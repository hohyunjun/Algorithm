#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nums[9];
    int biggest=0;

    for(int i=0; i<9; i++){
        cin >> nums[i];
    }

    for(int i=0; i<9; i++){
        biggest = max(biggest, nums[i]);
    }

    int index;

    for(int i=0; i<9; i++){
        if(biggest == nums[i]){
            index = i;
            break;
        }
    }

    cout << biggest << endl;
    cout << index+1 << endl;

    return 0;
}