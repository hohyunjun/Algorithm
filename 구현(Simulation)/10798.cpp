#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string a,b,c,d,e;

    cin >> a >> b >> c >> d >> e;

    string ans = "";

    for(int i=0; i<15; i++){
        if (a.length() > i)
        {
            ans += a[i];
        }
        if(b.length()>i){
            ans += b[i];
        }
        if(c.length()>i){
            ans += c[i];
        }
        if (d.length() > i)
        {
            ans += d[i];
        }
        if (e.length() > i)
        {
            ans += e[i];
        }
    }

    cout << ans << endl;


    return 0;
}