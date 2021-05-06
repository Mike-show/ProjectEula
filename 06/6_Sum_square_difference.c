#include <stdio.h>
#include <math.h>
int main(void){
    int a, c;
    int b = 0, d = 0;
    for(a = 1; a <= 100; a++){
        b += pow(a, 2);
    }
    for(c = 1; c <= 100; c++){
        d += c;
    }
    printf("%f\n", pow(d, 2) - b);
}