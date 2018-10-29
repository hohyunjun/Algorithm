#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &u, const pair<int,int> &v){
    if(u.second < v.second){
        return true;
    }else if(u.second == v.second){
        return u.first < v.first;
    }else{
        return false;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector< pair<int, int> > point(N);

    for(int i=0; i<N; i++){
        cin >> point[i].first >> point[i].second;
    }

    sort(point.begin(), point.end(), cmp);

    for(int i=0; i<N; i++){
        cout << point[i].first << " " << point[i].second << '\n';
    }

    return 0;
}