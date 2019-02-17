#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, k;
    int ans = 0;

    cin >> n >> k;

    if(k<5){
        cout << ans << '\n';
    }else{
        vector<string> str;
        vector<int> checkStr;

        // 반드시 필요한 단어들은 따로 계산해서 이후에는 더해주기만 한다.
        string necessary = "antatica";
        int necessaryCheck = 0;
        for(int i=0; i<necessary.length(); i++){
            necessaryCheck = necessaryCheck | (1<<(necessary[i] - 'a'));
        }

        for(int i=0; i<n; i++){
            string tmp;
            cin >> tmp;
            str.push_back(tmp);
        }

        // 알파벳을 bitmask 형태로 나타내서 숫자 형태로 저장한다.(checkStr 배열에 저장된 숫자는 a,c,i,n,t를 제외한 숫자이다.)
        for(int i=0; i<str.size(); i++){
            int checkSum = 0;
            for(int j=4; j<str[i].length()-4; j++){
                if(str[i][j] == 'a' || str[i][j] == 'c' || str[i][j] == 'i' || str[i][j] == 'n' || str[i][j] == 't') continue;
                checkSum = checkSum | ( 1 << (str[i][j] - 'a') );
            }
            checkStr.push_back(checkSum);
        }

        // a,c,i,n,t를 제외한 21개의 알파벳 중 k-5개를 배우는 모든 경우의 수를 따져본다.
        if(k==5){ // k가 5인 경우는 a,c,i,n,t를 배우는 경우가 최대 경우의 수이다.
            int know = 0;
            vector<int> tmpCheck = checkStr;
            for(int i=0; i<tmpCheck.size(); i++){
                if(tmpCheck[i] == 0) know++;
            }
            ans = max(know, ans);
        }else{
            // a,c,i,n,t 를 제외한 알파벳 배열
            vector<char> alphabet;
            for(int i=0; i<26; i++){
                if(i == 'a' - 'a') continue;
                if(i == 'i' - 'a') continue;
                if(i == 'c' - 'a') continue;
                if(i == 'n' - 'a') continue;
                if(i == 't' - 'a') continue;
                alphabet.push_back(i + 'a');
            }
        
            for(int i=0; i< (1<<21); i++){
                int cnt = 0;
                for(int j=0; j<21; j++){
                    if( i & (1<<j) ) cnt++;
                }
                if(cnt != k-5) continue;
                vector<int> tmpCheck = checkStr;
                for(int j=0; j<21; j++){
                    if(i & (1<<j) ){
                        for(int l=0; l<tmpCheck.size(); l++){
                            tmpCheck[l] = tmpCheck[l] & ~(1<<(alphabet[j] - 'a'));
                        }
                    }
                }
                int know = 0;
                for(int j=0; j<tmpCheck.size(); j++){
                    if(tmpCheck[j] == 0) know++;
                }
                ans = max(know, ans);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}