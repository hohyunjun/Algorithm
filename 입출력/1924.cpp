#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){

    int daysOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string yoils[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int daycount =0 , index = 0;
    int x,y;

    scanf("%d", &x);
    scanf("%d", &y);

    while(index+1 != x){
        daycount += daysOfMonth[index++];
    }

    if( y != 1){
        daycount += (y-1);
    }

    cout << yoils[daycount % 7];



    return 0;
}