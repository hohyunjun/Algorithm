#include <iostream>
using namespace std;

void local(int var){
    var += 10;
}

int main(){

    int var = 10;

    cout << "함수 호출 전 : " << var << '\n';

    local(var);

    cout << "local() 함수 호출 후 : " << var << '\n';

    return 0;
}