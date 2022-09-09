#ifndef Z_PARSER_H
#define Z_PARSER_H

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
    InstructionType type_ = UNDEFINED;
    String * line_;
    explicit Instruction(InstructionType type, String * line) : type_(type), line_(line) {}
};

class Code {
public:
    vector<Instruction *> instructions;
};

class Parser {
public:
    Code * getCode(string & document) {
        auto code = new Code;

        ifstream input;
        string line;
        input.open(document);
        while (getline(input, line)) {
            istringstream input_stream(line);


            int a, b;
            if (!(input_stream >> a >> b)) {
                cout << line << endl;
                auto * current = new String(line);
                InstructionType instructionType = getType(current);
                switch (instructionType) {
                    case InstructionType::UNDEFINED:
                        cout << "Line can't be parsed" << endl;
                        break;
                    case InstructionType::DEFINITION:
                        cout << "IS A DEFINITION." << endl;
                        break;
                    case InstructionType::ASSIGNMENT:
                        cout << "IS A ASSIGNMENT." << endl;
                        break;
                    case InstructionType::LOOP:
                        cout << "IS A LOOP." << endl;
                        break;
                    case InstructionType::CONDITIONAL:
                        cout << "IS A CONDITIONAL." << endl;
                        break;
                    case InstructionType::INVOCATION:
                        cout << "IS A INVOCATION." << endl;
                        break;
                }
                code->instructions.push_back(new Instruction(instructionType, current));
            }
        }

        return code;
    }
protected:
    static InstructionType getType(String * current) {
        if (current->startsWith(new String("if "))->isTrue()
            || current->startsWith(new String("else if "))->isTrue()
               || current->startsWith(new String("else "))->isTrue()) {
            return InstructionType::CONDITIONAL;
        }

        if (current->startsWith(new String("for "))->isTrue()
            || current->startsWith(new String("while "))->isTrue()) {
            return InstructionType::LOOP;
        }

        if (current->startsWith(new String("def "))->isTrue()) {
            if (current->contains(new String(" = "))->isTrue()) {
                return InstructionType::ASSIGNMENT;
            }
            return InstructionType::DEFINITION;
        }

//
//        if (current->contains(new String("."))->isTrue()) {
//            return InstructionType::INVOCATION;
//        }

        return InstructionType::UNDEFINED;
    }
};

#endif
