#include <iostream>
#include <string.h>
using namespace std;

/*
    shallow copy & deep copy
*/

class myClass{
    private:
        int a;
        char *name;

    public:
        myClass(){ // constructor with no argument
        }

        myClass(int _a, const char*_name){
            a = _a;
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }

        myClass(const myClass &T){ // deep Copy!!
            a = T.a;
            name = new char[strlen(T.name) + 1];
            strcpy(name, T.name);
        }

        void ChangeA(int _a){
            a = _a;
        }

        void ChangeChar(const char* _name){
            strcpy(name, _name);
        }
        
        void showData(){
            cout << a << '\n';
            cout << name << endl;
        }

        ~myClass(){
            delete[] name;
        }
};

int main(){

    myClass A(4, "spider"); // myClass A = myClass(3);
    myClass B(A); 
    A.showData();
    B.showData();

    A.ChangeA(1);
    cout << "After Changing A's int value" << '\n';
    A.showData();
    B.showData();

    A.ChangeChar("sasas");
    cout << "After Changing A's name value" << '\n';

    A.showData();
    B.showData();
    return 0;
}