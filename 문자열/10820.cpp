#include <cstdio>
using namespace std;

int main(){

    char input[102];
    while(fgets(input, 102, stdin)){
        int small = 0, big = 0, num = 0, space = 0;
        for(int i=0; input[i]; i++){
            if(int(input[i])>=97 && int(input[i]) <=122 ){
                small++;
                continue;
            }else if(int(input[i])>=65 && int(input[i])<=90){
                big++;
                continue;
            }else if(input[i] == ' '){
                space++;
                continue;
            }else if(input[i] != '\n'){
                num++;
            }
        }
        printf("%d %d %d %d\n", small, big, num, space);
    }

    return 0;
}