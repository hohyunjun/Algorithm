#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N;
    
    cin >> N;

    int numbers[N];

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    sort(numbers, numbers+N);

    for(int i=0; i<N; i++){
        cout << numbers[i] << '\n';
    }

    return 0;
}