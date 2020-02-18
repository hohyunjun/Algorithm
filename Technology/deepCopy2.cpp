#include <iostream>
#include <string.h>
using namespace std;

class Student{

    char *name;
    int number;

    public:
        // 기본 생성자
        Student(const char *pn, int n){
            name = new char[strlen(pn) + 1];
            strcpy(name, pn);
            number = n;
        }
        ~Student(){
            delete [] name;
        }

        // Deep Copy를 위한 복사 생성자
        Student(Student& s){
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
            number = s.number;
        }
        
        // 이름을 설정해주는 함수
        void setName(const char *pn){
            delete[] name;
            name = new char[strlen(pn) + 1];
            strcpy(name, pn);
        }

        void print(){
            cout << "이름 : " << name << " ";
            cout << "학번 : " << number << endl;
        }
};

int main(){

    Student s1("Jeon", 20130000);
    Student s2(s1); // 디폴트 복사 생성자 호출

    s1.print();
    s2.print();

    s1.setName("Kim"); // s1의 이름만 kim 으로 바꿈

    s1.print();
    s2.print();

    return 0;
}