#include "core.h"

/**
 * BOOLEANS
 */

boolean App::Types::Boolean::isTrue() const {
    return value_ == TRUE;
}

boolean App::Types::Boolean::isFalse() const {
    return value_ == FALSE;
}

std::ostream &App::Types::operator<<(ostream &stream, const App::Types::Boolean &boolean_) {
    cout << boolean_.value_;
    return stream;
}

/**
 * STRINGS
 */

/**
 * Returns the length.
 * @return size_t
 */
size_t App::Types::String::count() {
    return value_.length();
}

/**
 * Returns the position of the given value.
 * @param search
 * @return size_at
 */
size_t App::Types::String::at(App::Types::String * search) {
    return value_.find(search->value_);
}

/**
 * Returns a substring given the min and max.
 * @param min
 * @param max
 * @return string
 */
App::Types::String *App::Types::String::sub(size_t min, size_t max) {
    auto copy = string(value_);
    return new App::Types::String(copy.substr(min, max));
}

/**
 * Determines if the given string is at the start.
 * @param search
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::startsWith(App::Types::String *search) {
    return new Boolean(at(search) == 0);
}

/**
 * Determines if the given string is at the end.
 * @param search
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::endsWith(App::Types::String *search) {
    return new Boolean(at(search) == (count() - search->count()));
}

/**
 * Determines if the given string is equals to the current.
 * @param search
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::isEmpty() {
    return new Boolean(count() == 0);
}

/**
 * Determines if the given string is equals to the current.
 * @param search
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::isEquals(App::Types::String *search) {
    return new Boolean(value_ == search->value_);
}

/**
 * Determines if the given string contains the given value.
 * @param search
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::contains(App::Types::String *search) {
    return new Boolean(at(search) != NPOS);
}

/**
 * Returns everything after the given value.
 * @param search
 * @return string
 */
App::Types::String *App::Types::String::after(App::Types::String *search) {
    size_t position = at(search);
    if (position == NPOS)
        throw App::Exceptions::NotFound();
    return sub(position + search->count(), count() - search->count());
}

/**
 * Determines if the given string matches to the given pattern.
 * @param pattern
 * @return Boolean
 */
App::Types::Boolean *App::Types::String::matches(App::Types::String *pattern) {
    return new Boolean(regex_match(value_, regex(pattern->value_)) == TRUE);
}

/**
 * Returns a copy.
 * @return String
 */
App::Types::String *App::Types::String::copy() {
    return new App::Types::String(string(value_));
}

/**
 * Returns everything after the last occurrence.
 * @param search
 * @return string
 */
App::Types::String *App::Types::String::afterLast(App::Types::String *search) {
    String * copy = this->copy();
    size_t position = copy->at(search);
    if (position == NPOS)
        throw App::Exceptions::NotFound();

    while (position != NPOS) {
        copy = copy->sub(position + search->count(), count() - search->count());
        position = copy->at(search);
    }
    return copy;
}

/**
 * Returns everything before the given value.
 * @param search
 * @return String
 */
App::Types::String *App::Types::String::before(App::Types::String *search) {
    size_t position = at(search);

    if (position == NPOS)
        throw App::Exceptions::NotFound();

    return sub(0, position);
}

/**
 * Returns everything before the last occurrence.
 * @param search
 * @return String
 */
App::Types::String *App::Types::String::beforeLast(App::Types::String *search) {
    String * copy = this->copy();
    size_t position = at(search);
    size_t result;

    if (position == NPOS)
        throw App::Exceptions::NotFound();

    while (position != NPOS) {
        result = position;
        copy = copy->sub(position + search->count(), count() - search->count());
        position = copy->at(search);
    }

    return sub(0, result);
}

/**
 * Returns the portion of a string between two values.
 * @param start
 * @param end
 * @return String
 */
App::Types::String *App::Types::String::between(App::Types::String *start, App::Types::String *end) {
    String * copy = this->copy();
    copy = copy->afterLast(start);
    return copy->beforeLast(end);
}

/**
 * Returns the smallest possible portion of a string between two values.
 * @param start
 * @param end
 * @return String
 */
App::Types::String *App::Types::String::betweenFirst(App::Types::String *start, App::Types::String *end) {
    String * copy = this->copy();
    copy = copy->after(start);
    return copy->before(end);
}

/**
 * Returns a list with values of a delimited string.
 * @param start
 * @param end
 * @return String
 */
