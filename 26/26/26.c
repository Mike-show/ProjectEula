#include <stdio.h>
#include <math.h>

#define BITSIZE 10

int Divide(int d, int Digit, int a[BITSIZE]);
int DigitCount(int d);

int main(int argc, const char * argv[]) {
    int d = 73, bit = 0;
    int a[BITSIZE] = {0};
        int Digit = 0;
        Digit = DigitCount(d);
        bit = Divide(d, Digit, a);
    printf("0.");
    for(int i=0; i<BITSIZE; i++){
        printf("%d", a[i]);
    }
}

int DigitCount(d){
    int Digit = 0;
    if(d/1000 != 0) Digit = 4;
    else {
        if(d/100 != 0) Digit = 3;
        else{
            if(d/10 != 0) Digit = 2;
            else Digit = 1;
        }
    }
    
    return Digit;
}

int Divide(int d, int Digit, int a[BITSIZE]){
    int Quotient, Remainder = 1, Numerator, bit = Digit-1;
    int Pow = pow(10, Digit);
    do{
        Numerator = Remainder;
        Quotient = Numerator*Pow/ d;
        Remainder = (Numerator*Pow)%d;
        a[bit] = Quotient;
        bit+=Digit;
    }while(Remainder != 0 && bit<BITSIZE);
    return bit;
}
