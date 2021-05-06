#include<stdio.h>
int main(void){
    long p, q;
    printf("Input a number:");
    scanf("%ld", &q);
    for(p = 2; p <= q; p++){
        if(p != q){
            while(q % p == 0){
                q = q / p;
                }
            }
        else printf("The biggest prime factor is %ld.\n", q);
    }
    return 0;
}