#include <iostream>
#include <stack>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> s;

    s.push('(');

    cout << s.top() << endl;



    return 0;
}