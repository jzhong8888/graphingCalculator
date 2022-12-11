#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <cstring>

#include <iostream>

#include "../array_functions/array_functions.h"

using namespace std;

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity);

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity);

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity);



template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity){
    if(size == capacity){
        capacity = capacity * 2;
        list = reallocate(list, size, capacity);
        _append(list, size, new_entry);
        return list;
    }
    else {
        _append(list, size, new_entry);
        return list;
    }
}

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity){
    T* p = search_entry(list, size, delete_me);
    shift_left(list, size, p);
    if (size <= capacity/4.0 && capacity >= 6){
        capacity = capacity/2;
        T* q = reallocate(list, size, capacity);
        return q;
    }
    else{
        return list;
    }
}

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity){
    T* p = list + size - 1;
    popped = *p;
    shift_left(list, size, p);
    if (size <= capacity/4.0 && capacity >= 6){
        capacity = capacity/2;
        T* q = reallocate(list, size, capacity);
        return q;
    }
    else{
        return list;
    }
}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity){

    if(size == capacity){
        capacity = capacity * 2;
        list = reallocate(list, size, capacity);
    }
        shift_right(list, size, insert_here);
        T* p = list +insert_here;
        *p = insert_this;
        return list;
    }


template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity){
    shift_left(list, size, index);
    if (size <= capacity/4.0 && capacity >= 6){
        capacity = capacity/2;
        list = reallocate(list, size, capacity);
    }
    return list;
    }



#endif