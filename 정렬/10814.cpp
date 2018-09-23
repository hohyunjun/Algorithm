#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, string> &u, const pair<int, string> &v){
    if(u.first < v.first){
        return true;
    }else{
        return false;
    }
}

int main(){

    int N;

    cin >> N;

    vector<pair<int, string> > customer(N);

    for(int i=0; i<N; i++){
        cin >> customer[i].first;
        cin >> customer[i].second;
    }

    stable_sort(customer.begin(), customer.end(), cmp);

    for(int i=0; i<N; i++){
        cout << customer[i].first << " " << customer[i].second << '\n';
    }

    return 0;
}