#ifndef HBVECTOR_H
#define HBVECTOR_H

#include <iostream>
#include <string>
#include <iterator>
using namespace std;

template <class T>
class HBVector
{
private:
	T* data;
	int Size, Capacity;

public:
    HBVector(int cap);
    HBVector(T* arr, int n);
    HBVector(const HBVector& other);
    ~HBVector();
    HBVector& operator=(const HBVector& another);
    HBVector& operator=(HBVector&& another);
    T& operator[](int index);

    void push_back(T element);
    T pop_back();
    //void erase(iterator iter);
    //void erase(iterator iter1, iterator iter2);
    void clear();
    //void insert(iterator, T element);
    //iterator begin();
    //iterator end();

    bool operator== (const HBVector& other);
    bool operator<  (const HBVector& other);
    int size() const;
    int capacity() const;
    T* getData() { return data; }
    void resize(int newCap);
    bool empty();
    friend ostream& operator<<(ostream& out, const HBVector<T> &vec);

};

#include "HBVector.cpp"

#endif // !HBVECTOR_H