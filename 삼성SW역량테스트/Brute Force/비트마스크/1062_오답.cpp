#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, k;
    int ans = 0;

    cin >> n >> k;

    if(k<5){
        cout << 0 << '\n';
    }else{
        vector<string> str;
        vector<char> unqChar;
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

        // 알파벳을 bitmask 형태로 나타내서 숫자 형태로 저장한다.
        for(int i=0; i<str.size(); i++){
            int checkSum = necessaryCheck;
            for(int j=4; j<str[i].length()-4; j++){
                if(str[i][j] == 'a' || str[i][j] == 'c' || str[i][j] == 'i' || str[i][j] == 'n' || str[i][j] == 't') continue;
                unqChar.push_back(str[i][j]);
                checkSum = checkSum | ( 1 << (str[i][j] - 'a') );
            }
            checkStr.push_back(checkSum);
        }

        sort(unqChar.begin(), unqChar.end());
        unqChar.erase(unique(unqChar.begin(), unqChar.end()), unqChar.end());

        vector<int> tmpChecker = checkStr;
        for(int j=0; j<tmpChecker.size(); j++){
            tmpChecker[j] = tmpChecker[j] & ~(1 << ('a' - 'a'));
            tmpChecker[j] = tmpChecker[j] & ~(1 << ('c' - 'a'));
            tmpChecker[j] = tmpChecker[j] & ~(1 << ('i' - 'a'));
            tmpChecker[j] = tmpChecker[j] & ~(1 << ('n' - 'a'));
            tmpChecker[j] = tmpChecker[j] & ~(1 << ('t' - 'a'));
        }
        int preKnow = 0;
        for(int j=0; j< tmpChecker.size(); j++){
            if(tmpChecker[j] == 0) preKnow++;
        }
        ans = max(ans, preKnow);

        // 중복이 제거된 알파벳 중에서 K-5개만 배운다.(a,c,i,n,t는 무조건 배우는 것으로 가정)
        for(int i=0; i < (1<<(unqChar.size())); i++){
            int cnt = 0;
            for(int j=0; j<unqChar.size(); j++){
                if( i & (1<<j) ){
                    cnt++;
                }
            }
            if(cnt > k-5) continue;

            // unqChar 중에서 K-5개를 선택했을 경우
            int know = 0;
            vector<int> tmpChecker = checkStr;
            // 5개의 알파벳은 무조건이라고 가정하므로 빼주고 시작
            for(int j=0; j<tmpChecker.size(); j++){
                tmpChecker[j] = tmpChecker[j] & ~(1 << ('a' - 'a'));
                tmpChecker[j] = tmpChecker[j] & ~(1 << ('c' - 'a'));
                tmpChecker[j] = tmpChecker[j] & ~(1 << ('i' - 'a'));
                tmpChecker[j] = tmpChecker[j] & ~(1 << ('n' - 'a'));
                tmpChecker[j] = tmpChecker[j] & ~(1 << ('t' - 'a'));
            }
            for(int j=0; j<unqChar.size(); j++){
                // j번째 unqChar이 i에 존재할 경우
                if( i & (1<<j) ){
                    for(int l=0; l<tmpChecker.size(); l++){
                        tmpChecker[l] = tmpChecker[l] & ~(1 << (unqChar[j] - 'a'));
                    }
                }
            }
            for(int j=0; j< tmpChecker.size(); j++){
                if(tmpChecker[j] == 0) know++;
            }
            ans = max(ans, know);
        }

        cout << ans << '\n';
        
    }


    return 0;
}