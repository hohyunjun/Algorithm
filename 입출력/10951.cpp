// test case 개수조차 주어지지 않은 경우
// EOF 까지 
// scanf의 return 값은 성공적으로 입력받은 변수의 개수이다.
// scanf("%d %d",&a,&b) == 2
#include <iostream>
using namespace std;

int main(){

    int a, b;

    while(cin >> a >> b){
        cout << a + b << endl;
    }


    return 0;
}