#include <iostream>
using namespace std;

int main(){

    int day;

    cin >> day;

    int cnt=0;

    for(int i=0; i<5; i++){
        int num;
        cin >> num;
        if(num%10 == day) cnt++;
    }

    cout << cnt << endl;

    return 0;
}