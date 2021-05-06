#include <stdio.h>
int main(void){
    int i;
    int x = 0;
    for(i = 0; i < 1000; i++){
        if(i % 3 == 0|| i % 5 == 0){
            x += i;
        }
    }
    printf("The sum of multiples of 3 or 5 is %d.\n", x);
    return 0;
}