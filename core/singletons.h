#ifndef Z_SINGLETONS_H
#define Z_SINGLETONS_H

class Singleton
{
private:
    static Singleton * instance;
    static mutex mutex_;

protected:
    Singleton() = default;
    ~Singleton() = default;
    string value_;
public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance();
};

Singleton* Singleton::instance{nullptr};
mutex Singleton::mutex_;

Singleton *Singleton::GetInstance()
{
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

#endif
