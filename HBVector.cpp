#include "HBVector.h"

#define TMP template <class T>

TMP
HBVector<T>::HBVector(int cap)
{
    if (cap <= 0)
    {
        cout << "For the Capacity, Please Enter a Number greater than Zero." << endl;
        exit(1);
    }

    Capacity = cap;
    data = new T[Capacity];
    Size = 0;
}

TMP
HBVector<T>::HBVector(T* arr, int n)
{
    Size = n;
    data = new T[Size];
    for (int i = 0; i < Size; i++)
        data[i] = arr[i];
}


TMP
HBVector<T>::HBVector(const HBVector& other)
{
    // new vector size should equal to the passed vector size
    Size = other.size();
    data = new T[Size];
    for (int i = 0; i < Size; i++) {
        data[i] = other.data[i];
    }
}

TMP
HBVector<T>::~HBVector()
{
    delete[] data;
}

TMP
HBVector<T>& HBVector<T>::operator= (const HBVector& another)
{
    if (this != &another) {
        delete[] data;
        Size = another.size();
        data = new T[Size];
        for (int i = 0; i < Size; i++) {
            data[i] = another.data[i];
        }
    }
    return *this;
}

/*TMP
HBVector<T>& HBVector<T>::operator= (const HBVector&& another)
{
    if (this != &another){
        delete [] data;
        Size = another.size();
        data = another.getData();
        another.data = nullptr;
    }
    return *this;
}
*/

TMP
T& HBVector<T>::operator[] (int index)
{
    if (index > Size - 1 || index < 0) {
        cout << "Out of Range Error.\n";
        exit(-1);
    }
    else {
        return data[index];
    }
}

///////////////////////////////////////////////////////////////////////

TMP
void HBVector<T>::push_back(T element)
{
    Size++;
    if (Size > Capacity)
        resize(Capacity + (Capacity / 2));
    *(data + Size - 1) = element;
}

TMP
T HBVector<T>::pop_back()
{
    Size--;

    if (Size <= 0)
    {
        cout << "The Vector is already Empty!" << endl;
        exit(1);
    }

    return *(data + Size);
}

/*TMP
void HBVector<T>::erase(iterator iter)
{

}
*/

/*
TMP
void HBVector<T>::erase(iterator iter1, iterator iter2)
{

}
*/

TMP
void HBVector<T>::clear()
{
    data = nullptr;
    Size = 0;
}

/*TMP
void HBVector<T>::insert(iterator iter, T element)
{

}
*/

/*TMP
iterator HBVector<T>::begin()
{

}
*/

/*TMP
iterator HBVector<T>::end()
{

}
*/

///////////////////////////////////////////////////////////////////////

TMP
bool HBVector<T>::operator== (const HBVector& other)
{
    if (Size != other.size())
        return false;

    for (int i = 0; i < Size; i++)
    {
        if (*(data + i) != *((other.getData()) + i))
            return false;
    }

    return true;
}

TMP
bool HBVector<T>::operator< (const HBVector& other)
{
    if (Size < other.size())
        return true;

    if (Size > other.size())
        return false;

    for (int i = 0; i < Size; i++)
        if (data[i] > other.data[i])
            return false;

    return true;
}


TMP
int HBVector<T>::size() const
{
    return Size;
}


TMP
int HBVector<T>::capacity() const
{
    return Capacity;
}

TMP
void HBVector<T>::resize(int newCap)
{
    Capacity = newCap;
    T* newData = new T[Capacity];
    for (int i = 0; i < Size; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

TMP
bool HBVector<T>::empty()
{
    return (Size == 0);
}

TMP
ostream& operator << (ostream out, HBVector<T> vec) {
    for (int i = 0; i < vec.size; i++) {
        out << vec.data[i] << " ";
    }
    return out;
}