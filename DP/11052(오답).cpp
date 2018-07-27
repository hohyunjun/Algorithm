#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = {};
int P[1001] = {};

int maxPrice(int n){
    if(n==0){
        dp[n] = 0;
        return dp[n];
    }
    if(n==1){
        dp[n] = P[n];
        return dp[n];
    }
    if(n>=2){
        if(dp[n]>0){
            return dp[n];
        }else{
            float pricePerOne[n + 1] = {};
            float sortedPricePerOne[n + 1] = {};

            for (int i = 1; i < n + 1; i++){
                pricePerOne[i] = (float)P[i] / i;
            }

            for (int i = 1; i < n + 1; i++){
                sortedPricePerOne[i] = pricePerOne[i];
            }

            sort(sortedPricePerOne, sortedPricePerOne+n + 1, greater<float>()); // 한 개당 가격을 정렬한다.

            int highPriceIndex;
            for (int i = 1; i < n + 1; i++){
                if (sortedPricePerOne[0] == pricePerOne[i]){
                    highPriceIndex = i;
                    break;
                }
            }

            dp[n] = maxPrice(n%highPriceIndex) + P[highPriceIndex]* (n/highPriceIndex);
            return dp[n];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for(int i=1; i<N+1; i++){
        cin >> P[i];
    }

    cout << maxPrice(N) << endl;
    
    return 0;
}