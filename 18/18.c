#include <stdio.h>
void Read(int Array[15][30], FILE *fp);

int main(void){
    int Array[15][30] = {0};
    FILE *fp;
    fp = fopen("data.txt", "r");
    Read(Array, fp);
    for(int i=0; i<15; i++){
        for(int j=0; j<30; j++){
            printf("%d  ", Array[i][j]);
        }
        printf("\n");
    }
}

void Read(int Array[15][30], FILE *fp){
    for(int i=0; i<15; i++){
        for(int j=14-i; j<=14+i; j+=2){
            fscanf(fp, "%d", &Array[i][j]);
        }
    }
}