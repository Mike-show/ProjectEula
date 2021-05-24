#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 10
#define TIME 1000000
#define STRING 11
uint32_t Count = 0;
void NextBit(char *Store, char *Value, int PreviousBit);

int main(void){
    char Store[SIZE] = {0};
    char *Value;
    Value = (char *)calloc(SIZE, STRING*sizeof(char));

    for(int i=0; i<STRING-1; i++){
        *(Value+i*sizeof(char)) = i+48;
    }

    uint32_t *Count = 0;
    for(int i=0; i<SIZE; i++){
        Store[0] = *(Value+i*sizeof(char));
        NextBit(Store, Value, 0);
    }
}

void NextBit(char *Store, char *Value, int PreviousBit){
    int CurrentBit = PreviousBit+1;
    if(CurrentBit == SIZE) {
        Count++;
        if(Count == TIME){
            printf("%s\n", Store);
            printf("%u\n", Count);
        }
    }
    else{
        int PreviousCount = 0;
        for(int i=0; i<SIZE-CurrentBit; i++){
            *(Value+(CurrentBit*STRING+i)*sizeof(char)) = *(Value+(PreviousBit*STRING+PreviousCount)*sizeof(char));
            if(*(Value+(CurrentBit*STRING+i)*sizeof(char)) == Store[PreviousBit]){
                PreviousCount++;
                *(Value+(CurrentBit*STRING+i)*sizeof(char)) = *(Value+(PreviousBit*STRING+PreviousCount)*sizeof(char));
            }
            PreviousCount++;
        }
        for(int i=0; i<SIZE-CurrentBit; i++){
            Store[CurrentBit] = *(Value+(CurrentBit*11+i)*sizeof(char));
            NextBit(Store, Value, CurrentBit);
        }
    }
}
