#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
using namespace std;

class Singleton{
private:
    static Singleton* _instance;
    Singleton(){
        cout<<"Singleton..."<<endl;
    }
    Singleton(const Singleton& other);
public:
    static Singleton* Instance();

};

Singleton* Singleton::_instance=0;

//线程非安全版本
Singleton* Singleton::Instance(){
    if(_instance==0){
        _instance=new Singleton();
    }
    return _instance;
}

/*线程安全版本，但锁的代价过高
Singleton* Singleton::Instance(){
    Lock lock;
    if(_instance==0){
        _instance=new Singleton();
    }
    return _instance;
}
*/

/*双检查锁，但由于内存读写reorder不安全,造成双检查锁失效
锁前不检查：代价过高
锁后不检查：锁不住
Singleton* Singleton::Instance(){
    if(_instance==0){
        Lock lock;
        if(_instance==0){
            _instance=new Singleton();
        }
    }
    return _instance;
}
*/

/*C++ 11 版本之后的跨平台实现（volatile)
std::atomic<Singleton*> Singleton::_instance;
std::mutex Singleton::_mutex;
Singleton* Singleton::Instance(){
    Singleton* tmp = _instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
    if(tmp==nullptr){
        std::lock_guard<std::mutex> lock(_mutex);
        tmp=_instance.load(std::memory_order_relaxed);
        if(tmp==nullptr){
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            _instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
*/
#endif