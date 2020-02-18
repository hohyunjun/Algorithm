#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

/*
    4번.
     최대 8자리의 숫자 배열이 주어지고, K라는 값이 주어진다. 
     숫자 배열의 각 원소를 1대 1로 swap하여 최소 횟수의 swap으로 모든 인접 원소 간 차이값이 K이하가 되도록 할 때,
     최소 횟수 answer를 구하라.
     K이하로 만드는 것이 불가능할 경우, answer는 -1을 반환한다.
*/

/*
    1. 숫자 배열에 대한 순열 조합을 모두 구해보고, 그 중에서 조건을 만족하는 순열을 저장한다.
    2. 저장된 각각의 순열에 대해서 원래 배열으로부터 몇 번의 최소 swap을 통해 해당 순열이 만들어지는지를 구하고, ans를 update한다.
    ** 최소 swap을 구하는 방법
     - 첫번째 요소를 배열의 값으로, 두번째 요소를 배열 인덱스로 가지는 vector<pair<int,int>> 를 만든다.
     - 위에서 만든 vector에서 swap을 연산할 최초 배열 input과 pair의 first 값이 같도록 vector를 정렬한다.
     - i=0 부터 배열의 크기만큼 돌면서 pair.second(배열의 인덱스) 와 i 값이 같지 않을 경우, 요소가 원래 배열의 인덱스로 돌아갈 때까지 swapping을 계속 진행하면서 swap횟수를 샌다.
*/

// 입력값
int k, n;
vector<int> input(MAX);
bool visit[MAX];
vector<int> a(MAX);
vector<vector<int>> satisfying;

// 정답
int ans = -1;

// 모든 인접 원소 간 차이값이 K 이하인지 확인하는 함수
bool check(vector<int> b){
    for(int i=0; i<n-1; i++){
        if(abs(b[i] - b[i+1]) > k) return false;
    }
    return true;
}

// input 벡터에 대해 순열을 돌린 이후, 순열을 돌린 벡터가 조건을 만족할 경우 satisfying 벡터에 넣어준다.
void permut(int index, int m){
    if(index == m){
        if(check(a)){
            satisfying.push_back(a);
        }
        return;
    }
    for(int i=0; i<m; i++){
        if(visit[i]) continue;
        a[index] = input[i];
        visit[i] = true;
        permut(index+1, m);
        visit[i] = false;
    }
}

// 최소스왑을 찾는 함수
void findMinSwap(vector<int> arr){

    vector<pair<int,int>> vec(n);

    for(int i=0; i<n; i++){
        vec[i].first = arr[i];
        vec[i].second = i;
    }

    vector<pair<int,int>> vec2(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(input[i] == vec[j].first){
                vec2[i] = vec[j];
                break;
            }
        }
    }

    int ret = 0;

    for(int i=0; i<n; i++){
        if(vec2[i].second == i){
            continue;
        }else{
            swap(vec2[i].first, vec2[vec2[i].second].first);
            swap(vec2[i].second, vec2[vec2[i].second].second);
        }

        if(i != vec2[i].second){
            --i;
        }

        ret++;
    }

   if(ans == -1){
       ans = ret;
   }else{
       ans = min(ans, ret);
   }

    return;
}

int main(){

    cin >> k >> n;

    a.resize(n);
    input.resize(n);

    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    // 모든 순열을 구해보고, 조건을 만족하는 순열을 저장한다.
    permut(0, n);

    for(int i=0; i<satisfying.size(); i++){
        findMinSwap(satisfying[i]);
    }

    cout << ans << '\n';

    return 0;
}