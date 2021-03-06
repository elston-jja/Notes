#include <stdio.h>
#include <stdlib.h>

// Determine the Det
double calc_det(double ** a);

void calc_rref(double ** a);
void print_matrix(double  ** array);

// Matrix Manipulations
void m_row_mat(double ** a, int row, double n);

void a_row_mat(double ** a, int row_a, int row_b, double multiplier);
void s_row_mat(double ** a, int row_a, int row_b, double multiplier);

void a_mat(double ** a, int row, double n);
void s_mat(double ** a, int row, double n);

int main()
{
    FILE* matrix_dat = fopen("matrix.dat", "r");

	
    // Create the Array
    double **array = (double**)malloc(3*sizeof(double*));
    for (int i = 0 ; i < 3 ; i++)
    {
	array[i] = (double*)malloc(3*sizeof(double));
    }

    
    // Fill array from file
    for(int x = 0; x < 3; x++)
    {
	for(int y = 0; y < 3; y++)
	{
	    fscanf(matrix_dat,"%lf",&(array[x][y]));
	}
    }

    print_matrix(array);

    if (calc_det(array) != 0)
    {
	calc_rref(array);
	print_matrix(array);
    }
    else
	printf("Cannot reduce array");
    
    // Delete the array
    for(int i = 0; i < 3; i++)
    {
	array[i] = NULL;
    }
    free(array);

    fclose(matrix_dat);
    
    return 0;
}

double calc_det(double ** a)
{
    double det = 0;
    // Math to calc det
    double C1 = a[1][1] * a[2][2] - a[2][1] * a[1][2];
    double C2 = a[0][1] * a[2][2] - a[2][1] * a[0][2];
    double C3 = a[0][1] * a[1][2] - a[1][1] * a[0][2];
    //printf("\nC1: %f C2: %f C3: %f\n", C1, C2, C3);
    det = a[0][0] * C1 - a[1][0] * C2 + a[2][0] * C3;
    //printf("a: %f b: %f c: %f\n", a[0][0], a[1][0], a[2][0]);
    return det;
}

void calc_rref(double ** a)
{

    m_row_mat(a,1,1/a[0][0]);
    s_row_mat(a,2,1,a[1][0]);
    s_row_mat(a,3,1,a[2][0]);
    
    m_row_mat(a,2,1/a[1][1]);
    s_row_mat(a,1,2,a[0][1]);
    s_row_mat(a,3,2,a[2][1]);

    m_row_mat(a,3,1/a[2][2]);
    s_row_mat(a,1,3,a[0][2]);
    s_row_mat(a,2,3,a[1][2]);

}

void print_matrix(double ** array)
{
    for(int x = 0; x < 3; x++)
    {
	for(int y = 0; y < 3; y++)
	{
	    printf("%lf\t", array[x][y]);
	}
	printf("\n");
    }
    printf("\n");
}

void m_row_mat(double ** a, int row, double n)
{
    for(int col = 0; col < 3; col++)
    {
	a[row-1][col] = a[row-1][col]*n;
    }
}

// Add or subtract constants
void a_mat(double ** a, int row, double n)
{
    for(int col = 0; col < 3; col++)
    {
	a[row-1][col] = a[row-1][col] + n;
    }

}
void s_mat(double ** a, int row, double n)
{
    for(int col = 0; col < 3; col++)
    {
	a[row-1][col] = a[row-1][col] - n;
    }
    
}

void a_row_mat(double ** a, int row_a, int row_b, double multiplier)
{
    for (int col = 0; col < 3; col++)
    {
	a[row_a-1][col] = a[row_a-1][col] + a[row_b-1][col]*multiplier;
    }
}
void s_row_mat(double ** a, int row_a, int row_b, double multiplier)
{
    for (int col = 0; col < 3; col++)
    {
	a[row_a-1][col] = a[row_a-1][col] - a[row_b-1][col]*multiplier;
    }
}
