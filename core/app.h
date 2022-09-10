#ifndef Z_APP_H
#define Z_APP_H

class Engine {
public:
    Storage * _storage;

    /**
     * Engine Constructor
     */
    Engine() {
        _parser = new Parser;
        _storage = StorageContainer::getInstance();
    }

    Storage * getStorage() {
        return _storage;
    }

    void debugStorage() {
        _storage->debug();
    }

    void executeAssigment(Instruction * instruction) {
        auto name = instruction->getLine()->between(new String("def "),new String(" = "));
        auto nested = instruction->getLine()->after(new String(" = "));
        if (name->isEmpty()->isTrue()) {
            cout << "Something went wrong..." << endl;
            cout << "Key can't be empty" << endl;
        } else {
            Boolean * exists = _storage->exists(name);
            if (nested->startsWith(new String("\""))->isTrue() &&
                nested->endsWith(new String("\""))->isTrue()) {
                if (exists->isFalse()) {
                    _storage->insert(
                        new Variable(
                            name,
                        new Value(
                                nested->betweenFirst(new String("\""), new String("\""))
                            )
                        )
                    );
                }
            } else {
                if (exists->isFalse()) {
                    _storage->insert(new Variable(name, new Value(nested)));
                }
            }
            cout << "The name is" << endl;
            cout << name << endl;
            cout << "Must be resolved using" << endl;
            cout << nested << endl;
        }
    }

    void start(string & document) {
        auto * code = _parser->getCode(document);
        for (auto instruction : code->instructions) {
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
protected:
    Parser * _parser;
};

class AppContainer
{
private:
    static Engine * instance;
    static mutex mutex_;

protected:
    AppContainer() = default;
    ~AppContainer() = default;
public:
    AppContainer(AppContainer &other) = delete;
    void operator=(const AppContainer &) = delete;
    static auto *GetInstance();
    static auto *CreateInstance();
};

/**
 * Engine instance.
 */
Engine * AppContainer::instance {nullptr};

/**
 * Engine mutex.
 */
mutex AppContainer::mutex_;

/**
 * Creates the Engine instance.
 * @return Engine
 */
auto * AppContainer::CreateInstance() {
    return new Engine();
};

/**
 * Retrieves the Engine instance.
 * @return Engine
 */
auto * AppContainer::GetInstance(){
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr)
        instance = CreateInstance();
    return instance;
}

#endif