vector<App::Types::String *> App::Types::String::explode(App::Types::String *separator) {
    vector<String *> vector;
    String * copy = this->copy();
    while(copy->count() > 0) {
        if (copy->contains(separator)->isTrue()) {
            String * instance = copy->before(separator);
            vector.push_back(instance);
            copy = copy->after(separator);
        } else {
            vector.push_back(copy);
            copy = new App::Types::String("");
        }
    }
    return vector;
}

/**
 * String Echo.
 * @param stream
 * @param string_
 * @return ostream
 */
std::ostream &App::Types::operator<<(ostream &stream, const App::Types::String &string_) {
    cout << string_.value_;
    return stream;
}

string App::Types::String::asPrimitive() {
    return value_;
}

/**
 * NUMBERS
 */

/**
 * Number Echo.
 * @param stream
 * @param number_
 * @return stream
 */
std::ostream &App::Types::operator<<(ostream &stream, const App::Types::Number &number_) {
    cout << number_.value_;
    return stream;
}

/**
 * FUNCTIONS
 */

/**
 * @param name
 * @param lambda
 */
App::Functions::Function::Function(App::Types::String *name, function<void()> lambda) {
    _name = name;
    _lambda = std::move(lambda);
}

App::Types::String *App::Functions::Function::getName() const {
    return _name;
}

function<void()> App::Functions::Function::getLambda() const {
    return _lambda;
}

App::Functions::Function * App::Functions::Functions::get(App::Types::String *name) {
    for (Function * function : *_storage) {
        if (function->getName()->isEquals(name)->isTrue()) {
            return function;
        }
    }
    throw App::Exceptions::NotFound();
}

void App::Functions::Functions::insert(App::Functions::Function *function) {
    _storage->push_back(function);
}

App::Memory::Value::Value(App::Types::Boolean *value) {
    _value._boolean = value;
    _type = Type::BOOLEAN;
}

App::Memory::Value::Value(App::Types::String *value) {
    _value._string = value;
    _type = Type::STRING;
}

App::Memory::Value::Value(App::Types::Number *value) {
    _value._number = value;
    _type = Type::NUMBER;
}

App::Memory::Value::Value(App::Types::Object *value) {
    _value._object = value;
    _type = Type::OBJECT;
}

App::Types::Boolean *App::Memory::Value::getBoolean() const {
    return _value._boolean;
}

App::Types::String *App::Memory::Value::getString() const {
    return _value._string;
}

App::Types::Number *App::Memory::Value::getNumber() const {
    return _value._number;
}

App::Types::Object *App::Memory::Value::getObject() const {
    return _value._object;
}

std::ostream &App::Types::operator<<(ostream &stream, const App::Types::Object &object_) {
    cout << object_.value_ << endl;
    return stream;
}

/**
 * MEMORY
 */

App::Memory::Type App::Memory::Value::getType() {
    return _type;
}

App::Memory::Variable::Variable(App::Types::String *name)  {
    _name = name;
    _value = {};
}

App::Memory::Variable::Variable(App::Types::String *name, App::Memory::Value *value) {
    _name = name;
    _value = value;
}

void App::Memory::Variable::setValue(App::Memory::Value *value) {
    _value = value;
}

auto App::Memory::Variable::getValue() {
    return _value;
}

App::Types::String *App::Memory::Variable::getName() {
    return _name;
}

/**
 * ENGINE
 */

/**
 * @return
 */
App::Types::String *Engine::Instruction::getLine() {
    return _line;
}

Engine::InstructionType Engine::Instruction::getType() {
    return _type;
}

vector<Engine::Instruction *> Engine::Instructions::getItems() {
    return _instructions;
}

Engine::Instructions * Engine::Parser::getInstructions(App::Types::String *document)  {
    auto instructions = new Instructions;
    ifstream input;
    string line;
    input.open(document->asPrimitive());
    while (getline(input, line)) {
        istringstream input_stream(line);
        int a, b;
        if (!(input_stream >> a >> b)) {
            cout << line << endl;
            auto * current = new App::Types::String(line);
            InstructionType instructionType = getType(current);

            instructions->getItems()
                    .push_back(new Instruction(instructionType, current));
        }
    }
    return instructions;
}

