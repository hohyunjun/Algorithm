#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector< pair<int, int> > point(N);

    for(int i=0; i<N; i++){
        cin >> point[i].first;
        cin >> point[i].second;
    }

    sort(point.begin(), point.end());

    for(int i=0; i<N; i++){
        cout << point[i].first << " " << point[i].second << '\n';
    }


    return 0;
}