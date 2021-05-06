#include <stdio.h>
int main(void){
    int counter = 0, num = 2, i, flag = 1;
    while(counter < 10001){
        for(i = 2; i <= num/2; i++){
            if(num % i == 0){
                flag++;
                break;
            }
        }
        counter = num - flag;
        num++;
    }
    printf("%d\n", num-1);
}