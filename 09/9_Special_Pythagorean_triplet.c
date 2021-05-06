#include <stdio.h>
#include <math.h>
int main(void){
    int a, b;
    float c;
        for(a = 1; a < 1000; a++){
            for(b = a + 1; b < 1000; b++){
                c = sqrt(a*a + b*b);
                if( a + b + c == 1000 && c == (int)c) break;
            }
            if( a + b + c == 1000 && c == (int)c) break;
        }
    printf("a = %d, b = %d, c = %f, abc = %f\n", a, b, c, a * b * c);
}