#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(auto each:phone_book){
        cout << each << " ";
    }
    for(int i=0; i<phone_book.size(); i++){
        for(int j=i+1; j<phone_book.size(); j++){
            if(phone_book[i].length() > phone_book[j].length()){
                continue;
            }
            string checkStr = phone_book[j].substr(0, phone_book[i].length());
            if(checkStr == phone_book[i]){
                answer = false;
                break;
            }
        }
    }
    return answer;
}