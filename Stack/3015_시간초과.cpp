#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// O(N^2) 으로 시간초과

int main(){

    int n;

    cin >> n;

    vector<long long int> h(n);

    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    long long int cnt = 0;

    for(int i=0; i<n-1; i++){
        stack<long long int> st;
        st.push(h[i]);
        for(int j=i+1; j<n; j++){
            if(st.size() == 1){
                if(st.top() < h[j]){
                    st.push(h[j]);
                    break;
                }
                st.push(h[j]);
            }else{
                if(st.top() > h[j]){
                    continue;
                }else{
                    st.push(h[j]);
                }
            }
        }
        cnt += st.size() - 1;
    }

    cout << cnt << '\n';



    return 0;
}