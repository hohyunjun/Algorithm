#include <stdio.h>

int main(){

    while(1){
        // 초기 입력값 변수에 저장
        int year, month, day, anniversary;
        // 각 월별 일 수를 저장하는 배열. index는 0 부터 시작
        int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        printf("Input year : ");
        scanf("%d", &year);
        // Exception Handling for year
        if (year < 0){
            printf("Wrong number!\n");
            continue;
        }else if (year == 0){
            return 0;
        }

        // LeapYear 판별 : Leap year 일경우 2월의 일수를 29일까지, 아닐경우 28일까지
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
            daysOfMonth[1] = 29;
        }

        printf("Input month : ");
        scanf("%d", &month);
        // Exception Handling for month
        if(month == 0){
            return 0;
        }else if (month < 1 || month > 12){
            printf("Wrong number!\n");
            continue;
        }

        printf("Input day : ");
        scanf("%d", &day);
        // Exception Handling for day
        if (daysOfMonth[month - 1] < day || day < 1){
            printf("Wrong number!\n");
            continue;
        }

        printf("Input anniversary : ");
        scanf("%d", &anniversary);

        anniversary -= 1; // 오늘부터 1일을 세기 위해서 하루빼고시작

        // anniversary가 0 이 아닐때 Loop 수행
        while (anniversary){
            anniversary -= 1;
            day += 1;
            // 월의 정해진 날짜를 넘어갔을 때, 월을 + 1 하고, day는 1로
            if (day > daysOfMonth[month - 1]){
                month += 1;
                // month 가 12월을 넘어가면, year 를 + 1 하고, month 를 1 로
                if (month > 12){
                    year += 1;
                    // LeapYear 판별 : Leap year 일경우 2월의 일수를 29일까지, 아닐경우 28일까지
                    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
                        daysOfMonth[1] = 29;
                    }
                    else{
                        daysOfMonth[1] = 28;
                    }
                    month = 1;
                }
                day = 1;
            }
        }

        printf("%d %d %d\n", year, month, day);
    }

    return 0;
}