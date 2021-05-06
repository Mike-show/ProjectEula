#include <stdio.h>

int CountH(int H);
int CountT(int T);
int CountU(int U);

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
        Result += CountH(Hundreds); //one hundred~nine hundred
        Tens = i-Hundreds*100;
        if(Tens != 0){
            Result += 3;  //and
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
    Result += 11; //one thousand
    printf("%d\n", Result);
}

int CountH(int H){
    switch (H)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 10;
        break;
    case 2:
        return 10;
        break;
    case 3:
        return 12;
        break;
    case 4:
        return 11;
        break;
    case 5:
        return 11;
        break;
    case 6:
        return 10;
        break;
    case 7:
        return 12;
        break;
    case 8:
        return 12;
        break;
    case 9:
        return 11;
        break;
    default:
        printf("Error\n");
        break;
    }
}

int CountT(int T){
    switch (T)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 0;
        break;
    case 2:
        return 6;
        break;
    case 3:
        return 6;
        break;
    case 4:
        return 5;
        break;
    case 5:
        return 5;
        break;
    case 6:
        return 5;
        break;
    case 7:
        return 7;
        break;
    case 8:
        return 6;
        break;
    case 9:
        return 6;
        break;
    default:
        printf("Error\n");
        break;
    }
}

int CountU(int U){
    switch (U)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 3;
        break;
    case 2:
        return 3;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 4;
        break;
    case 6:
        return 3;
        break;
    case 7:
        return 5;
        break;
    case 8:
        return 5;
        break;
    case 9:
        return 4;
        break;
    case 10:
        return 3;
        break;
    case 11:
        return 6;
        break;
    case 12:
        return 6;
        break;
    case 13:
        return 8;
        break;
    case 14:
        return 8;
        break;
    case 15:
        return 7;
        break;
    case 16:
        return 7;
        break;
    case 17:
        return 9;
        break;
    case 18:
        return 8;
        break;
    case 19:
        return 8;
        break;
    default:
        printf("Error\n");
        break;
    }
}