#include <stdio.h>
#include <stdint.h>

int main(void){
    uint32_t Num = 0;
    int Chain = 0;
    for(uint32_t i=2; i<=1000000; i++){
        int ChainTemp = 0;
        uint32_t NumTemp = i;
        do
        {
            if(NumTemp % 2 == 1){
                NumTemp = 3*NumTemp+1;
            }
            else NumTemp /= 2;
            ChainTemp++;
        } while (NumTemp != 1);
        if(ChainTemp > Chain) {
            Chain = ChainTemp;
            Num = i;
        }
    }
    printf("%d, %d\n", Num, Chain);
}