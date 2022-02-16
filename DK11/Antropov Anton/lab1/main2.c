#include <stdio.h>
#include "dk_tool2.h" 
int main (int argc, const char * argv[])
{
    float a = 0, b = 0, c = 0, under = 0; 
    printf("Введіть три числа a, b та c : "); 
    scanf("%f %f %f", &a, &b, &c); 
    under = mathF(a, b, c); 
    float result = (a*b)/(under); 
    printf("Результат розрахунку лівої частини : %.3f\n", result);
    int sum = factorial(b);
    printf("Сума факторіалів : %d\n", sum);
    float Q = result + sum;
    printf("Розв'язок задачі : %f\n", Q);
}


