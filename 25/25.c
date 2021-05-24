#include <stdio.h>
#include <stdint.h>
#define SIZE 1000
#define DIGIT 1000

int main(int argc, const char * argv[]) {
    int a[4][SIZE] = {0};
    a[0][0] = 1;
    a[1][0] = 1;
    uint64_t Count = 2;
    int CurrentDigit = 1;
    do{
        for(int i=0; i<CurrentDigit; i++){
            a[2][i] = a[0][i] + a[1][i];
        }
        
        for(int i=0; i<CurrentDigit-1; i++){
            if(a[2][i] > 9){
                a[3][i] = a[2][i]%10;
                a[2][i+1]++;
            }
            else a[3][i] = a[2][i];
        }
        if(a[2][CurrentDigit-1] > 9){
            a[3][CurrentDigit-1] = a[2][CurrentDigit-1] % 10;
            a[3][CurrentDigit] = 1;
            CurrentDigit++;
        }
        else a[3][CurrentDigit-1] = a[2][CurrentDigit-1];
        
        for(int i=0; i<SIZE; i++){
            a[0][i] = a[1][i];
            a[1][i] = a[3][i];
        }
        
        Count++;
    }while(CurrentDigit<DIGIT);
    printf("%llu\n", Count);
}
