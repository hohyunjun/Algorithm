#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> map;
    
    for(auto each:participant){
        map[each] += 1;
    }
    
    for(auto each:completion){
        map[each] -= 1;
    }
    
    for(auto each:map){
        if(each.second == 1){
            answer = each.first;
        }
    }
    
    
    return answer;
}