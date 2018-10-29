#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<int> nums, int target) {
    bool answer = false;
    
    map<int, int> m;
    
    for(auto each:nums){
        m[each] += 1;
    }
    
    for(auto each:nums){
        int findNum = target - each;
        m[findNum] -= 1;
        if(m[findNum] >= 0){
            answer = true;  
            break;
        } 
    }
    
    return answer;
}