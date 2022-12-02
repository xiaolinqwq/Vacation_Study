# 线性表（author: @小麟)
## 目录
* <a href="#1">基本概念</a>
* <a href="#2">顺序表</a>
* <a href="#3">链表</a>
## <a id="1">基本概念</a>
n个相同数据类型的有限序列
## <a id="2">顺序表</a>
### 动态数组
#### 类的声明
```cpp
class DYnamicArrays{
public:
    DYnamicArrays(size_t Size = 64):
        _length(0),
        _size(Size),
        _flag(true)
    {
        _data = new T[Size]; 
    }
    ~DYnamicArrays()
    {
        delete[] _data;
    }
    inline void Expansion();
    inline void insert(T value, size_t index);
    inline void Delete(size_t index);
    inline int Find_Byvalue(T value) const;
    inline T Find_Byindex(size_t index) const;
    inline size_t length() const;
    inline bool isempty() const;
    inline T operator[](size_t index);
private:
    T* _data;
    size_t _length;
    size_t _size;
    bool _flag;
};
```
_size为当前数组大小,T类型指针_data指向所开辟的空间大小,_length为有效数据个数,当_length >= _size,会重新开辟一个2*_size的内存空间用来扩容,_flag为当前是否达到最大容量.
(代码见 > code > part2 > DYnamicArrays.h)
#### 时间复杂度

FindByValue $ O(n) = n $
Insert $ O(n) = n $
Delete $ O(n) = n $
FindByIndex $ O(n) = 1 $  
## <a id="3">链表</a>
#### 类的声明

```cpp
template <typename T>
class Lnode{
private:
    T _data;
    Lnode<T>* _next;
public:
    Lnode(T data = 0, Lnode<T>* next = nullptr):
        _data(data),
        _next(next)
    {

    }
    ~Lnode()
    {
        delete _next;
    }
    inline T GetData() {return _data;}
friend class Linklist<T>;
};
```
Lnode为链表节点类,并声明了链表Linklist友元
```cpp
template <typename T>
class Linklist{
public:
    Linklist()
    {
        _root = new Lnode<T>(0,nullptr);
        _length = 0;
    }
    ~Linklist()
    {
        delete _root;
    }
    inline void insert(T value, int index);
    inline void Delete(int index);
    inline Lnode<T>* Find_ByValue(T value);
    inline Lnode<T>* Find_ByIndex(int index);
    inline int length();
    inline bool isempty();
private:
    Lnode<T>* _root;
    int _length;
};
```
代码见 > code > part2 > Linkedlist.h
#### 时间复杂度

insert $ O(n) = 1 $
Delete $ O(n) = 1 $
Find_ByValue,Find_ByIndex $ O(n) = n $
## <font color=pink>来张二次元</font>
<img src="./part2.jpg" />
<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width=100% height=86 src="https://music.163.com/outchain/player?type=2&id=1997650590&auto=0&height=66"></iframe>


