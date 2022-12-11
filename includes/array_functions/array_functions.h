#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <cstring>

#include <iostream>

using namespace std;

const int MINIMUM_CAPACITY = 3;

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY);  

template<class T>
T* reallocate(T* a, int size, int capacity);

template <class T>
void delete_repeats(T* a, int& size);

template <class T>
void shift_left(T* a, int& size, T* shift_here);

template <class T>
void shift_left(T* a, int& size, int shift_here); 

template<class T>
void print_array(T* a, int size, int capacity = 0, ostream& outs = cout); 

template <class T>
void print(T* a, unsigned int how_many, ostream& outs = cout); 

template<class T>
T* search_entry(T* a, int size, const T& find_me);

template<class T>
void array_init(T* a, int size, T x);


template<class T>
void _append(T *a, int& size, T append_me);

template <class T>
void shift_right(T *a, int &size, T* shift_here); 

template <class T>
void shift_right(T *a, int &size, int shift_here);  

template <class T>
int search(T* a, int size, const T& find_me); 

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy); 

template <class T>
T* copy_array(const T *src, int size); 

template <class T>
string array_string(const T *a, int size);  



template <class T>
void delete_repeats(T* a, int& size){
    T* walker = a;
    T* find;
    while(walker - a < size){
        find = search_entry(a, size, *walker);
        if(walker == find){
            walker++;
        }
        else{
            shift_left(a, size, find);
        }
    }
    }
    


template<class T>
void print_array(T* a, int size, int capacity, ostream& outs)
{
    outs << "( " << size << "/ " << capacity << ") ";
    outs << "[";
    for (int i = 0; i < size; i++)
    {
        outs << *a << "|"; 
        a++;
    }
    outs << "]";
    outs << endl;
}

template <class T>
void print(T* a, unsigned int how_many, ostream& outs){
    outs << "( " << how_many << " ) ";
    outs << "[";
    for (int i = 0; i < how_many; i++)
    {
        outs << *a << "|"; 
        a++;
    }
    outs << "]";
    outs << endl;
}

template <class T>
void shift_left(T* a, int& size, T* shift_here){
    T *walker_here = shift_here;
    for(int i = shift_here - a; i < size - 1; i++){
    *walker_here = *(walker_here + 1);
    walker_here++;
    }
    size--;
}

template <class T>
void shift_left(T* a, int& size, int shift_here){
    T *shift_ptr = a + shift_here;
    shift_left(a, size, shift_ptr);
}

template<class T>
T* search_entry(T* a, int size, const T& find_me){
     for (int i=0; i < size; i++)
   {
    if(*a == find_me)
    {
        return a;
    }
    a++;
   }
    return nullptr;
}

template<class T>
void array_init(T* a, int size, T x)
{
for (int i = 0; i < size; i++)
{
    *a = x;
    a++;
}
}


template<class T>
void _append(T *a, int& size, T append_me)
{
    T *walker = a + size;
    *walker = append_me;
    size++;
}

template <class T>
void shift_right(T *a, int &size, T* shift_here){
    T *walker_end = a + size;
    for(int i = size; i > shift_here - a; i--)
    {
        *walker_end = *(walker_end - 1);
        walker_end--;
    }
    size++;
}

template <class T>
void shift_right(T *a, int &size, int shift_here){
    T *shift_ptr = a + shift_here;
    shift_right(a, size, shift_ptr);
}
template <class T>
int search(T* a, int size, const T& find_me){
    T *walker = a;
    int index = 0;
    for (int i=0; i < size; i++)
   {
    if(*walker == find_me)
    {
        return index;
    }
    walker++;
    index++;
   }
    return -1;
}

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy){
    for (int i = 0; i < many_to_copy; i++){
        *dest = *src;
        dest++;
        src++;
    }
}

template <class T>
T* copy_array(const T *src, int size){
    T *dest_ptr;
    dest_ptr = allocate<T>(size);
    copy_array(dest_ptr, src, size);
    return dest_ptr;
}

template <class T>
string array_string(const T *a, int size){
    string s ="[";
    for (int i = 0; i < size; i++){
        string convert = " " + to_string(*a);
        s += convert;
        a++;
    }
    s = s + " ][" + to_string(size) + "]";
    return s;
}

template<class T>
T* allocate(int capacity){
    T *p = new T[capacity];
    return p;
}

template<class T>
T* reallocate(T* a, int size, int capacity){
    T *ptr; 
    ptr = allocate<T>(capacity);
    copy_array(ptr, a, size);
    delete []a;
    return ptr;
}

#endif