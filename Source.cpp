#include <iostream>
#include "HBVector.h"

using namespace std;
int main() {

    string arr[5] = { "hend","arwa","ali","omar","mai" };
    HBVector<string> v(arr, 5);
    int arr1[5] = { 2,3,6,8,7 };
    HBVector <int> v1(arr1, 5);
    int arr2[7] = { 2,3,6,8,7,5,6 };
    HBVector <int> v2(arr2, 7);
    //v2 = v1;
    cout << v1 << endl;

}
