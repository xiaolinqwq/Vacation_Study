/***************************
* @author :小麟
* @date :2022-11-26
***************************/
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
template <typename T>
class Linklist;
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

template <typename T> 
inline void 
Linklist<T>::insert(T value, int index)
{
    if(index <= _length){
        Lnode<T>* temp = _root;
        while(index--) temp = temp->_next;
        Lnode<T>* a = temp->_next;
        Lnode<T>* add = new Lnode<T>(value, a);
        temp->_next = add;
        _length = _length + 1;
    } 
}

template <typename T>
inline void 
Linklist<T>::Delete(int index)
{
    if(_length > 0 && index > 0){
        index = index - 1;
        Lnode<T>* temp = _root;
        while(index--) temp = temp->_next;
        Lnode<T>* a = temp->_next->_next;
        temp->_next = a;
        _length = _length - 1;
    }
}

template <typename T>
inline Lnode<T>*
Linklist<T>::Find_ByValue(T value)
{
    if(_length > 0){
        Lnode<T>* temp = _root;
        while(temp->_next != nullptr){
            temp = temp->_next;
            if(temp->_data == value) {
                return temp;
            }
        }
    }
    return nullptr;
}

template <typename T>
inline Lnode<T>* 
Linklist<T>::Find_ByIndex(int index)
{
    if(_length > 0 && index > 0 && index <= _length){
        Lnode<T>* temp = _root;
        while(index--) temp = temp->_next;
        return temp; 
    }
    return nullptr;
}

template <typename T>
inline int 
Linklist<T>::length()
{
    return _length;
}
template <typename T>
inline bool
Linklist<T>::isempty()
{
    if(_length > 0) return false;
    return true;
}
#endif