# 线性表（author: @小麟)
## 目录
* <a href="#1">队列</a>
* <a href="#2">栈</a>
## <a id="1">队列</a>
#### 类的声明
```cpp
const int m_max = 101;
template <typename T>
class Mqueue{
public:
    Mqueue(int Size = 100):
        l(0),
        r(0),
        _Size(Size+1),
        _length(0)
    {
        _data = new T[(Size+1) <= m_max?(Size+1):m_max];
    }
    ~Mqueue()
    {
        delete[] _data;
    }
    inline void push_back(T value);
    inline void pop();
    inline T top();
    inline bool isempty();


private:
    int l, r;
    T *_data;
    int _Size;
    int _length;
};
```
代码见part4 > mqueue.h
## <a id="2">栈</a>
#### 类的声明
```cpp
const int m_stack_max = 101;
template <typename T>
class mStack{

public:
    mStack(int Size = 100):
        _top(0),
        _Size(Size + 1),
        _length(0)
    {
        _data = new T[(Size+1) <= m_stack_max?(Size+1):m_stack_max];
    }
    ~mStack()
    {
        delete[] _data;
    }
    inline void push(T value);
    inline void pop();
    inline T top();
    inline bool isempty();

private:
    T *_data;
    int _top;
    int _Size;
    int _length;
};
```
代码见 >code > part4 > mStack.h 
## <font color=pink>来张二次元</font>
<img src="./part4.jpg" />
<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width=100% height=86 src="https://music.163.com/outchain/player?type=2&id=1997650590&auto=0&height=66"></iframe>


