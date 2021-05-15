#include <stdio.h>
#include <stdint.h>
int main(void){
    double Grid = 20;
    double Step = 2 * Grid; // in a matrix contains X cubes, 2*X steps are needed from one corner to the diagonal corner
    double Uper = 1, Lower = 1;
    for(double i=Step; i>Grid; i--){
        Lower = i/(i-Grid);
        Uper *= i/(i-Grid);
    }

    printf("%lf", Uper);
}