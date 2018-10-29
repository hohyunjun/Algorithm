#include <iostream>
using namespace std;

int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T, cnt;
    string a;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> a;
        cnt = 0;
        for(int j=0; j<a.length(); j++){
            if(a[j] == '('){
                cnt += 1;
            }else if(a[j] == ')'){
                cnt -= 1;
            }
            if(cnt<0){
                break;
            }
        }
        if(cnt==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}