#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
    BOJ 15686 치킨 배달
    1. 초기 지도로부터 치킨집의 개수와 좌표를 알아내서 vector<pair<int,int>> 에 저장한다. + 집들의 좌표도 같은 방식으로 저장한다.
    2. next_permutation을 이용해서 m개의 치킨집 index만 뽑아낸다.
    3. 뽑아낸 치킨집 index 의 도시 치킨 거리를 구해 최솟값을 update해준다.
*/


int A[51][51]; // 도시전체정보

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    // 치킨집들의 좌표를 저장, 집들의 좌표도 저장
    vector<pair<int,int>> chicken;
    vector<pair<int,int>> house;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }else if(A[i][j] == 1){
                house.push_back(make_pair(i,j));
            }
        }
    }

    int ans = 0x7FFFFFFF;

    // next_permutation을 돌리기 위한 check 배열 선언
    vector<int> check(chicken.size(), 0);
    for(int i=0; i<m; i++){
        check[i] = 1;
    }

    sort(check.begin(), check.end());

    do{
        int cityDistance = 0;
        int eachDistance;

        // 각 집으로부터의 치킨 거리 최솟값을 구해서 도시 치킨 거리에 더한다.
        for(int i=0; i<house.size(); i++){
            eachDistance = 0x7FFFFFFF;
            for(int j=0; j<chicken.size(); j++){
                if(check[j] == 0) continue;
                int x, y;
                x = abs(chicken[j].first - house[i].first);
                y = abs(chicken[j].second - house[i].second);
                eachDistance = min(eachDistance, x+y);
            }
            cityDistance += eachDistance;
        }
        
        ans = min(ans, cityDistance);
        
    }while(next_permutation(check.begin(), check.end()));

    cout << ans << '\n';


    return 0;
}