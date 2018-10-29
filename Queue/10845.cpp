#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queue[10000] = {};
    int begin = 0;
    int end = 0;
    string cmd;
    int T;
    int pushNum;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> pushNum;
            queue[end] = pushNum;
            end+=1;
        }
        if(cmd == "pop"){
            if(end-begin == 0){
                cout << -1 << endl;
            }else{
                int tmp = queue[begin];
                begin += 1;
                cout << tmp << endl;
            }
        }
        if(cmd == "size"){
            cout << end-begin << endl;
        }
        if(cmd == "empty"){
            if(end-begin == 0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
        if(cmd == "front"){
            if(end-begin == 0){ cout << -1 << endl;}
            else{
                cout << queue[begin] << endl;
            }
        }
        if(cmd == "back"){
            if(end-begin == 0){cout << -1 << endl;}
            else{
                cout << queue[end - 1] << endl;
            }
        }
    }


    return 0;
}