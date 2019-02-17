#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

/*
    BOJ 1339 단어 수학


*/
char modify[256];
int main(){

    int n;

    cin >> n;

    // 주어진 단어들을 저장할 벡터
    vector<string> strings;

    //일단 unique한 알파벳을 다 뽑아낸다
    string tmp = "";
    for(int i=0; i<n; i++){
        string tmp2;
        cin >> tmp2;
        strings.push_back(tmp2);
        tmp += tmp2;
    }

    vector<char> alpha;
    for(int i=0; i<tmp.length(); i++){
        alpha.push_back(tmp[i]);
    }

    sort(alpha.begin(), alpha.end());
    alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());


    // 정답을 저장할 변수
    long long int ans = -0x7FFFFFFF;

    // 각각의 unique한 알파벳에 숫자를 할당한다.
    // 최댓값이므로 순열은 큰 수들만 포함하여 돌린다.
    int k = alpha.size(); // k는 unique한 알파벳의 개수
    vector<int> nums;
    for(int i=0; i<k; i++){
        nums.push_back(9-i);
    }

    do{
        // 각각의 unique한 alphabet에 숫자를 사상시킨다.
        for(int i=0; i<k; i++){
            modify[alpha[i]] = nums[i];
        }

        long long int localAns = 0;
        // 단어 계산
        for(int i=0; i<strings.size(); i++){
            int now = 0;
            for(char x : strings[i]){
                now = now * 10 + int(modify[x]);
            }
            localAns += now;
        }

        ans = max(ans, localAns);

    }while(prev_permutation(nums.begin(), nums.end()));

    cout << ans << '\n';

    return 0;
}