#include <stdio.h>
void Read(int Array[15][15], FILE *fp);

int main(void){
    int Array[15][15] = {0};
    int ParentRow[15] = {0};
    int RightPath, LeftPath;
    int MaxNum = 0; 
    FILE *fp;
    fp = fopen("data.txt", "r");
    Read(Array, fp);
    ParentRow[0] = 75;
    for(int i=1; i<15; i++){
        int Temp[15] = {0};
        for(int j=0; j<=i; j++){
            if(j == 0){
                Temp[j] = Array[i][j] + ParentRow[j];
            }
            else {
                if(j == i){
                    Temp[j] = Array[i][j] + ParentRow[j-1];
                }
                else {
                    RightPath = Array[i][j] + ParentRow[j];
                    LeftPath = Array[i][j] + ParentRow[j-1];
                    if(RightPath > LeftPath) Temp[j] = RightPath;
                    else Temp[j] = LeftPath;
                }
            }
        }
        for(int k=0; k<=i; k++){
            ParentRow[k] = Temp[k];
        }
    }
    for(int i=0; i<15; i++){
        if(ParentRow[i] > MaxNum) MaxNum = ParentRow[i];
    }
    printf("%d\n", MaxNum);
    /*for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            printf("%d  ", Array[i][j]);
        }
        printf("\n");
    }*/
}

void Read(int Array[15][15], FILE *fp){
    for(int i=0; i<15; i++){
        for(int j=0; j<=i; j++){
            fscanf(fp, "%d", &Array[i][j]);
        }
    }
}