#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, s;

    cin >> n >> s;

    int nums[40];

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    if(n==1){
        if(nums[0] == s){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
        return 0;
    }

    // 두 개의 작은 수로 쪼갠다
    int d1 = n/2;
    int d2 = n-d1;

    // d1의 경우 0부터 n/2 - 1 까지 부분집합의 합을 구한다
    vector<int> num1(d1);
    for(int i=0; i<d1; i++){
        num1[i] = nums[i];
    }
    vector<int> first(1<<d1); // 부분집합의 합을 저장할 벡터

    // d2의 경우 n/2 부터 n-1까지 부분집합의 합을 구한다
    vector<int> num2(d2);
    for(int i=0; i<d2; i++){
        num2[i] = nums[i+d1];
    }
    vector<int> second(1<<d2); // 부분집합의 합을 저장할 벡터

    // 비트마스크 활용해서 모든 부분집합의 합을 저장한다.
    for(int i=0; i< (1<<d1); i++){
        for(int j=0; j<d1; j++){
            if( i & (1 << j) ){ // i 내부에 j 값이 존재한다면
                first[i] += num1[j];
            }
        }
    }

    for(int i=0; i< (1<<d2); i++){
        for(int j=0; j<d2; j++){
            if( i & (1 << j) ){ // i 내부에 j 값이 존재한다면
                second[i] += num2[j];
            }
        }
    }

    long long int ans = 0;

    // 부분집합의 합을 구한 두 개의 벡터를 정렬한다.
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    // left, right pointer 를 두고 s를 찾는다.
    int left = 0;
    int right = second.size() - 1;

    while(left < first.size() && right>=0){
        long long int sum = first[left] + second[right];
        if(sum > s){
            right-=1;
        }else if(sum < s){
            left+=1;
        }else if(sum == s){ // s와 같은 경우를 찾은 경우
            long long int ls=1, rs=1; // ls, rs에는 현재 first[left], second[right] 값과 같은 값들의 개수를 저장
            left+=1;
            right-=1;
            while(left<first.size() && first[left] == first[left-1]){
                ls += 1;
                left += 1;
            }
            while(right >= 0 && second[right] == second[right+1]){
                rs+=1;
                right -= 1;
            }
            ans += ls*rs;
        }
    }    

    if(s == 0) ans -= 1;
    cout << ans << '\n';

    return 0;
}