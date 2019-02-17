#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, s;
    int ans = 0;

    cin >> n >> s;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // n개 중에서 1,2,3,...n개를 뽑는 경우의 수를 모두 계산

    for(int i=1; i<=n; i++){
        vector<int> check;
        for(int j=0; j<i; j++){
            check.push_back(1);
        }
        for(int j=0; j<n-i; j++){
            check.push_back(0);
        }

        sort(check.begin(), check.end());

        do{
            int tmp = 0;
            for(int i=0; i<check.size(); i++){
                if(check[i] == 1){
                    tmp += nums[i];
                }
            }
            if(tmp == s) ans++;
        }while(next_permutation(check.begin(), check.end()));
    }

    cout << ans << '\n';


    return 0;
}