Engine::InstructionType Engine::Parser::getType(App::Types::String * current) {
    if (current->startsWith(new App::Types::String("if "))->isTrue()
        || current->startsWith(new App::Types::String("else if "))->isTrue()
        || current->startsWith(new App::Types::String("else "))->isTrue()) {
        return InstructionType::CONDITIONAL;
    }

    if (current->startsWith(new App::Types::String("for "))->isTrue()
        || current->startsWith(new App::Types::String("while "))->isTrue()) {
        return InstructionType::LOOP;
    }

    if (current->startsWith(new App::Types::String("def "))->isTrue()) {
        if (current->contains(new App::Types::String(" = "))->isTrue()) {
            return InstructionType::ASSIGNMENT;
        }
        return InstructionType::DEFINITION;
    }
    return InstructionType::UNDEFINED;
}

void Engine::Parser::run(App::Types::String * document) {
    auto * code = getInstructions(document);
    for (auto instruction : code->getItems()) {
        switch(instruction->getType()) {
            case ASSIGNMENT:
                executeAssigment(instruction);
                break;
            case DEFINITION:
                break;
            case LOOP:
                break;
            case CONDITIONAL:
                break;
            case UNDEFINED:
                break;
            case INVOCATION:
                break;
        }
    }
}

/**
 * STORAGE
 */


void App::Storage::Warehouse::insert(App::Memory::Variable *variable) {
    _variables.push_back(variable);
}

App::Memory::Variable *App::Storage::Warehouse::get(App::Types::String *name) {
    for (App::Memory::Variable * variable : _variables) {
        if (variable->getName()->isEquals(name)->isTrue()) {
            return variable;
        }
    }
    throw App::Exceptions::NotFound();
}

void App::Storage::Warehouse::debug() {
    cout << "============ START DEBUG ============" << endl;
    for (App::Memory::Variable * variable : _variables)
    {
        if (variable->getValue())
            cout << "Name: " << *variable->getName() << "     Value: ";
        switch (variable->getValue()->getType()) {
            case Memory::UNDEFINED:
                cout << "UNDEFINED" << endl;
                break;
            case Memory::STRING:
                cout << *variable->getValue()->getString() << endl;
                break;
            case Memory::BOOLEAN:
                cout << *variable->getValue()->getBoolean() << endl;
                break;
            case Memory::NUMBER:
                cout << *variable->getValue()->getNumber() << endl;
                break;
            case Memory::OBJECT:
                cout << *variable->getValue()->getObject() << endl;
                break;
        }
    }
    cout << "============  END DEBUG  ============" << endl;
}

App::Types::Boolean *App::Storage::Warehouse::exists(App::Types::String * name) {
    return new App::Types::Boolean(ranges::any_of(_variables, [name](App::Memory::Variable * variable) {
        return variable->getName()->isEquals(name)->isTrue();
    }));
}

/**
 * Storage instance.
 */
App::Storage::Warehouse * App::Storage::WarehouseContainer::instance {nullptr};

/**
 * Storage mutex.
 */
mutex App::Storage::WarehouseContainer::mutex_;

auto *App::Storage::WarehouseContainer::createInstance() {
    return new Warehouse();
}

auto *App::Storage::WarehouseContainer::getInstance() {
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr)
        instance = createInstance();
    return instance;
}

void Engine::Parser::executeAssigment(Engine::Instruction * instruction) {
    auto name = instruction->getLine()->between(new App::Types::String("def "),new App::Types::String(" = "));
    auto nested = instruction->getLine()->after(new App::Types::String(" = "));
    auto warehouse = App::Storage::WarehouseContainer::getInstance();
    if (name->isEmpty()->isTrue()) {
        cout << "Something went wrong..." << endl;
        cout << "Key can't be empty" << endl;
    } else {
        App::Types::Boolean * exists = warehouse->exists(name);
        if (nested->startsWith(new App::Types::String("\""))->isTrue() &&
            nested->endsWith(new App::Types::String("\""))->isTrue()) {
            if (exists->isFalse()) {
                warehouse->insert(
                        new App::Memory::Variable(
                                name,
                                new App::Memory::Value(
                                        nested->betweenFirst(new App::Types::String("\""), new App::Types::String("\""))
                                )
                        )
                );
            }
        } else {
            if (exists->isFalse()) {
                warehouse->insert(new App::Memory::Variable(name, new App::Memory::Value(nested)));
            }
        }
        cout << "The name is" << endl;
        cout << name << endl;
        cout << "Must be resolved using" << endl;
        cout << nested << endl;
    }
}
