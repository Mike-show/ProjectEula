#include <stdio.h>
#include <math.h>
int NumberOfDivisors(int);


int main(){
    int number = 0;
    int i = 1;
    
    while(NumberOfDivisors(number) < 500){
        number += i;
        i++;
    }

    printf("%d\n", number);
}

int NumberOfDivisors(int number) {
    int nod = 0;
    int root = sqrt(number);
 
    for(int i = 1; i<= root; i++){
        if(number % i == 0){
            nod += 2;
        }
    }
    //Correction if the number is a perfect square
    if (root * root == number) {
        nod--;
    }
 
    return nod;
}