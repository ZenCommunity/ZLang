#ifndef Z_APP_H
#define Z_APP_H

class App {
public:
    App() {}
};

class AppContainer
{
private:
    static App * instance;
    static mutex mutex_;

protected:
    AppContainer() = default;
    ~AppContainer() = default;
    string value_;
public:
    AppContainer(AppContainer &other) = delete;
    void operator=(const AppContainer &) = delete;
    static auto *GetInstance();
    static auto *CreateInstance();
};

/**
 * App instance.
 */
App * AppContainer::instance {nullptr};

/**
 * App mutex.
 */
mutex AppContainer::mutex_;

/**
 * Creates the App instance.
 * @return App
 */
auto * AppContainer::CreateInstance() {
    return new App();
};

/**
 * Retrieves the App instance.
 * @return App
 */
auto * AppContainer::GetInstance(){
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = CreateInstance();
    }
    return instance;
}

#endif
