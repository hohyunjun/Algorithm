#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int deque[10000];
    string cmd;
    int begin = 0;
    int end = 0;
    int N;
    int X;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> X;
            end++;
            for(int j=end-1; j>=begin+1; j--){
                deque[j] = deque[j-1];
            }
            deque[begin] = X;
        }
        if(cmd == "push_back"){
            cin >> X;
            deque[end] = X;
            end++;
        }
        if(cmd == "pop_front"){
            if(end-begin==0){
                cout << -1 << endl;
            }else{
                cout << deque[begin] << endl;
                begin++;
            }
        }
        if(cmd == "pop_back"){
            if(end-begin==0){
                cout << -1 << endl;
            }else{
                cout << deque[end-1] << endl;
                end--;
            }
        }
        if(cmd == "size"){
            cout << end-begin << endl;
        }
        if(cmd == "empty"){
            if(end-begin==0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
        if(cmd == "front"){
            if(end-begin == 0){
                cout << -1 << endl;
            }else{
                cout << deque[begin] << endl;
            }
        }
        if(cmd == "back"){
            if(end-begin==0){
                cout << -1 << endl;
            }else{
                cout << deque[end-1] << endl;
            }
        }
    }

    return 0;
}