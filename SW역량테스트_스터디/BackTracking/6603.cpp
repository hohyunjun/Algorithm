#include <cstdio>
#include <vector>
using namespace std;

int nums[13];
// k개의 수 중에서 6개를 뽑는 dfs

void solve(int index, vector<int> selected, int k){
    if(selected.size() == 6){
        for(auto each:selected){
            printf("%d ", each);
        }
        printf("\n");
        return;
    }
    if(index >= k){
        return;
    }
    selected.push_back(nums[index]);
    solve(index+1, selected, k);
    selected.pop_back();
    solve(index+1, selected, k);
}

int main(){


    while(true){

        int k;

        scanf("%d", &k);

        if(k == 0) break;

        for(int i=0; i<k; i++){
            scanf("%d", &nums[i]);
        }

        vector<int> selected;

        solve(0, selected, k);
        printf("\n");
    }

    return 0;
}