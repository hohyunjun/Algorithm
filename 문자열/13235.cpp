#include <iostream>
#include <string>
using namespace std;

int isPalindrome(int start, int last, string s)
{
    if (start >= last)
    {
        return 1;
    }
    else if (s[start] != s[last])
    {
        return 0;
    }
    return isPalindrome(start + 1, last - 1, s);
}

int main()
{

    string s;

    cin >> s;

    if(isPalindrome(0, s.length() - 1, s) == 0){
        cout << "false" << '\n';
    }else{
        cout << "true" << '\n';
    }

    return 0;
}