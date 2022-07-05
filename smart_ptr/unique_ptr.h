/* 不存在拷贝和赋值，没有管理权的转移 */
//C++98防拷贝的方式：只声明不实现+声明成私有；C++11防拷贝的方式修饰函数为delete

template<class T>
class unique_ptr {
public:
    unique_ptr(T* ptr)
        :_ptr(ptr)
    {}

    unique_ptr(unique_ptr<T>& ap) = delete;
    unique_ptr<T>&  operator=(unique_ptr<T>& ap) = delete;

    ~unique_ptr() {
        if (_ptr) {
            std::cout << "~unique_ptr: " << _ptr << endl;
            delete _ptr;
        }
    }

    T& operator*() {
        return *_ptr;
    }

    T& operator*->() {
        return &_ptr;
    }

private:
    T* _ptr;
};