#include <stdio.h>
#include <math.h>

int main(void) {
    int nod = 0;
    int number = 99999; //find all the facts of the number
    int root = sqrt(number);
 
    for(int i = 1; i<= root; i++){
        if(number % i == 0){
            printf("%d\n", i);
            nod++;
        }
    }
    //Correction if the number is a perfect square
    if (root * root == number) {
        nod--;
    }

    printf("This number has %d facts.\n", nod);
}