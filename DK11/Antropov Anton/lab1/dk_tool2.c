#include "dk_tool2.h"

float mathF(float a, float b, float c){
    float under = 0;
    while(under == 0){
        printf("Уведіть три числа a, b та c : ");
        scanf("%f %f %f", &a, &b, &c);
        under = b+(c*c);
    }
    return under;
}

int factorial(float b){
    int sum = 0, fact = 1;
    for(int d = 0; d <= b; d++)
    {
        if(d==0){
            sum = sum + 1;
        }else{
            fact = fact*d;
            sum = sum+fact;
        }
    }
    return sum;
}
