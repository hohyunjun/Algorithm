#include <cstdio>

int main(){

    int t;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int numCourse;
        scanf("%d", &numCourse);
        int hakjum = 0;
        float pyungjum = 0;
        for(int i=0; i<numCourse; i++){
            int a;
            float b;
            scanf("%d", &a);
            scanf("%f", &b);
            hakjum += a;
            pyungjum += a * b;
        }
        printf("%d ", hakjum);
        printf("%.1f\n", pyungjum / (float)hakjum);
    }



    return 0;
}