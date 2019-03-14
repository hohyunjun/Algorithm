#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<long long> A(n);
    vector<long long> B(n);
    vector<long long> C(n);
    vector<long long> D(n);

    for(int i=0; i<n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<long long> first(n*n); // a,b의 합 저장
    vector<long long> second(n*n); // c,d의 합 저장

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            first[cnt++] = A[i] + B[j];
        }
    }

    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            second[cnt++] = C[i] + D[j];
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    long long int ans = 0;

    // int left = 0;
    // int right = second.size()-1;

    // while(left<first.size() && right>=0){
    //     long long int sum = first[left] + second[right];
    //     if(sum == 0){
    //         long long int ls=0, rs=0;
    //         int tmpl = left, tmpr = right;
            
    //         while(tmpl<first.size() && first[left]==first[tmpl]){
    //             ls++;
    //             tmpl++;
    //         }
    //         while(tmpr>=0 && second[right]==second[tmpr]){
    //             rs++;
    //             tmpr--;
    //         }
    //         left += ls;
    //         right -= rs;
    //         ans += rs*ls;
    //     }else if(sum>0){
    //         right--;
    //     }else{
    //         left++;
    //     }
    // }

    // equal_range 함수 사용하기
    for(int num:first){
        auto range = equal_range(second.begin(), second.end(), -num);
        ans += range.second-range.first;
    }

    cout << ans << '\n';

    return 0;
}