#include <stdio.h>
int main(void)
{   unsigned long long sum = 0;
    int tar, i, flag;
    for(tar = 2; tar <= 2000000; ++tar){
        flag = 0;
        for(i = 2; i <= tar/2; ++i){
            if(tar % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0) sum += tar;
    }
    printf("sum is %llu\n", sum);
    return 0;
}