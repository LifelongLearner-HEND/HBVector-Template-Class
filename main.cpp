#include <iostream>
using namespace std;

template <class T>
class HBVector{
private:
    // Dynamically allocated array of type T
    T* data;
    int size;
    int capacity;
public:
    // initialize capacity and size
    HBVector(int cap = 10){
        size = 0;
        capacity = cap;
    }

    // initialize size and fill the vector with
    // another passed array or a pointer
    HBVector(T* arr ,int n){
        size = n;
        data = new T[size];
        for(int i = 0; i < size; i++){
            data[i] = arr[i];
        }
    }

    // copy another vector and paste it to the original one
    // the copied vector is of class template HBVector and oof type T
    HBVector(HBVector<T>& vec){
        // new vector size should equal to the passed vector size
        size = vec.size;
        data = new T[size];
        for (int i = 0; i < size; i++){
            data[i] = vec.data[i];
        }
    }

    // Access vector items by index
    T& operator[] (int index){
        if (index > size - 1 || index < 0){
            cout << "Out of Range Error.\n";
            exit(-1);
        }
        else{
            return data[index];
        }
    }

    //  copy operator assignment
    // copying a vector of HBVector class and type T to the original vector
    HBVector<T> &operator= (HBVector<T> &another){
        if (this != &another){
            delete [] data;
            size = another.size;
            data = new T[size];
            for (int i = 0; i < size; i++){
                data[i] = another.data[i];
            }
        }
        return *this;
    }

    // move operator assignment
    // moving a vector of HBVector class and type T to the original vector
    // and then free the memory of the moved vector
    HBVector<T> &operator= (HBVector<T> &&another){
        if (this != &another){
            delete [] data;
            size = another.size;
            data = another.data;
            another.data = nullptr;
        }
        return *this;
    }

    // Destructor to delete the allocated memory
    ~HBVector(){
        delete [] data;
    }

    // Add an item to the end of the vector
    friend ostream &operator << (ostream out ,HBVector<T>);
};

// Overload the << operator to print the vector
template <class T>
ostream &operator << (ostream out, HBVector<T> vec){
    for (int i = 0; i < vec.size; i++){
        out << vec.data[i] << " ";
    }
    return out;
}

int main() {
    /*
    string arr[5] = {"hend","arwa","ali","omar","mai"};
    HBVector<string> v(arr,5);
    cout << v[5];
    int arr1[5] = {2,3,6,8,7};
    HBVector <int> v1(arr1 ,5);
    int arr2[7] = {2,3,6,8,7,5,6};
    HBVector <int> v2(arr2 ,7);
    v2 = v1;
    for (int i = 0; i < 5; i++){
        cout <<  v1[i] << " ";
    }
     */
}
