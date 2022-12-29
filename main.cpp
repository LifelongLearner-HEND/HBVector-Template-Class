#include <iostream>
#include "HBVector.h"
#include "HBVector.cpp"
using namespace std;
int main() {

//    int arr[] = {1, 2, 3, 4, 5};
    HBVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    Iterator <int > itr = v.begin();
    Iterator <int > itr2 = v.end();
//    cout << *itr << endl;
//    cout << *itr2 << endl;
    v.erase(itr, itr2);

//    v.insert(itr2, 10);
//    cout << *itr2 << endl;
    cout << v.size() << endl;
    cout << v;

//    vector <int> v1;
//    v1.push_back(1);
//    v1.push_back(2);
//    v1.push_back(3);
//    v1.push_back(4);
//    v1.push_back(5);
//    v1.erase(v1.begin(), v1.begin() + 2);
//    cout << v1.size() << endl;
//    for (int i = 0; i < v1.size(); i++) {
//        cout << v1[i] << " ";
//    }


    return 0;
}