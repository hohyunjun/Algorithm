#include <iostream>
#include <vector>
using namespace std;

bool check1[100000];
bool check2[100000];

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

    // sorting
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(playList[i] > playList[j]){
                swap(playList[i],playList[j]);
            }
        }
    }

    // 전체 합이 lt보다 작은 경우, 모든 곡을 들을 수 있다.
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += playList[i];
    }

    if(sum <= lt){
        answer = n;
    }else{
        // 처음부터 듣는 경우와 마지막 1분부터 듣는 경우 중 큰 것을 답으로
        int from_first = lt, from_last = lt;
        int from_first_ans = 0, from_last_ans = 0;

        for(int i=0; i<n; i++){
            if(from_first > 0){
                check1[i] = true;
            }else{
                break;
            }
            from_first -= playList[i];
        }

        for(int i=0; i<n; i++){
            if(check1[i]){
                from_first_ans++;
            }
        }

        // 마지막 1분부터 듣는 경우
        from_last -= 1;
        check2[n-1] = true;

        for(int i=0; i<n-1; i++){
            if(from_last > 0){
                check2[i] = true;
            }else{
                break;
            }
            from_last -= playList[i];
        }

        for(int i=0; i<n; i++){
            if(check2[i]){
                from_last_ans++;
            }
        }

        answer = max(from_first_ans, from_last_ans);
    }

    cout << answer << '\n';

    return 0;
}