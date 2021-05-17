#include <stdio.h>
#include <math.h>
#define Range 10000

int Dsum(int Number);

int main(void){
    int SumA = 0;
    for(int n=1; n<=Range; n++){
        int Sum1 = 0, Sum2 = 0;
        Sum1 = Dsum(n);
        if(Sum1 <= Range && Sum1 != n) Sum2 = Dsum(Sum1);
        if(Sum2 == n) {
            printf("%d, %d\n", n, Sum1);
            SumA += n;
            SumA += Sum1;
        }
    }
    SumA /= 2;
    printf("%d\n", SumA);
}

int Dsum(int Number){
    int Sum = 0;
    for(int i=1; i<=sqrt(Number); i++){
        int Div = Number/i;
        if(i*Div == Number){
            Sum += i;
            Sum += Div;
        }
    }
    int Root = sqrt(Number);
    if(pow(Root, 2) == Number) Sum -= Root;
    Sum -= Number;
    return Sum;
}