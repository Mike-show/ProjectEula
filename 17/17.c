#include <stdio.h>

int CountT(int T);
int CountU(int U);
#define AND 3;
#define ONETHOUSAND 11;
#define HUNDRED 7;

int main(void){
    int Result = 0;

    for(int i=1; i<=19; i++){
        Result += CountU(i); // one~ninteen
    }

    for(int i=20; i<=99; i++){
        int Temp = i/10;
        Result += CountT(Temp); // twenty~ninety
        int Units = i-Temp*10;
        Result += CountU(Units); // one~nine        
    }

    for(int i=100; i<=999; i++){
        int Hundreds, Tens, Units, Temp;
        Hundreds = i/100;
        Result += CountU(Hundreds); //one~nine
        Result += HUNDRED;
        Tens = i-Hundreds*100;
        if(Tens != 0){
            Result += AND;  //and
            if(Tens >= 20){
                Temp = Tens/10;
                Result += CountT(Temp); // twenty~ninety
                Units = Tens-Temp*10;
                Result += CountU(Units); // one~nine
            }
            else {
                Result += CountU(Tens); // one~ninteen
            }
        }
    }
    Result += ONETHOUSAND; //one thousand
    printf("%d\n", Result);
}

int CountT(int T){
    int R;
    switch (T)
    {
    case 0:
        R = 0;
        break;
    case 1:
        R = 0;
        break;
    case 2:
        R = 6;//twenty
        break;
    case 3:
        R = 6;//thirty
        break;
    case 4:
        R = 5;//forty
        break;
    case 5:
        R = 5;//fifty
        break;
    case 6:
        R = 5;//sixty
        break;
    case 7:
        R = 7;//seventy
        break;
    case 8:
        R = 6;//eighty
        break;
    case 9:
        R = 6;//ninety
        break;
    default:
        printf("Error\n");
        break;
    }
    return R;
}

int CountU(int U){
    int R;
    switch (U)
    {
    case 0:
        R = 0;
        break;
    case 1:
        R = 3;//one
        break;
    case 2:
        R = 3;//two
        break;
    case 3:
        R = 5;//three
        break;
    case 4:
        R = 4;//four
        break;
    case 5:
        R = 4;//five
        break;
    case 6:
        R = 3;//six
        break;
    case 7:
        R = 5;//seven
        break;
    case 8:
        R = 5;//eight
        break;
    case 9:
        R = 4;//nine
        break;
    case 10:
        R = 3;//ten
        break;
    case 11:
        R = 6;//eleven
        break;
    case 12:
        R = 6;//twelve
        break;
    case 13:
        R = 8;//thirteen
        break;
    case 14:
        R = 8;//fourteen
        break;
    case 15:
        R = 7;//fifteen
        break;
    case 16:
        R = 7;//sixteen
        break;
    case 17:
        R = 9;//seventeen
        break;
    case 18:
        R = 8;//eighteen
        break;
    case 19:
        R = 8;//nineteen
        break;
    default:
        printf("Error\n");
        break;
    }
    return R;
};