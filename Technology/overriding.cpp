#include <iostream>
#include <string>
using namespace std;

class Car{
    public:
        int getHP(){
            return 100;
        }
};

class SportsCar : public Car {
    public:
        int getHP(){
            return 300;
        }
};

int main(){

    SportsCar sc;

    cout << "Horse Power : " << sc.getHP() << endl;
    cout << "Horse Power : " << sc.Car::getHP() << endl;

    return 0;
}