#include <cstdio>

void draw(int right, int down){
    char blankR = ' ';
    char blankD = '\n';
    while(right){
        printf(blakR);
        right--;
    }
    printf("  *  \n");
    printf(" * * \n");
    printf("*****\n");
}

int main(){

    draw(3,0);
    draw(0,3);
    draw(6,0);


    return 0;
}