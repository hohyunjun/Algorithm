#include <iostream>
using namespace std;

int main(){

    int E,S,M;
    int e,s,m;
    e = s = m = 1;
    int cnt = 1;

    cin >> E >> S >> M;    

    if(e==E && s==S && m==M){
        cout << cnt << endl;
        return 0;
    }

    for(int i=1; i<=100000; i++){
        cnt++;
        e = e+1;
        s = s+1;
        m = m+1;
        if(e>15){
            e = 1;
        }
        if(s>28){
            s = 1;
        }
        if(m>19){
            m = 1;
        }
        if(e==E && s==S && m==M){
            cout << cnt << endl;
            break;
        }
    }



    return 0;
}