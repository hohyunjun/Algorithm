#include <string>
#include <iostream>
using namespace std;

int main(){

    string str;

    cin >> str;

    int answer = 0;

    for(int i=0; i<str.length(); i++){
        if('A' <= str[i] && str[i] <= 'C'){
            answer += 3;
        }else if('D' <= str[i] && str[i] <= 'F'){
            answer += 4;
        }
        else if ('G' <= str[i] && str[i] <= 'I')
        {
            answer += 5;
        }
        else if ('J' <= str[i] && str[i] <= 'L')
        {
            answer += 6;
        }
        else if ('M' <= str[i] && str[i] <= 'O')
        {
            answer += 7;
        }
        else if ('P' <= str[i] && str[i] <= 'S')
        {
            answer += 8;
        }
        else if ('T' <= str[i] && str[i] <= 'V')
        {
            answer += 9;
        }
        else if ('W' <= str[i] && str[i] <= 'Z')
        {
            answer += 10;
        }
    }

    cout << answer << '\n';




    return 0;
}