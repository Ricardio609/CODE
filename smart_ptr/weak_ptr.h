/* 解决循环引用的问题 */

template<class T>
class weak_ptr {
public:
    weak_ptr()
        :_ptr(nullptr)
    {}

    weak_ptr(const weak_ptr<T>& wp)
        :_ptr(wp._ptr)
        ,_pCount(wp._pCount)
    {}

    weak_ptr(const shared_ptr<T>& sp)
        :_ptr(sp._ptr)
        ,_pCount(sp._pCount)
    {}

    weak_ptr<T>& operator=(const weak_ptr<T>& wp) {
        _ptr = wp._ptr;
        _pCount = wp._pCount;
    }

    weak_ptr<T>& operator=(const shared_ptr<T>& sp) {
        _ptr = sp._ptr;
        _pCount = sp._pCount;
    }

private:
    T*      _ptr;
    int*    _pCount;
};