#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size()-1; i++){
        int count = 0;
        for(int j=i; j<prices.size()-1; j++){
            if(prices[j] >= prices[i]){
                count++;
            }else{
                break;
            }
        }
        answer.push_back(count);
    }
    
    answer.push_back(0);
    
    
    return answer;
}