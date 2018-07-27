#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> odd;
    int n;
    int sum = 0;
    int min = 0;

    for(int i=0; i<7; i++){
        cin >> n;
        if(n%2){
            odd.push_back(n);
        }
    }

    if(odd.size() == 0){
        cout << -1 << endl;
    }else{
        for (int i = 0; i < odd.size(); i++){
            sum += odd[i];
        }
        min = odd[0];
        for(int i=0; i<odd.size(); i++){
            if(odd[i]<min){
                min = odd[i];
            }
        }
        cout << sum << endl;
        cout << min << endl;
    }




    return 0;
}