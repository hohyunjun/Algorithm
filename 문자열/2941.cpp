// 그냥 단순하게 인덱스 값을 비교해주는 형식으로 풀이해도 된다.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string alpha;
int answer;
int check[101];

void removeCroatian(string croatian){

    string tmp;
    for(int i=0; i<alpha.length(); i++){
        tmp = alpha.substr(i);
        // cout << tmp << '\n';
        while (tmp.find(croatian) != string::npos && check[tmp.find(croatian) + i] == 0)
        {
            if(croatian == "dz="){
                int foundIndex = tmp.find(croatian);
                check[foundIndex + i] = 1;
                check[foundIndex + i + 1] = 1;
                check[foundIndex + i + 2] = 1;
                answer += 1;
            }else{
                int foundIndex = tmp.find(croatian);
                check[foundIndex + i] = 1;
                check[foundIndex + i + 1] = 1;
                answer += 1;
            }
        }
    }
}

int main(){

    cin >> alpha;

    removeCroatian("c=");
    removeCroatian("c-");
    removeCroatian("dz=");
    removeCroatian("d-");
    removeCroatian("lj");
    removeCroatian("nj");
    removeCroatian("s=");
    removeCroatian("z=");

    for(int i=0; i<alpha.length(); i++){
        if(check[i] == 0){
            answer += 1;
        }
    }

    cout << answer << '\n';

    return 0;
}