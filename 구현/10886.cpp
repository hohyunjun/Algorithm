#include <iostream>
using namespace std;

int main(){

    int isCute = 0;
    int notCute = 0;

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        int result;
        cin >> result;
        if(result == 0) notCute++;
        else isCute++;
    }

    if(notCute > isCute){
        cout << "Junhee is not cute!" << '\n';
    }else{
        cout << "Junhee is cute!" << '\n';
    }


    return 0;
}