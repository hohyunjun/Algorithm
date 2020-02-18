#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> mushrooms(10);

    for(int i=0; i<10; i++){
        cin >> mushrooms[i];
    }

    vector<int> sums(10, 0);

    for(int i=0; i<10; i++){
        for(int j=0; j<=i; j++){
            sums[i] += mushrooms[j]; 
        }
    }

    vector<int> diffs(10);

    for(int i=0; i<10; i++){
        diffs[i] = abs(sums[i] - 100);
    }

    // 버섯의 sum 위치와 diff 값을 pair형태로 저장한다.
    vector<pair<int,int>> posDiffs(10);

    for(int i=0; i<10; i++){
        posDiffs[i] = make_pair(diffs[i], i);
    }

    // 값의 차이를 기준으로 오름차순 정렬한다.
    sort(posDiffs.begin(), posDiffs.end());

    int cnt = 0;
    for(auto each:posDiffs){
        if(each.first == posDiffs[0].first) cnt++;
    }

    if(cnt == 1){
        cout << sums[posDiffs[0].second] << '\n';
    }else{
        cout << sums[posDiffs[1].second] << '\n';
    }

    return 0;
}