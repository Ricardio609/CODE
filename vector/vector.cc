
template <typename T>
class vector {
public:
    vector();
    vector(size_t n);
    vector(size_t n, const T& x);
    vector(const vector& x);
    vector(vector&& x);
    vector(std::initializer_list<T> il):

    ~vector();

    vector& operator=(const vector& x);
    vector& operator=(const vector&& x);
    vector& operator=(std::initializer_list<T> il);

    void push_back(const T& x);     //拷贝
    void push_back(T&& x);          //移动
    template <typename ... Args>    //此处Args是左值还是右值？暂时还不确定，因此下面使用右值引用
    void emplace_back(Args&& ... args);
    void pop_back();

    size_t size();
    size_t capacity();
    bool empty();

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;


private:
    T* alloc(size_t n);
    void dealloc(T* p);
    template <typename ... Args>
    void construct(T* p, Args&& ... args);
    void destory(T* p);

    size_t cap_;
    size_t len_;
    T* ptr_;
};

#include <vector>

int main() {
    std::vector<int> nums{1, 2, 3};     //初始化列表赋值
    nums = {4, 5};
    nums[0];

    const std::vector<int> nums2;
    nums2[i];
}   