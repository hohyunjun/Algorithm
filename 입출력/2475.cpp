#include <iostream>
#include <math.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    int n;

    for(int i=0; i<5; i++){
        cin >> n;
        sum += pow(n,2);
    }

    cout << sum % 10 << endl;



    return 0;
}