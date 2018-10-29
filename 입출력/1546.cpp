#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

    int N;
    
    scanf("%d", &N);

    double score[N];
    double newScore[N];

    for(int i=0; i<N; i++){
        scanf("%lf", &score[i]);
    }

    sort(score, score + N);

    for(int i=0; i<N; i++){
        newScore[i] = score[i] / score[N-1] * 100;
    }

    double avr, sum = 0;

    for(int i=0; i<N; i++){
        sum += newScore[i];
    }

    avr = sum / N;

    printf("%lf", avr);


    return 0;
}