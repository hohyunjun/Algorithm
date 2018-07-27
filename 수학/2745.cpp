#include <iostream>
#include <math.h>
using namespace std;

int main(){

    string N;
    int B;
    int answer = 0;

    cin >> N >> B;

    for(int i=0; i<N.length(); i++){
        if('A'<=N[i] && N[i]<='Z'){
            answer += (N[i]-'A'+10) * pow(B, N.length()-1-i);
        }else{
            answer += (N[i]-'0') * pow(B, N.length()-1-i); 
        }
    }

    cout << answer << endl;

    return 0;
}