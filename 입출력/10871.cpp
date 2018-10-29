#include <iostream>
using namespace std;

int main()
{

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X;
    
    cin >> N >> X;

    int numbers[N];

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    for(int i=0; i<N; i++){
        if(numbers[i] < X){
            cout << numbers[i] << " ";
        }
    }

    return 0;
}