#include <stdio.h>
#include <stdlib.h>

// 3x3 Solver

void create_matrix(float a[3][3]);
void print_matrix(float a[3][3]);

void matrix_add_row(float *a[3][3], int row, float to_add);
void matrix_divide_row(float *a[3][3], int row, float divident);
void matrix_rref(float *a, int col);   

float calc_det(float a[3][3]);


int main()
{
    float a[3][3], *ptr = a[0];
    create_matrix(a);
    print_matrix(a);
    float det = calc_det(a);
    printf("The determinate was: %f", det);
    matrix_rref(ptr,0);
}

void create_matrix(float a[3][3])
{
    for(int col = 0; col < 3; col++)
    {
	for(int row = 0; row < 3; row++)
	{
	    printf("Please enter value for a[%d][%d]: ",row+1,col+1);
	    scanf("%f", &a[row][col]);
	}
    }
    printf("\nStrored Matrix\n");
}

void print_matrix(float a[3][3])
{
    printf("\n");
    for(int y = 0; y < 3; y++)
    {
	for(int x = 0; x < 3; x++ )
	{
	    printf("%f\t", a[x][y]);
	}
	printf("\n");
    }
}

float calc_det(float a[3][3])
{
    float det;
    float C1 = a[1][1] * a[2][2] - a[2][1] * a[1][2];
    float C2 = a[0][1] * a[2][2] - a[2][1] * a[0][2];
    float C3 = a[0][1] * a[1][2] - a[1][1] * a[0][2];
    printf("\nC1: %f C2: %f C3: %f\n", C1, C2, C3);
    det = a[0][0] * C1 - a[1][0] * C2 + a[2][0] * C3;
    printf("a: %f b: %f c: %f\n", a[0][0], a[1][0], a[2][0]);
    return det;
}

void matrix_divide_row(float *a[3][3], int row, float divident)
{
    for(int col = 0; col < 3; col ++)
    {
	*a[row][col] = *a[row][col]/divident;
    }
}

void matrix_add_row(float *a[3][3], int row, float to_add)
{
        for(int col = 0; col < 3; col++)
    {
	*a[row][col] = *a[row][col] + to_add;
    }
}


void matrix_rref(float *a[3][3], int col)
{
    matrix_divide_row(a,0,*a[0][0]);
    for(int row = 1; row < 3; row++)
    {
	matrix_add_row(a,row, -(*a[0][0]));
    }
    print_matrix((*a));
    
}
