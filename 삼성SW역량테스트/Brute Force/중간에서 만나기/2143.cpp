#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    long long int t;
    int n, m;

    cin >> t;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    long long int ans = 0;

    // 부 배열의 개수는 (n+1)n/2 개
    vector<int> first(n*(n+1)/2); // a의 부배열의 합 저장
    vector<int> second(m*(m+1)/2); // b의 부배열의 합 저장

    int cnt = -1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cnt++;
            for(int k=i; k<=j; k++){
                first[cnt] += a[k]; 
            }
        }
    }

    cnt = -1;
    for(int i=0; i<m; i++){
        for(int j=i; j<m; j++){
            cnt++;
            for(int k=i; k<=j; k++){
                second[cnt] += b[k]; 
            }
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int left = 0;
    int right = second.size()-1;

    while(left<first.size() && right >= 0){
        int sum = first[left] + second[right];
        if(sum == t){ // 목표값을 찾았을 경우
            long long int ls=0, rs=0;
            int tmpl, tmpr;
            tmpl = left;
            tmpr = right;
            while(tmpl<first.size() && first[left]==first[tmpl]){
                ls++;
                tmpl++;
            }
            while(tmpr>=0 && second[right] == second[tmpr]){
                rs++;
                tmpr--;
            }
            left += ls;
            right -= rs;
            ans += ls*rs;
        }else if(sum < t){
            left++;
        }else{
            right--;
        }
    }

    cout << ans << '\n';

    return 0;
}