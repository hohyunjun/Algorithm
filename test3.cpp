#include <iostream>
#include <array>
using namespace std;

int main(){

    int arr[42];

    cout << sizeof(arr)/sizeof(int) << '\n';


    const size_t arraySize{5};

    array<int, arraySize> values;

    cout << values.size() << '\n';


    return 0;
}