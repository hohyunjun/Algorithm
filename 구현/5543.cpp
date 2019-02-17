#include <iostream>
using namespace std;

int main(){

    int sang, jung, ha;
    int coke, cidar;

    cin >> sang >> jung >> ha >> coke >> cidar;

    int minBurger = sang;
    int minBeverage = coke;    

    minBurger = min(minBurger, jung);
    minBurger = min(minBurger, ha);

    minBeverage = min(minBeverage, cidar);

    cout << minBurger + minBeverage - 50 << '\n';

    return 0;
}