#include <stdio.h>
#include <math.h>

#define BITSIZE 6000

int Divide(int d, int a[BITSIZE]);
int CircleCount(int a[BITSIZE]);
void ArrayReset(int a[BITSIZE]);

int main(int argc, const char * argv[]) {
    int a[BITSIZE] = {0};
    int MaxCircle = 1;
    int MaxCircleNum = 1;
    int CircleJudge = 0;
    for(int i=1; i<1000; i++){
        int Temp = 1;
        CircleJudge = Divide(i, a);   //divde 1 by i, store the result into an array
        if(CircleJudge == 1) {
            Temp = CircleCount(a);
            if(Temp > MaxCircle){
                MaxCircle = Temp;
                MaxCircleNum = i;
            }
        }
        ArrayReset(a);
    }
    
    printf("Number %d has a max circle whose length is %d\n", MaxCircleNum, MaxCircle);
    return 1;
}

int Divide(int d, int a[BITSIZE]){
    int Quotient, Remainder = 1, Numerator = 1, bit = 0, Judge = 1;
    do{
        Quotient = Numerator / d;
        Remainder = Numerator % d;
        Numerator = Remainder * 10;
        a[bit] = Quotient;
        bit++;
    }while(bit<BITSIZE && Remainder != 0);
    if(Remainder == 0) Judge = 0;
    return Judge;
}

int CircleCount(int a[BITSIZE]){
    int CircleDigit = 5;
    int CircleConfirm;
    do{
        CircleConfirm = 1;
        for(int i=1; i<=CircleDigit && CircleConfirm != 0; i++){
            if(a[BITSIZE-i] != a[BITSIZE-(i+CircleDigit)] || a[BITSIZE-i] != a[BITSIZE-(i+2*CircleDigit)]) CircleConfirm = 0;
        }
        if(CircleConfirm == 0) CircleDigit++;
    }while(CircleConfirm == 0 && CircleDigit <= BITSIZE/3);
    
    return CircleDigit;
}

void ArrayReset(int a[BITSIZE]){
    for(int i=0; i<BITSIZE; i++){
        a[i] = 0;
    }
}
