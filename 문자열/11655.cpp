#include <cstdio>
using namespace std;

int main(){

    char input[102];
    char output[102] = {};
    fgets(input, 102, stdin);

    for(int i=0; input[i]; i++){
        if(input[i]>= 'A' && input[i] <= 'Z'){
            int tmp = int(input[i]) + 13;
            if(tmp > int('Z')){
                tmp = tmp - int('Z') + int('A') - 1;
            }
            output[i] = char(tmp);
        }else if(input[i] >= 'a' && input[i] <= 'z'){
            int tmp = int(input[i]) + 13;
            if(tmp > int('z')){
                tmp = tmp - int('z') + int('a') - 1;
            }
            output[i] = char(tmp);
        }else{
            output[i] = input[i];
        }
    }

    printf("%s", output);



    return 0;
}