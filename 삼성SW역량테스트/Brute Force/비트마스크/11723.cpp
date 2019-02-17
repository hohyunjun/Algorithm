#include <cstdio>
#include <cstring>
using namespace std;

char op[111];
int main(){

    int S = 0;
    int opNum;

    scanf("%d", &opNum);

    for(int i=0; i<opNum; i++){
        
        scanf("%s", op);

        int x;

        if(strcmp(op, "all") && strcmp(op, "empty")){
            scanf("%d", &x);
        }

        // 0~n-1 범위이므로 x를 -1한 값을 비트마스크 형태로 저장한다.
        if(!strcmp(op, "add")){
            S = S | (1 << (x-1));
        }else if(!strcmp(op, "remove")){
            S = S & ~(1 << (x-1));
        }else if(!strcmp(op, "check")){
            if( (S & (1 << (x-1))) == 0){
                printf("%d\n", 0);
            }else{
                printf("%d\n", 1);
            }
        }else if(!strcmp(op, "toggle")){
            S = S ^ (1 << (x-1));
        }else if(!strcmp(op, "all")){
            S = (1 << (20)) - 1;
        }else if(!strcmp(op, "empty")){
            S = 0;
        }
        
    }



    return 0;
}