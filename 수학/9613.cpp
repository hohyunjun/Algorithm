#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){

    int t;
    int n;

    cin >>t;

    for(int i=0; i<t; i++){
        cin >> n;
        vector<int> numbers;
        int number;
        for(int j=0; j<n; j++){
            cin >> number;
            numbers.push_back(number);
        }
        long long int answer = 0;
        for(int j=0; j<numbers.size(); j++){
            for(int k=j+1; k<numbers.size(); k++){
                answer += gcd(numbers[j], numbers[k]);
            }
        }
        cout << answer << endl;
    }


    return 0;
}