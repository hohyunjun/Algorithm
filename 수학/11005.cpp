#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B;
    cin >> N >> B;
    vector<char> ans;

    while(N){
        char tmp;
        if(N%B>=10){
            tmp = 'A' + N%B-10;
        }else{
            tmp = (N%B) + '0';
        }
        N/=B;
        ans.push_back(tmp);
    }

     for(int i=ans.size()-1; i>=0; i--){
         cout << ans[i];
     }

    return 0;
}