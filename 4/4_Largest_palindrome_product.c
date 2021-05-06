#include <stdio.h>
int main(void){
    float a, b, c, i, n, r;
    for(a = 9; a > 0; a--){
        for(b = 9; b >= 0; b--){
            for(c = 9; c >= 0; c--){
                for(i = 100; i < 1000; i++){
                    n = a*100000 + b*10000 + c*1000 + c*100 + b*10 + a;
                    r = n / i;
                    if(r == (int)r && r >= 100 && r < 1000)
                    break;
                }
                if(r == (int)r && r >= 100 && r < 1000)
                break; 
            }
            if(r == (int)r && r >= 100 && r < 1000)
            break; 
        }
        if(r == (int)r && r >= 100 && r < 1000)
        break;
    }
    printf("%f, %f, %f\n", n, i, r);
    return 0;
}