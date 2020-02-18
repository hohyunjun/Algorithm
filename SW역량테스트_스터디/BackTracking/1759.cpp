#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;

bool check(vector<char> tmp){
    int moemCnt = 0;
    int jaemCnt = 0;
    for(auto each : tmp){
        if(each == 'a' || each == 'e' || each == 'i' || each == 'o' || each == 'u'){
            moemCnt++;
        }else{
            jaemCnt++;
        }
    }
    if(moemCnt < 1 || jaemCnt < 2) return false;
    return true;
}

void solve(vector<char> p, int index, vector<char> tmp){

    if(tmp.size() == l){
        if(check(tmp)){
            for(auto each: tmp){
                cout << each;
            }
            cout << '\n';
        }
        return;
    }

    if(index >= c) return;

    tmp.push_back(p[index]);
    solve(p, index+1, tmp);
    tmp.pop_back();
    solve(p, index+1, tmp);

}


int main(){

    cin >> l >> c;

    vector<char> p(c);

    for(int i=0; i<c; i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    vector<char> tmp;

    solve(p, 0, tmp);


    return 0;
}