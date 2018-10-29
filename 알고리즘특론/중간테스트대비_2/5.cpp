#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    map<int, int> m;
    sort(numbers.begin(), numbers.end());
    
    
    for(auto each:numbers){
        m[each] += 1;
    }
    
    int minus = 0;
    int plus = 0;
    for(auto each:m){
        if(each.second > 0){
            each.second -= 1;
            
        }
    }
    
    return answer;
}