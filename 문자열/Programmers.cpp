#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> height)
{
    int answer = 0;
    int n = height.size();
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = -1, rightMax = -1;
        if (i == 4)
        {
            cout << height[i - 1] << " " << height[i] << " " << height[i + 1] << "\n\n";
        }
        leftMax = height[i - 1];
        for (int j = i - 2; j >= 0; j--)
            leftMax = max(leftMax, height[j]);
        rightMax = height[i + 1];
        for (int j = i + 2; j < n; j++)
            rightMax = max(rightMax, height[j]);
        if (min(rightMax, leftMax) - height[i] > 0)
        {
            answer += min(rightMax, leftMax) - height[i];
        }
    }
    return answer;
}

int solution2(vector<int> height){

    int ans = 0;
    for(int i=0; i<height.size(); i++){
        int leftmax = 0;
        int rightmax = 0;
        for(int j=i-1; j>=0; j--){
            leftmax = max(leftmax, height[j]);
        }
        for(int j=i+1; j<height.size(); j++){
            rightmax = max(rightmax, height[j]);
        }
        if(min(rightmax, leftmax) - height[i] > 0){
            ans += min(rightmax, leftmax) - height[i];
        }
    }
    return ans;
}

int main(){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << solution2(height) << endl;

    return 0;
}