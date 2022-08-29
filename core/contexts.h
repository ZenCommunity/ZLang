#ifndef Z_CONTEXTS_H
#define Z_CONTEXTS_H

enum Scope {
    _undefined,
    _global,
    _public,
    _private,
    _protected,
};

class Context {
public:
    Scope getScope() {
        return this->scope;
    };
    Storage getStorage() {
        return this->storage;
    };
protected:
    Storage storage;
    Scope scope = _undefined;
};

#endif
