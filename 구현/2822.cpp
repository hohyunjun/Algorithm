#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<pair<int, int>> input;

    for(int i=0; i<8; i++){
        int score;
        cin >> score;
        input.push_back(make_pair(score, i+1));
    }

    sort(input.begin(), input.end(), greater<pair<int,int>>());

    int sum = 0;
    vector<int> answers;    

    for(int i=0; i<5; i++){
        sum += input[i].first;
        answers.push_back(input[i].second);
    }

    cout << sum << '\n';
    sort(answers.begin(), answers.end());
    for(auto each:answers){
        cout << each << " ";
    }

    return 0;
}