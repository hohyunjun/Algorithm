#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, k;

    // 국가명, 등수

    cin >> n >> k;

    vector<int> nation[n + 1];

    // 국가 이름에 따른 메달 정보 저장
    for(int i=0; i<n; i++){
        int nationNum;
        cin >> nationNum;
        int g,s,b;
        cin >> g >> s >> b;
        nation[nationNum].push_back(g);
        nation[nationNum].push_back(s);
        nation[nationNum].push_back(b);
    }

    // 국가명, 순위를 pair 형태로 저장
    vector<pair<int,int>> nationRow;

    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(nation[j][0] > nation[i][0]){
                cnt++;
                continue;
            }else if(nation[j][0] < nation[i][0]){
                continue;
            }
            if (nation[j][1] > nation[i][1]){
                cnt++;
                continue;
            }
            else if (nation[j][1] < nation[i][1]){
                continue;
            }
            if (nation[j][2] > nation[i][2]){
                cnt++;
                continue;
            }
            else if (nation[j][2] < nation[i][2]){
                continue;
            }
        }
        nationRow.push_back(make_pair(i, cnt+1));
    }

    for(auto each:nationRow){
        if(each.first == k){
            cout << each.second << '\n';
            break;
        }
    }

    return 0;
}