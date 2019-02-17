#include <iostream>
using namespace std;

int main(){

    int t;

    cin >> t;

    for(int i=0; i<t; i++){
        int hp, mp, atk, def;
        cin >> hp >> mp >> atk >> def;
        int hpv, mpv, atkv, defv;
        cin >> hpv >> mpv >> atkv >> defv;
        hp += hpv;
        mp += mpv;
        atk += atkv;
        def += defv;

        if(hp < 1){
            hp = 1;
        }

        if(mp < 1){
            mp = 1;
        }

        if(atk <0){
            atk = 0;
        }

        cout << 1*hp + 5*mp + 2*atk + 2*def << '\n';
    }



    return 0;
}