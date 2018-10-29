#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[] = {1,2,3,4,5};
    int second[] = {2,1,2,3,2,4,2,5};
    int third[] = {3,3,1,1,2,2,4,4,5,5};
    int fa = 0, sa = 0 , ta = 0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == first[i%5]){
            fa++;
        }
        if(answers[i] == second[i%8]){
            sa++;
        }
        if(answers[i] == third[i%10]){
            ta++;
        }
    }
    
    int best = max(fa,sa);
    best = max(best, ta);
    
    if(fa == best){
        answer.push_back(1);
    }
    if(sa == best){
        answer.push_back(2);
    }
    if(ta == best){
        answer.push_back(3);
    }
    return answer;
}