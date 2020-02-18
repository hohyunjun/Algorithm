#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<long long int> h(n);

    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    stack<pair<long long int,int>> st; // pair의 첫번째 값은 height, 두번째 값은 동일 키값
    long long int cnt = 0;

    st.push(make_pair(h[0],1));

    for(int i=1; i<n; i++){
        // 다음 키값이 s.top()보다 큰경우
        if(h[i] > st.top().first){
            while(!st.empty() && h[i] > st.top().first){
                cnt += st.top().second;
                st.pop();
            }
            if(st.empty()){
                st.push(make_pair(h[i],1));
            }else{
                if(h[i] == st.top().first){
                    int sameCnt = st.top().second;
                    cnt += sameCnt;
                    st.pop();
                    if(!st.empty()){
                        cnt++;
                    }
                    st.push(make_pair(h[i],sameCnt+1));
                }else{
                    // 스택이 비어있지 않다면
                    if(!st.empty()){
                        cnt++;
                    }
                    st.push(make_pair(h[i],1));
                }
            }
        }else if(h[i] < st.top().first){
            // 다음 키값이 s.top()보다 작은경우
            cnt+= 1;
            st.push(make_pair(h[i],1));
        }else{
            // 다음 키값이 s.top()과 같은경우
            int sameCnt = st.top().second;
            cnt += sameCnt;
            st.pop();
            if(!st.empty()){
                cnt++;
            }
            st.push(make_pair(h[i],sameCnt+1));
        }
    }

    // while(!st.empty()){
    //     cout << st.top().first << "," << st.top().second << " // ";
    //     st.pop();
    // }

    // cout << '\n';
    cout << cnt << '\n';

    return 0;
}