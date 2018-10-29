#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> height) {
    int answer = 0;
    
    for(int i=1; i<height.size(); i++){
        int leftLargest = 0;
        int rightLargest = 0;
        for(int j=0; j<i; j++){
            leftLargest = max(leftLargest, height[j]);
        }
        for(int j=i+1; j<height.size(); j++){
            rightLargest = max(rightLargest, height[j]);
        }
        if(min(leftLargest, rightLargest) - height[i] > 0){
            answer += min(leftLargest, rightLargest) - height[i];
        }
    }
    
    return answer;
}