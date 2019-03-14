#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체
int check[4000002];

int main(){

    //소수 구하기
    int n;

    cin >> n;

    if(n==1){
        cout << 0 << '\n';
        return 0;
    }

    vector<int> primes;
    
    for(int i=2; i<=n; i++){
        if(check[i] == false){
            primes.push_back(i);
            for(int j=i*2; j<=n; j+=i){
                check[j] = true;
            }
        }
    }

    int pn = primes.size();

    int left = 0, right = 0, sum = primes[0], ans = 0;
    while(left < pn && right < pn){
        if(sum == n){
            ans++;
            right+=1;
            if(right >= pn) break;
            sum+=primes[right];
        }else if(sum < n){
            right+=1;
            if(right >= pn) break;
            sum+=primes[right];
        }else if(sum > n){
            sum-=primes[left];
            left+=1;
            if(left >= pn) break;
        }
    }

    cout << ans << '\n';


    return 0;
}