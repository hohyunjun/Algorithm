#include <iostream>
using namespace std;

void Display(const char* str, int n){ // 문자열 str을 n번 출력함
    while(n){
        cout << str << " ";
        n--;
    }
    cout << '\n';
}
void Display(const char* str1, const char* str2){ // str1 과 str2를 함께 출력한다.
    cout << str1 << " " << str2 << '\n';
}
void Display(int x, int y){ // x+y를 출력한다
    cout << x + y << '\n';
}

int main(){

    Display("C++", 3);
    Display("C++", "Overloading");
    Display(3, 4);

    return 0;
}