#include <mutex>
#include <iostream>

/* 多个智能指针管理一个内存资源，最后一个智能指针释放内存
 * 线程安全：1. 引用计数；2. 管理的对象在堆上
 */

template<class T>
class shared_ptr {
public:
    explicit shared_ptr(T* ptr)
        :_ptr(ptr),
        _pCount(new int(1)),
        _mtx(new mutex)
    {}

    void add_pCount() {
        //加锁或者使用加1的原子操作
        _mtx->lock();
        ++(*_pCount);
        _mtx->unlock();
    }

    void release_pCount() {
        //引用计数减一，如果减到零，则释放资源
        bool flag = false;
        _mtx->lock();
        --(*_pCount);
        if ((*_pCount) == 0 && _ptr) {
            std::cout << "~shared_ptr: " << _ptr <<endl;
            D del;
            delete _ptr;
            delete _pCount;
            flag = true;
        }
        _mtx->unlock();
        if (flag) {
            delete _mtx;
        }
    }

    shared_ptr(shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            ,_pCount(sp._pCount)
            ,_mtx(sp._mtx)
    {
        add_pCount();
    }

    void swap(shared_ptr<T>& sp) {
        std::swap(_ptr, sp._ptr);
        std::swap(_pCount, sp._pCount);
        std::swap(_mtx, sp._mtx);
    }

    shared_ptr<T>& operator=(shared_ptr<T> sp) {
        swap(sp);
        return *this;
    }

    ~shared_ptr() {
        release_pCount();
    }

    T& operator*() {
        return *_ptr;
    }
    
    T* operator->() {
        return &_ptr;
    }

    T* get() {
        return _ptr;
    }

    size_t use_count() {
        return *_pCount;
    }
private:
    T*      _ptr;       //管理的内存资源
    int*    _pCount;    //计数
    mutex*  _mtx;       //多线程互斥
    //堆上开辟--多个只能指针共享计数和互斥锁
};
