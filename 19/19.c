#include <stdio.h>

int main(void){
    int Rest = 0;
    int LeapDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int NoLeapDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Sum = 365;
    int Count = 0;
    int First = 0;
    for(int Year=1901; Year<=2000; Year++){
        if(Year%4 == 0){
            for(int i=0; i<12; i++){
                Sum += LeapDays[i];
                if(Sum%7 == 6) Count++;
            }
        }
        else{
            for(int i=0; i<12; i++){
                Sum += NoLeapDays[i];
                if(Sum%7 == 6) Count++;
            }
        }
    }

    if(Sum%7 == 6) Count--;
    printf("%d ", Count);
}