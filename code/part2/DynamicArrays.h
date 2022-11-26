/***************************
* @author :小麟
* @date :2022-11-25
***************************/
#ifndef __DYnamicArrays_H__
#define __DYnamicArrays_H__
const size_t _max = 10086;
template<typename T>
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

template<typename T>
inline void 
DYnamicArrays<T>::Expansion()
{
    if(_flag && _length >= _size) {
        if(_size*2 > _max) _flag = false;
        else {
            _size = _size*2;
            T* temp = new T[_size];
        }
    }
}

template<typename T>
inline void
DYnamicArrays<T>::insert(T value, size_t index)
{
    if(_flag){
        for(int i=_length;i>index+1;i--){
            _data[i] = _data[i-1];
        } 
        _data[index+1] = value;
        _length = _length + 1;
        Expansion();
    }
}

template<typename T>
inline void 
DYnamicArrays<T>::Delete(size_t index)
{
    if(_length != 0){
        for(int i=index;i<_length-1;i++){
            _data[i] = _data[i+1];
        }
        _length = _length - 1;
    }
}

template<typename T>
inline int
DYnamicArrays<T>::Find_Byvalue(T value) const
{
    for(int i=0;i<_length;i++){
        if(_data[i] == value){
            return i;
        }
    }
    return -1;
}

template<typename T>
inline T
DYnamicArrays<T>::Find_Byindex(size_t index) const
{
    if(index > _length) return 0;
    return _data[index];
}

template<typename T>
inline size_t
DYnamicArrays<T>::length() const
{
    return _length;
}

template<typename T>
inline bool
DYnamicArrays<T>::isempty() const
{
    if(_length != 0) return false;
    return true;
}
template <typename T>
inline T 
DYnamicArrays<T>::operator[](size_t index)
{
    return _data[index];
}

#endif