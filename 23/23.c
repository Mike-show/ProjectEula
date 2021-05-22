#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX 28123

int AbunCheck(int Number);

int main(void){
    uint64_t Sum = 0;
    uint64_t Sum2 = 0;
    uint64_t Sum3 = 0;
    int NumberSize = sizeof(int);
    
    //list all abuntant number out
    int AbunCount = 0;
    int Check = 0;
    for(int i=1; i<=MAX; i++){
        Check = AbunCheck(i);
        if(Check == 1){
            AbunCount++;
        }
    }
    
    int *Abun = 0;
    Abun = (int *)calloc(AbunCount, NumberSize);
    Check = 0;
    int AbunCount2=0;
    for(int i=1; i<=MAX; i++){
        Check = AbunCheck(i);
        if(Check == 1){
            Abun[AbunCount2] = i;
            AbunCount2++;
        }
    }
    
    //check numbers from greatest to smallest
    for(int Number=MAX; Number>=24; Number--){
        int Remainder = 0;
        
        //find the abuntant number which is smaller than current checking number
        int CountA = 0;
        for(int i=0; i<AbunCount; i++){
            if(Abun[i] <= Number) CountA++;
        }
        
        //find the abuntant numbers which is smaller than 1/2 of current checking number
        int CountB = 0;
        for(int i=0; i<AbunCount; i++){
            if(Abun[i] <= Number/2) CountB++;
        }
        
        //find all the remainder which is less than half of current checking number
        int AdderCheck = 0;
        for(int i=CountA-1; i>=CountB-1; i--){
            Remainder = Number - Abun[i];
            
            //check if there is a abuntant number, which is smaller than 1/2 CN, equals to remainder
            for(int j=0; j<CountB; j++){
                if(Abun[j] == Remainder){
                    AdderCheck = 1;
                    j = CountB;
                }
            }
            if(AdderCheck == 1) i = 0;
        }
        if(AdderCheck == 1) Sum2 += Number;
    }
    
    //referance
    for(int i=1; i<=MAX; i++){
        Sum3 += i;
    }
    
    Sum = Sum3 - Sum2;
    
    printf("%llu\n", Sum);
    printf("%llu\n", Sum2);
    printf("%llu\n", Sum3);
}

int AbunCheck(int Number){
    int SumD = 0;
    for(int i=1; i<=sqrt(Number); i++){
        if(Number%i == 0) {
            SumD += i;
            SumD += Number/i;
        }
    }
    SumD -= Number;
    int root = sqrt(Number);
    if(pow(root, 2) == Number) SumD -= root;
    
    if(SumD > Number)
        return 1;
    else return 0;
}
