#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<int> nums, int target) {
    bool answer = false;
    map <int, int> _map;
    
    for(auto each : nums){
        if(_map.find(each) == _map.end()){ // map에 nums 내부 숫자가 존재하지 않을 경우
            _map[each] = 0;
        }
        _map[each]+=1; // 숫자의 개수를 세어주기 위해서 추가
    }
    
    for(auto each : nums){
        int gap = target - each;
        if(_map.find(gap) != _map.end()){ // gap 값이 map에 존재할경우
            if(gap == each){ // 만일 gap값이 each값과 같을경우, nums에 같은 수가 두번 존재할 경우만 true이다.
                if(_map[gap] > 1){
                    answer = true;   
                    break;
                }
            }
            answer = true;
            break;
        }
    }
    
    return answer;
}