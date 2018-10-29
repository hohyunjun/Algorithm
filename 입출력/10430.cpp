#include <iostream>
using namespace std;

int main()
{

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, b, c;

    cin >> a >> b >> c;

    cout << (a + b)%c << endl;
    cout << (a%c+b%c)%c << endl;
    cout << (a * b)%c << endl;
    cout << (a%c * b%c)%c << endl;

    return 0;
}