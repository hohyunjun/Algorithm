#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    string changed1, changed2;
    int num1, num2;

    cin >> num1 >> num2;

    str1 = to_string(num1);
    str2 = to_string(num2);

    changed1 = str1;
    changed2 = str2;

    for(int i=str1.length()-1; i>=0; i--){
        changed1[str1.length() - 1 - i] = str1[i];
    }

    for (int i = str2.length() - 1; i >= 0; i--){
        changed2[str2.length() - 1 - i] = str2[i];
    }

    num1 = stoi(changed1);
    num2 = stoi(changed2);

    if(num1 >= num2){
        cout << num1 << endl;
    }else{
        cout << num2 << endl;
    }

    return 0;
}