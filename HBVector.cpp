#include "HBVector.h"
#define TMP template <class T>
using namespace std;

TMP
// initialize capacity and size
HBVector<T>::HBVector(int cap) {
    Size = 0;
    Capacity = cap;
}
TMP
// initialize size and fill the vector with
// another passed array or a pointer
HBVector<T>::HBVector(T *arr, int n) {
    Size = n;
    data = new T[Size];
    for(int i = 0; i < Size; i++){
        data[i] = arr[i];
    }
}

TMP
// copy another vector and paste it to the original one
// the copied vector is of class template HBVector and oof type T
HBVector<T>::HBVector(HBVector<T> &vec) {
    Size = vec.Size;
    data = new T[Size];
    for (int i = 0; i < Size; i++){
        data[i] = vec.data[i];
    }
}

TMP
// Access vector items by index
T &HBVector<T>::operator[](int index) {
    if (index < 0 || index >= Size)
    {
        cout << "Index out of range";
    }
    return data[index];
}

TMP
//  copy operator assignment
// copying a vector of HBVector class and type T to the original vector
HBVector<T> &HBVector<T>::operator =(HBVector<T> &another) {
    if (this != &another){
        delete [] data;
        Size = another.Size;
        data = new T[Size];
        for (int i = 0; i < Size; i++){
            data[i] = another.data[i];
        }
    }
    return *this;
}

TMP
// move operator assignment
// moving a vector of HBVector class and type T to the original vector
// and then free the memory of the moved vector
HBVector<T> &HBVector<T>::operator =(HBVector<T> &&another) {
    if (this != &another){
        delete [] data;
        Size = another.Size;
        data = another.data;
        another.data = nullptr;
    }
    return *this;
}

TMP
void HBVector<T>::push_back(T element) {
        if (Size == Capacity)
    {
        T* temp = new T[Capacity * 2];
        for (int i = 0; i < Size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        Capacity *= 2;
    }
    data[Size] = element;
    Size++;
}

TMP
T HBVector<T>::pop_back() {
    if (Size == 0)
    {
        cout << "Vector is empty";
    }
    Size--;
    return data[Size];
}

TMP
Iterator<T> HBVector<T>::begin() {
    return Iterator <T> (data);
}

TMP
Iterator<T> HBVector<T>::end()
{
    return Iterator <T> (data + Size - 1);
}

TMP
void HBVector<T>::erase(Iterator<T> itr) {
    if (itr < begin() || itr > end())
    {
        cout << "Iterator out of range";
    }
    for (Iterator<T> i = itr; i < end(); i++)
    {
        *i = *(i + 1);
    }
    --Size;
}

TMP
void HBVector<T>::erase(Iterator<T> iter1, Iterator<T> iter2) {
    if (iter1 < begin() || iter1 > end() || iter2 < begin() || iter2 > end())
    {
        cout << "Iterator out of range";
    }
    T* temp = new T[Size - (iter2 - iter1)];
    int index1, index2;
    for (int i = 0; i < Size; i++){
        if (data[i] == *iter1){
            index1 = i;
        }
        else if (data[i] == *iter2){
            index2 = i;
        }
    }
    int k = 0;
    for (int i = 0; i < index1; i++){
        temp[k] = data[i];
        k++;
    }
    for (int i = index2; i < Size; i++){
        temp[k] = data[i];
        k++;
    }
    delete [] data;
    data = temp;
    Size = k;
}

TMP
void HBVector<T>::clear() {
    Size = 0;
}

TMP
void HBVector<T>::insert(Iterator<T> itr, T element) {
    if (itr < data || itr > data + Size)
    {
        cout << "Iterator out of range";
    }

    if (Size == Capacity)
    {
        resize(Capacity * 2);
    }
    int index;
    for (int i = 0; i < Size; i++){
        if (data[i] == *itr){
            index = i;
        }
    }
    int k = 0;
    T* temp = new T[Size + 1];
    for (int i = 0; i < index; i++){
        temp[k] = data[i];
        k++;
    }
    temp[k] = element;
    k++;
    for (int i = index; i < Size; i++){
        temp[k] = data[i];
        k++;
    }
    delete [] data;
    data = temp;
    Size++;
}

TMP
int HBVector<T>::size() const {
    return Size;
}

TMP
int HBVector<T>::capacity() const {
    return Capacity;
}

TMP
void HBVector<T>::resize(int newCap) {
        if (newCap < Size)
    {
        cout << "New capacity is too small";
    }
    T* temp = new T[newCap];
    for (int i = 0; i < Size; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    Capacity = newCap;

}

TMP
bool HBVector<T>::empty() {
    return Size == 0;
}

TMP
// Destructor to delete the allocated memory
HBVector<T>::~HBVector() {
    delete [] data;
}


