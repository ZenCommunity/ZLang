#ifndef Z_CORE_H
#define Z_CORE_H

#include <mutex>
#include <string>
#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

#define TRUE 1
#define FALSE 0
#define NPOS string::npos


typedef bool boolean;
typedef int integer;

namespace App::Exceptions {
    class NotFound : public std::exception {

    };
}

namespace App::Types {
    class Boolean {
    public:
        explicit Boolean(boolean value) : value_(value) {}
        friend std::ostream& operator<< (ostream& stream, const Boolean& boolean_);
        [[nodiscard]] boolean isTrue() const;
        [[nodiscard]] boolean isFalse() const;
    private:
        boolean value_;
    };
    class String {
    public:
        explicit String(string value) : value_(std::move(value)) {}
        friend std::ostream& operator<< (ostream& stream, const String& string_);
        size_t count();
        size_t at(String * string);
        String * copy();
        String * sub(size_t min, size_t max);
        String * before(String * search);
        String * beforeLast(String * search);
        String * after(String * search);
        String * afterLast(String * search);
        String * between(String * start, String * end);
        String * betweenFirst(String * start, String * end);
        Boolean * startsWith(String * search);
        Boolean * endsWith(String * search);
        Boolean * isEmpty();
        Boolean * isEquals(String * search);
        Boolean * contains(String * search);
        Boolean * matches(String * pattern);
        string asPrimitive();
        vector<String *> explode(String * separator);
    private:
        string value_;
    };
    class Number {
    public:
        explicit Number(float value) : value_(value) {}
        friend std::ostream& operator<< (ostream& stream, const Number& number_);
    private:
        float value_;
    };
    class Object {
    public:
        explicit Object() = default;
        friend std::ostream& operator<< (ostream& stream, const Object& object_);
    private:
        string value_;
    };
}

namespace App::Memory {
    enum Type {
        UNDEFINED = 0x00000000,
        STRING = 0x00000001,
        BOOLEAN = 0x00000002,
        NUMBER = 0x00000003,
        OBJECT = 0x00000004,
    };
    class Value {
    public:
        explicit Value() = default;
        explicit Value(App::Types::Boolean * value);
        explicit Value(App::Types::String * value);
        explicit Value(App::Types::Number * value);
        explicit Value(App::Types::Object * value);
        [[nodiscard]] App::Types::Boolean * getBoolean() const;
        [[nodiscard]] App::Types::String * getString() const;
        [[nodiscard]] App::Types::Number * getNumber() const;
        [[nodiscard]] App::Types::Object * getObject() const;
        Type getType();
    private:
        Type _type = UNDEFINED;
        union {
            App::Types::Boolean * _boolean;
            App::Types::String * _string;
            App::Types::Number * _number;
            App::Types::Object * _object;
        } _value{};
    };
    class Variable {
    public:
        explicit Variable(App::Types::String * name);
        explicit Variable(App::Types::String * name, Value * value);
        App::Types::String * getName();
        void setValue(Value * value);
        auto getValue();
    private:
        App::Types::String * _name;
        Value * _value;
    };
}

namespace App::Functions {
    class Function {
    public:
        App::Types::String * _name;
        function<void()> _lambda;
        Function(App::Types::String * name, function<void()> lambda);
        [[nodiscard]] App::Types::String * getName() const;
        [[nodiscard]] function<void()> getLambda() const;
    };
    class Functions {
    public:
        Function * get(App::Types::String * name);
        void insert(Function * function);
    private:
        vector<Function *> * _storage;
    };
}

namespace App::Storage {
    class Warehouse {
    public:
        explicit Warehouse() = default;
        void insert(App::Memory::Variable * variable);
        App::Memory::Variable * get(App::Types::String * name);
        void debug();
        Types::Boolean * exists(Types::String * name);
    private:
        vector<App::Memory::Variable *>  _variables;
    };
    class WarehouseContainer {
    private:
        static Warehouse * instance;
        static mutex mutex_;
    protected:
        WarehouseContainer() = default;
        ~WarehouseContainer() = default;
    public:
        WarehouseContainer(WarehouseContainer &other) = delete;
        void operator=(const WarehouseContainer &) = delete;
        static auto *getInstance();
        static auto *createInstance();
    };
}

namespace Engine {
    typedef enum _InstructionType {
        ASSIGNMENT = 0x00000001,
        DEFINITION = 0x00000002,
        LOOP = 0x00000003,
        CONDITIONAL = 0x00000004,
        UNDEFINED = 0x00000005,
        INVOCATION = 0x00000006,
    } InstructionType;
    class Instruction {
    public:
        explicit Instruction(InstructionType type, App::Types::String * line) : _type(type), _line(line) {}
        App::Types::String * getLine();
        InstructionType getType();
    private:
        InstructionType _type = UNDEFINED;
        App::Types::String * _line;
    };
    class Instructions {
    public:
        vector<Instruction *> getItems();
    private:
        vector<Instruction *> _instructions;
    };
    class Parser {
    public:
        void run(App::Types::String * document);
        static void executeAssigment(Instruction * instruction);
        static Instructions * getInstructions(App::Types::String * document);
    private:
        static InstructionType getType(App::Types::String * current);
    };
}

namespace App::IO {
    namespace Input {
        class Instance {
            Types::String * buffer;
        };
    };
    namespace Output {
        class Instance {
        };
    };
}

#endif //Z_CORE_H
