#ifndef Z_STORAGE_H
#define Z_STORAGE_H

class Storage {
public:
    vector<Variable *> variables;

    Storage() {
        insert(
            new Variable(
                    new String("in"), new Value(new Input())
            )
        );
        insert(
                new Variable(
                        new String("out"), new Value(new Output())
                )
        );
    }

    /**
     * Insert variable into stack.
     * @param variable
     */
    void insert(Variable * variable) {
        variables.push_back(variable);
    };

    /**
     * Get variable from stack.
     * @param name
     * @return
     */
    Variable * get(String * name) {
        for (Variable * variable : variables)
        {
            if (variable->getName()
                    ->equals(name)
                    ->isTrue()) {
                return variable;
            }
        }
        throw Variables::NotFound();
    };

    /**
     * Debug
     * @param name
     */
    void debug() {
        cout << "============ START DEBUG ============" << endl;
        for (Variable * variable : variables)
        {
            if (variable->getValue())
                cout << "Name: " << *variable->getName() << "     Value: ";
            switch (variable->getValue()->_type) {
                case _UNDEFINED:
                    cout << "UNDEFINED" << endl;
                    break;
                case _STRING:
                    cout << *variable->getValue()->getString() << endl;
                    break;
                case _BOOLEAN:
                    cout << *variable->getValue()->getBoolean() << endl;
                    break;
                case _NUMBER:
                    cout << *variable->getValue()->getNumber() << endl;
                    break;
                case _OBJECT:
                    cout << *variable->getValue()->getObject() << endl;
                    break;
            }
        }
        cout << "============  END DEBUG  ============" << endl;
    };

    /**
     * Determines if the given string exists as variable on the stack.
     * @param name
     * @return
     */
    Boolean * exists(String * name) {
        return new Boolean(ranges::any_of(variables, [name](Variable * variable) {
            return variable->getName()
                    ->equals(name)->isTrue();
        }));
    };
};

class StorageContainer
{
private:
    static Storage * instance;
    static mutex mutex_;

protected:
    StorageContainer() = default;
    ~StorageContainer() = default;
public:
    StorageContainer(StorageContainer &other) = delete;
    void operator=(const StorageContainer &) = delete;
    static auto *getInstance();
    static auto *createInstance();
};

/**
 * Storage instance.
 */
Storage * StorageContainer::instance {nullptr};

/**
 * Storage mutex.
 */
mutex StorageContainer::mutex_;

/**
 * Creates the Storage instance.
 * @return Storage
 */
auto * StorageContainer::createInstance() {
    return new Storage();
};

/**
 * Retrieves the Storage instance.
 * @return Storage
 */
auto * StorageContainer::getInstance(){
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr)
        instance = createInstance();
    return instance;
}

#endif
