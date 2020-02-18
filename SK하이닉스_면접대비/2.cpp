#include <iostream>
#include <vector>
using namespace std;

/*
    2번

    1. i번째 노래의 마지막 1분 전부터 듣기 시작한다고 가정하여, listening time을 줄여가면서 최대한 노래를 듣는다.
    2. 1번에서 i번째 노래부터 시작했을 때 들을 수 있는 노래의 최대값을 vector에 저장한다.
    3. 저장된 vector의 값들 중에서 가장 큰 값을 answer로 반환한다.

*/

int main(){

    int n; // playlist의 길이 n

    cin >> n;

    vector<int> playList(n);
    int lt; // listening time
    int answer = 0;

    for(int i=0; i<n; i++){
        cin >> playList[i];
    }

    cin >> lt;

    vector<int> possible(n);

    for(int i=0; i<n; i++){
        // 노래를 들었는지 듣지 않았는지를 체크할 배열
        bool check[100000] = {false};
        int tmplt = lt - 1; // i번째 노래의 마지막 1분을 들었다.
        check[i] = true;

        // i+1번째부터 노래 듣기 시작
        for(int j=i+1; j<i+n; j++){
            // lt이 남아 있으면 노래를 들을 수 있다.
            if(tmplt > 0){
                check[j%n] = true;
            }else{
                break;
            }
            tmplt -= playList[j%n];
        }

        // 들은 노래 개수를 세서 저장한다.
        int cnt = 0;
        for(int k=0; k<n; k++){
            if(check[k]){
                cnt++;
            }
        }

        possible[i] = cnt;

    }

    for(auto each:possible){
        cout << each << " ";
    }

    cout << '\n';

    for(int i=0; i<n; i++){
        answer = max(answer, possible[i]);
    }

    cout << answer << '\n';

    return 0;
}