/***************************
* @author :小麟
* @date :2022-12-2
***************************/
#ifndef __MQUEUE_H__
#define __MQUEUE_H__
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

template <typename T>
inline void 
Mqueue<T>::push_back(T value)
{
    if(_length < _Size-1){
        _data[r] = value;
        r = r + 1;
        if(r >= _Size) r = 0;
        _length = _length + 1;
    }
}

template <typename T>
inline void 
Mqueue<T>::pop()
{
    if(_length != 0){
        l = l + 1;
        if(l >= _Size) l = 0;
        _length = _length - 1;
    }
}

template <typename T>
inline T 
Mqueue<T>::top()
{
    T temp;
    if(_length != 0){
        temp = _data[l];
        return temp;
    }
    return temp;
    
}

template <typename T>
inline bool
Mqueue<T>::isempty()
{
    if(_length == 0) return true;
    return true;
}

#endif