// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 3
// Program Name: HBVector
// Last Modification Date: 23/12/2022
// Author1 and ID and Group: Hend Ahmed Kamal Abd-El Aziem  ID: 20211111
// Author2 and ID and Group: Basma Mahmoud Hashim Ali  ID: 20210091
/*
description: In this problem we developed our own C++ vector template class.
that can hold some functions .
such as: begin ,end , erase, pop_back, push_back, etc...
 */

#ifndef HBVECTOR_H
#define HBVECTOR_H
#define TMP template <class T>
#include <iterator>
#include <iostream>
#include <string>
using namespace std;
// Iterator class with implementation
TMP
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* ptr) : ptr(ptr) {}
    Iterator& operator++() { ptr++; return *this; }
    Iterator operator++(int) { Iterator tmp(*this); operator++(); return tmp; }
    Iterator& operator--() { ptr--; return *this; }
    Iterator operator--(int) { Iterator tmp(*this); operator--(); return tmp; }
    bool operator==(const Iterator& rhs) { return ptr == rhs.ptr; }
    bool operator!= (const Iterator& rhs) { return ptr != rhs.ptr; }
    bool operator< (const Iterator& rhs) { return ptr < rhs.ptr; }
    bool operator> (const Iterator& rhs) { return ptr > rhs.ptr; }
    bool operator>= (const Iterator& rhs) { return ptr >= rhs.ptr; }
    bool operator<= (const Iterator& rhs) { return ptr <= rhs.ptr; }
    bool operator- (const Iterator& rhs) { return ptr - rhs.ptr; }
    bool operator+ (const Iterator& rhs) { return ptr + rhs.ptr; }
    Iterator operator + (int n) { Iterator tmp(ptr + n); return tmp; }
    Iterator operator - (int n) { Iterator tmp(ptr - n); return tmp; }
    T* operator -> () { return ptr; }
    T& operator* () { return *ptr; }
};

//--------------------------------------------------------------------------------------------
// HBVector class
template <typename T>
class HBVector
{
private:
    T* data;
    int Size, Capacity;

public:
    HBVector(int cap = 10);
    HBVector(T* arr ,int n);
    HBVector(HBVector<T>& vec);
    T& operator[] (int index);
    HBVector<T> &operator= (HBVector<T> &another);
    HBVector<T> &operator= (HBVector<T> &&another);
    ~HBVector();

    void push_back(T element);
    T pop_back();
    void erase(Iterator<T> iter);
    Iterator <T> begin();
    Iterator <T> end();
    void erase(Iterator<T> iter1, Iterator<T> iter2);
    void clear();
    void insert(Iterator<T>, T element);

    int size() const;
    int capacity() const;
    void resize(int newCap);
    bool empty();
    template <typename F>
    friend ostream& operator<< (ostream& out, HBVector<F>& vec);

};

template<typename F>
ostream &operator<<(ostream &out, HBVector<F> &vec) {
    for (int i = 0; i < vec.Size; ++i) {
        out << vec[i] << " ";
    }
    return out;
}

#endif // !HBVECTOR_H

