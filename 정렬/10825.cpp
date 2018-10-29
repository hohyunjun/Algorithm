#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    int korean;
    int english;
    int math;
    string name;
};

bool cmp(const Student &u, const Student &v){
    if(u.korean > v.korean){
        return true;
    }else if(u.korean == v.korean){
        if(u.english == v.english){
            if(u.math == v.math){
                return u.name < v.name;
            }else{
                return u.math > v.math;
            }
        }else{
            return u.english < v.english;
        }
    }
    return false;
}

int main(){

    int N;

    cin >> N;

    Student students[N];

    for(int i=0; i<N; i++){
        cin >> students[i].name;
        cin >> students[i].korean;
        cin >> students[i].english;
        cin >> students[i].math;
    }

    sort(students, students+N, cmp);

    for(int i=0; i<N; i++){
        cout << students[i].name << '\n';
    }

    return 0;
}