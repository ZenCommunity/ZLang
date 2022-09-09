#ifndef Z_ENGINE_H
#define Z_ENGINE_H

class Engine {
public:
    Parser * _parser;

    /**
     * Engine Constructor
     */
    Engine() {
        _parser = new Parser;
    }

    void start(string & document) {
        auto * code = _parser->getCode(document);
    }
};

class EngineContainer
{
private:
    static Engine * instance;
    static mutex mutex_;

protected:
    EngineContainer() = default;
    ~EngineContainer() = default;
public:
    EngineContainer(EngineContainer &other) = delete;
    void operator=(const EngineContainer &) = delete;
    static auto *GetInstance();
    static auto *CreateInstance();
};

/**
 * Engine instance.
 */
Engine * EngineContainer::instance {nullptr};

/**
 * Engine mutex.
 */
mutex EngineContainer::mutex_;

/**
 * Creates the Engine instance.
 * @return Engine
 */
auto * EngineContainer::CreateInstance() {
    return new Engine();
};

/**
 * Retrieves the Engine instance.
 * @return Engine
 */
auto * EngineContainer::GetInstance(){
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr)
        instance = CreateInstance();
    return instance;
}

#endif
