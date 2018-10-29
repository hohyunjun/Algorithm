#include <iostream>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    string cmd;
    int T;
    int pushNum;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> pushNum;
            q.push(pushNum);
        }
        if (cmd == "pop")
        {
            if(q.empty()){
                cout << -1 << endl;
            }else{
                cout << q.front() << endl;
                q.pop();
            }
        }
        if (cmd == "size")
        {
            cout << q.size() << endl;
        }
        if (cmd == "empty")
        {
            if (q.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        if (cmd == "front")
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
        if (cmd == "back")
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}