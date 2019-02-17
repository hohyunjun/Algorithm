#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{

    vector<int> s;

    s.push_back(1);
    s.push_back(1);
    s.push_back(2);
    s.push_back(2);

    s.erase(unique(s.begin(), s.end()), s.end());

    for(auto each:s){
        cout << each << " ";
    }

    return 0;
}