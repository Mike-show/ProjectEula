#include<stdio.h>
int main(void){
    int x = 1, y = 1, z = 0, sum = 0;
    while(z <= 4000000){
        z = x + y;
        if(z % 2 == 0){
            sum += z;
        }
        x = y;
        y = z;
    }
    printf("The sum of even-term value is %d.\n", sum);
    return 0;
}