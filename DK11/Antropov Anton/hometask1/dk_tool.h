#ifndef math_h
#define math_h

#include <stdio.h>

int **create_matrix(int a, int b);
void delete_matrix(int **array, int a);
void fillarray(int **array,int a,int b,int c);
void printarray(int **array,int a,int b);

#endif 
