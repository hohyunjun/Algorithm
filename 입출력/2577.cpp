#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

    int a,b,c;
    int mul;
    int count[10] = {};
    string str;

    scanf("%d%d%d", &a, &b, &c);

    mul = a*b*c;

    str = to_string(mul);

    for(int i=0; i<str.length(); i++){
        int x = str[i] - '0';
        count[x]++;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", count[i]);
    }

    return 0;
}