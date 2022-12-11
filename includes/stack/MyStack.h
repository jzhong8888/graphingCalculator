#ifndef MY_STACK_H
#define MY_STACK_H
#include <iostream>
#include <cassert>
#include "../linked_list_functions/linked_list_functions.h"
#include "../node/node.h"

using namespace std;

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                //default ctor
        Iterator(node<T>* p){_ptr =p;}          //Point Iterator to where
                                                //  p is pointing to

        T &operator*(){
            assert(_ptr);
            return _ptr->_item;
        }     

        T *operator->(){
            assert(_ptr);
            T* p;
            *p = _ptr->_item;
            return p;
        }    

        bool is_null(){
            if (_ptr == nullptr){
                return true;
            }
            else return false;
        } 

        friend bool operator!=(const Iterator &left, const Iterator &right){
            if (left._ptr != right._ptr){
                return true;
            }
            else return false;
        } //true if left != right     

        friend bool operator==(const Iterator &left, const Iterator &right){
            if (left._ptr == right._ptr){
                return true;
            }
            else return false;
        } //true if left == right

        Iterator &operator++(){
            _ptr = _ptr->_next;
            return *this;
        }     

        friend Iterator operator++(Iterator &it, int unused){
            Iterator hold;
            hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }          //friend operator: it++  

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename TT>
    friend ostream& operator<<(ostream& outs, 
                                        const Stack<TT>& printMe);

    Iterator begin() const;              //Iterator to the head node
    Iterator end() const;                //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

template <class T>
Stack<T>::Stack(){
    _top = nullptr;
    _size = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
}

template <class T>
Stack<T>::~Stack(){
    _clear_list(_top);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
    if (this == &RHS){
        return *this;
    }
    _clear_list(_top);
    _top = _copy_list(RHS._top);
    _size = RHS._size;
    return *this;
}

template <class T>
T Stack<T>::top(){
    return _top->_item;
}

template <class T>
bool Stack<T>::empty(){
    if (_top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void Stack<T>::push(T item){
    _top = _insert_head(_top, item);
    _size++;
}

template <class T>
T Stack<T>::pop(){
    T pop = _remove_head(_top);
    _size--;
    return pop;
}

template<typename TT>
    ostream& operator<<(ostream& outs, const Stack<TT>& printMe){
        outs << "Stack:Head->";
        _print_list(printMe._top);
        return outs;
    }

template <class T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    Iterator result(_top);
    return result;
}

template <class T>
typename Stack<T>::Iterator Stack<T>::end() const{
    Iterator result(nullptr);
    return result;
}




#endif