#include <cstdio>

void isAscending(){

    for(int i=0; i<7; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp!=2+i){
            printf("mixed");
            return;
        }
    }
    printf("ascending");

}

void isDescending(){

    for (int i = 0; i < 7; i++){
        int tmp;
        scanf("%d", &tmp);
        if (tmp != 7-i){
            printf("mixed");
            return;
        }
    }
    printf("descending");
}


int main(){

    int num;

    scanf("%d", &num);

    if(num==1){
        isAscending();
    }else if(num==8){
        isDescending();
    }else{
        printf("mixed");
    }



    return 0;
}