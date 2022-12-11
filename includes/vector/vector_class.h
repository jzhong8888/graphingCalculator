#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iostream>
#include <iomanip>
#include <cassert>

#include "../array_functions/array_functions.h"
#include "../add_entry/add_entry.h"

using namespace std;



template <class T>
class Vector{
    public:

    Vector();
    
    Vector(int size );
    Vector(T *arr, int size);
    
    // big three:

    //destructer
    ~Vector();

    //copy constructor
    Vector (const T& other);

    //assignment operator
    Vector& operator = (const Vector &rhs);

    //member access functions:
    T& operator [](int index);

    const T& operator [](int index) const;

    T& at(int index);              //return reference to item at position index
    const T& at(int index) const;  //return a const item at position index

    T& front();                         //return item at position 0.

    T& back();                          //return item at the last position

    //Push and Pop functions:
    Vector& operator +=(const T& item);   //push_back

    void push_back(const T& item);      //append to the end

    T pop_back();                       //remove last item and return it

    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos

    void erase(int erase_this_index);        //erase item at position
    
    int index_of(const T& item);             //search for item. retur index.

    //size and capacity:
    void set_size(int size);              //enlarge the vector to this size

    void set_capacity(int capacity);      //allocate this space

    int size() const;   //return _size

    int capacity() const;     //return _capacity

    bool empty() const;                    //return true if vector is empty
    
    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);

   
   

    private:
    int _size;
    T *_arr;
    int _capacity;
};


  template <class T>
  Vector<T>::Vector(){
    _size = 0;
    _capacity = 1;
    _arr = allocate<T>(_capacity);
  }

  template <class T>
  Vector<T>::Vector(int size){
    const bool debug = false;
    if(debug){
        cout << "DEBUG: CTOR: Vector::Vector(int size)" << endl;
    }
   
    _size = size;

    //_capacity = _size;
    
    _capacity = MINIMUM_CAPACITY;
       while (_capacity < _size)
        {
            _capacity *= 2;
        }
    
    _arr = allocate<T>(_capacity);
    }

    template <class T>
    Vector<T>::Vector(T *arr, int size)
    {
        const bool debug = false;
        if(debug){
            cout << "DEBUG: CTOR: Vector::Vector(T *arr, int size)" << endl;
        }
        
        _size = size;

        
        _capacity = MINIMUM_CAPACITY;
        while (_capacity < _size)
        {
            _capacity *= 2;
        }
        
        _arr = allocate<T>(_capacity);
        copy_array(_arr, arr, size);
    }

    template <class T>
    Vector<T>::~Vector(){
        delete[]_arr;
    }

    template <class T>
    Vector<T>::Vector (const T& other){
        _arr = allocate<T>(other._capacity);
        _capacity = other._capacity;
        copy_array(_arr, other._arr, other._size);
        _size = other._size;
    }

    template <class T>
    Vector<T>& Vector<T>::operator = (const Vector &rhs)
    {
        if(this == &rhs){
            return *this;
        }
        delete []_arr;
        _arr = allocate<T>(rhs._capacity);
        copy_array(_arr, rhs._arr, rhs._size);
        _capacity = rhs._capacity;
        _size = rhs._size;
        return *this;
    }


    template <class T>
    T& Vector<T>::operator [](int index)
    {
        assert(index >= 0);
        assert(index < _size);
        return _arr[index];
    }


    template <class T>
    const T& Vector<T>::operator [](int index) const{
        assert(index >= 0);
        assert(index < _size);
        return _arr[index];
    }

    template <class T>
    T& Vector<T>::at(int index)
    {
        T *walker =_arr + index;
        return *walker;
    }

    template <class T>
    const T& Vector<T>::at(int index) const{
        T *walker =_arr + index;
        return *walker;
    }

    template <class T>
    T& Vector<T>::front(){
        T *walker = _arr;
        return *walker;
    }

    template <class T>
    T& Vector<T>::back(){
        T *walker = _arr + _size - 1;
        return *walker;
    }

    template <class T>
    Vector<T>& Vector<T>::operator +=(const T& item){
        _arr = add_entry(_arr, item, _size, _capacity);
        return *this;
        }

    template <class T>
    void Vector<T>::push_back(const T& item){
        _arr = add_entry(_arr, item, _size, _capacity);
    }

    template <class T>
    T Vector<T>::pop_back(){
        T result;
        _arr = remove_last_entry(_arr, result, _size, _capacity);
        return result;
    }

    template <class T>
    void Vector<T>::insert(int insert_here, const T& insert_this){
        _arr = insert_entry(_arr, insert_this, insert_here, _size, _capacity);
    }

    template <class T>
    void Vector<T>::erase(int erase_this_index){
        _arr = erase_entry(_arr, erase_this_index, _size, _capacity);
    }

    template <class T>
    int Vector<T>::index_of(const T& item){
        int result;
        result = search(_arr, _size, item);
        return result;
    }

    template <class T>
    void Vector<T>::set_size(int size){
        _arr = reallocate(_arr, size, size);
    }

    template <class T>
    void Vector<T>::set_capacity(int capacity){
        _arr = reallocate(_arr, _size, capacity);
    }

    template <class T>
    int Vector<T>::size() const{
        return _size;
    }

    template <class T>
    int Vector<T>::capacity() const{
        return _capacity;
    }

    template <class T>
    bool Vector<T>::empty() const{
        if (_size == 0)
        {
        return true;
        }
        else 
        {
            return false;
        }
    }

    template <class U>
    ostream& operator <<(ostream& outs, const Vector<U>& _a){
        print_array(_a._arr, _a._size, _a._capacity, outs);
        return outs;
    }



#endif