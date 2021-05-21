#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define LEN 20

int StrCompare(char *String1, char *String2);
void StringRead(char *R, FILE *fp);
int NameCount(FILE *fp);
void DataMove(char *Row, char *Temp, int CurrentRow, int Count);

int main(void){
    FILE *fp;
    FILE *fp2;
    fp = fopen("p022_names.txt", "r");

    //create an array to store names which have been re-ordered
    char *Row;
    int Count=0;

    //Count how many names are there
    Count = NameCount(fp);

    //manually assign memery according to the quantity of names
    //there would be "Count" number of rows, every row's size is LEN * char
    Row = (char *)calloc(Count+1, LEN*sizeof(char));

    //initialize the 1st row into a "ZZZ..." string
    for(int i=0; i<LEN-1; i++){
        *(Row+i) = 'Z'+1;
    }

    //after count names, file pointer has come to the end of the file, reset it
    rewind(fp);
    printf("%d\n", Count);


    while(!feof(fp)){
        char R[LEN] = {0};

        //read file name by name
        StringRead(R, fp);
        int CurrentRow = 0;
        char Temp[LEN];
        do{
            //compare current name stored in R to every row of the array
            int CompareResult = StrCompare(R, Row+CurrentRow*LEN);

            //if current row is bigger than the R, this is the right position where R should be placed
            if(CompareResult == 1){

                //store R at current row, store the former value temporarily in Temp for the next move funtion
                strcpy(Temp, Row+CurrentRow*LEN);
                strcpy(Row+CurrentRow*LEN, R);

                //all the rows after current row should be move one row, towards the end of the array
                DataMove(Row, Temp, CurrentRow, Count);
                //all the steps inside of this while loop can be called "insertion"
                break;
            }
            CurrentRow++;
        }while(CurrentRow < Count);
    }
    
    uint64_t Sum = 0;
    int Count2 = 0;
    for(int i=0; i<Count; i++){
        int SumRow = 0;
        for(int j=0; *(Row+i*LEN+j) != '\0'; j++){
            SumRow += (*(Row+i*LEN+j)-'@');
        }
        Sum += (i+1)*SumRow;
    }
    printf("%llu\n\n", Sum);
}


int NameCount(FILE *fp){
    int Count = 1;
    char Read;
    do{
        Read = fgetc(fp);
        if(Read == ',') Count++;
    }while(!feof(fp));
    return Count;
}

void StringRead(char *R, FILE *fp){
    int Count = 0;
    for(int i=0; i<LEN; i++){
        *(R+i) = fgetc(fp);
        Count++;
        if(*(R+i) == '"') {
            i--;
            Count--;
        }
        else if(*(R+i) == ',' || *(R+i) == EOF) break;
    }
    *(R+Count-1) = '\0';
}

int StrCompare(char *String1, char *String2){
    int Result = 0;
    for(int i=0; i<LEN; i++){
        if(*(String1+i) > *(String2+i)) break;
        else {
            if(*(String1+i) < *(String2+i)){
                Result = 1;
                break;
            }
        }
    }
    return Result;
}

void DataMove(char *Row, char *Temp, int CurrentRow, int Count){
    for(int i=Count; i>CurrentRow+1; i--){
        strcpy(Row+i*LEN, Row+(i-1)*LEN);
    }
    strcpy(Row+(CurrentRow+1)*LEN, Temp);
}