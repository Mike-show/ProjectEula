#include <stdio.h>
int main(void){
    int x = 1;
    int y, z;
    while (x > 0){
        z = 0;
        for(y = 1; y <= 20; y++){
            z += x % y;
        }
        if(z == 0)break;
        else x++;
    }
    printf("%d, %d\n", x, z);
    return 0;
}