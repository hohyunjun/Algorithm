#include <cstdio>
#include <vector>
using namespace std;

bool isPrime(int n){
    if(n<2){
        return false;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }

    return true;
}


int main(){

    bool check[1000001];
    vector<int> primes;

    check[0] = true;
    check[1] = true;

    for(int i=2; i*i<=1000000; i++){
        if(check[i]==false){
            for(int j=i*2; j<=1000000; j+=i){
                check[j] = true;
            }
        }
    }
    
    for(int i=3; i<=1000000; i++){
        if(check[i]==false){
            primes.push_back(i);
        }
    }

    int n, a, b;

    while(scanf("%d", &n)){
        if(n==0) break;
        bool find = false;
        for(int i=0; i<primes.size(); i++){
            if(isPrime(n-primes[i])){
                a = primes[i];
                b = n-primes[i];
                find = true;
                break;
            }
        }

        if(find){
            printf("%d = %d + %d\n", n, a, b);
        }else{
            printf("Goldbach's conjecture is wrong.");
        }
    }

    return 0;
}