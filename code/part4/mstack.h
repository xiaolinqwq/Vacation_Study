#ifndef __MSTACK_H__
#define __MSTACK_H__
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

template <typename T>
inline void 
mStack<T>::push(T value)
{
    if(_length < _Size){
        _data[_top] = value;
        _length = _length + 1;
        _top = _top + 1;
    }
    return ;
}

template <typename T>
inline void 
mStack<T>::pop()
{
    if(_length != 0){
        _length = _length - 1;
        _top = _top - 1;
    }
}
template <typename T>
inline T
mStack<T>::top()
{
    T temp = 0;
    if(_length != 0) {
        temp = _data[_top-1];
    }
    return temp;
}
template <typename T>
inline bool 
mStack<T>::isempty()
{
    if(_length == 0) return  true;
    return false;
}
#endif