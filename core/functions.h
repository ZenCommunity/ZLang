#ifndef Z_FUNCTIONS_H
#define Z_FUNCTIONS_H

class Parameter {
public:
    string name;
    Variable value;
};

typedef vector<Parameter> Parameters;

template<typename T>

class Function {
public:
    explicit Function() = default;
private:
    string name;
//    Context context;
    std::function<T(Parameters)> lambda;
};

#endif //Z_FUNCTIONS_H
