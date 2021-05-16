#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void){
    int *Array;
    uint64_t SumD = 0;
    int Digit = 3;
    int n;
    int Temp10;
    int Temp100;
    Array = (int *)calloc(Digit, sizeof(int));
    Array[0] = 0;
    Array[1] = 2;
    Array[2] = 1;
    for(n=6; n<=100; n++){
        for(int i=0; i<Digit; i++){
            Array[i] *= n;
        }
        for(int i=0; i<Digit-1; i++){
            Temp10 = Array[i]/10;
            Array[i] = Array[i]-Temp10*10;
            Array[i+1] += Temp10;
        }
        if((Array[Digit-1]/100) != 0){
            Digit += 2;
            Array = (int *)realloc(Array, Digit*sizeof(int));
            Temp100 = Array[Digit-3]/100;
            Temp10 = (Array[Digit-3]-Temp100*100)/10;
            Array[Digit-3] = Array[Digit-3]-Temp100*100-Temp10*10;
            Array[Digit-2] += Temp10;
            Array[Digit-1] += Temp100;       
        }
        else {
            if((Array[Digit-1]/10) != 0){
            Digit++;
            Array = (int *)realloc(Array, Digit*sizeof(int));
            Temp10 = Array[Digit-2]/10;
            Array[Digit-2] = Array[Digit-2]-Temp10*10;
            Array[Digit-1] += Temp10;
            }
        }
    }
    for(int i=Digit-1; i>-1; i--){
        //printf("%d ", Array[i]);
        SumD += Array[i];
    }
    printf("%llu\n", SumD);
}