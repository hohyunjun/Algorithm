#include <iostream>
using namespace std;

int main(){

    int t;
    int tcnum = 0;

    cin >> t;

    while(t--){
        tcnum++;
        int sum = 0;

        for(int i=0; i<10; i++){
            int num;
            cin >> num;
            if(num%2) sum+= num;
        }

        cout << "#" << tcnum << " " << sum << '\n';

    }


    return 0;
}