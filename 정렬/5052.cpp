#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*
    BOJ 5052. 전화번호 목록
    1. 첫번째 자리수를 기준으로 HashMap을 구성한다. map<int, vector<string>>
    2. Hashmap 내부 Vector String 들을 정렬한다.
    3. Vector String 내부에서 비교하면서 일관성 없으면 바로 return

    ---> 위의 방법으로 푼 결과, 50%에서 시간초과
    1. 새로운 전화번호가 들어오면, 한자리, 두자리, ... 열번째 자리까지 차례로 검사해서 이미 존재하는 번호인지 체크
    2. 이미 존재하는 번호라면 NO 출력
    3. 존재하지 않는 번호라면 map 에 check.  map<string, bool>
*/

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;

    cin >> t;

    while(t--){
        // m[n]에는 n이라는 번호가 들어왔는지 아닌지 체크
        map<string, bool> m;
        bool ans = true;
        int num;
        cin >> num;
        vector<string> book(num);
        for(int i=0; i<num; i++){
            cin >> book[i];
        }

        //길이가 짧은 것부터 map에 넣기 위해 정렬한다.
        sort(book.begin(), book.end());

        // length -1 까지 검사
        for(int i=0; i<book.size(); i++){
            int len = book[i].length();
            for(int j=1; j<=len-1; j++){
                if(m[book[i].substr(0,j)]){
                    ans = false;
                    break;
                }
            }
            if(ans){
                m[book[i]] = true;
            }
            if(!ans) break;
        }


        if(!ans){
            cout << "NO\n"; 
        }else{
            cout << "YES\n";
        }

    }


    return 0;
}