#include <iostream>
using namespace std;

int main(){

    int t;

    cin >> t;

    for(int i=0; i<t; i++){
        int r, e, c;
        cin >> r >> e >> c;

        if(r < e - c){
            cout << "advertise" << '\n';
        }else if(r == e-c){
            cout << "does not matter" << '\n';
        }else{
            cout << "do not advertise" << '\n';
        }
    }    



    return 0;
}