#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(void){
    int Size = 1000;
    int Array[1000] = {0};
    Array[0] = 1;
    for(int i=0; i<Size; i++){
        for(int j=Size-1; j>=0; j--){
            Array[j] *= 2;
            if(Array[j] >= 10){
                Array[j+1]++;
                Array[j] -= 10;
            }
        }
    }
    for(int i=0; i<Size; i++){
        printf("%d", Array[i]);
    }
    printf("\n");
    uint64_t sum = 0;
    for(int i=0; i<Size; i++){
        sum += Array[i];
    }
    printf("%llu\n", sum);
}