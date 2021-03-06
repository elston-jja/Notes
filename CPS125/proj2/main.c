#include <stdio.h>
#include <stdlib.h>

double find_avg(double**a, int row, int col),      find_sum_border(double**a, int, int);
double find_sum_corner(double**a, int,int),        find_sum_diag(double**a, int, int, double *a_diag);
double find_sum_row(double**a, int, int r_a),      find_avg_col(double**a, int, int c_a);

void print_matrix(double**a, int row, int col);

int main()
{
    int r_a, c_a;

    double a_diag;

    // Questions and Answers Array
    const char * q_array[7] = {"avg","avg col","sum corner","sum diag","sum a_diag","sum border", "sum row"};
    double a_array[7];

    int col, row;
    
    FILE * data = fopen("data.dat", "r");

    // Find the number of rows and col to allocate
    fscanf(data,"%d %d", &row, &col);
    
    // Create pointer pointer array according to standard
    double **a = (double**)malloc( row*sizeof(double*) );
    for(size_t i = 0; i < (size_t)col; i++)
    	a[i] = (double*)malloc( col*sizeof(double) );

    // Fill array with data from file
    for(size_t r = 0; r < (size_t)row; r++)
		for(size_t c = 0; c < (size_t)col; c++)
    	    fscanf(data,"%lf", &(a[c][r]) );
    
    // Row sum and Col average
    fscanf(data, "%d %d", &r_a, &c_a);

    print_matrix(a,row, col);
    
    // Save all answers in the Answer Array
    a_array[0] = find_avg(a,row, col);
    a_array[1] = find_avg_col(a, row, c_a);
    a_array[2] = find_sum_corner(a, row, col);
    a_array[3] = find_sum_diag(a, row, col, &a_diag);
    a_array[4] = a_diag;
    a_array[5] = find_sum_border(a, row, col);
    a_array[6] = find_sum_row(a, col, r_a);

    // Print the Q and A array neatly
    for(int p = 0; p < 7; p++)
    {
	if (p == 1)
	    printf("col: %d || ", c_a);
	else if (p == 6)
	    printf("row: %d || ", r_a);
	
    	printf("%s: %lf\n", q_array[p],a_array[p]);

    }
	
    if (col != row)
	printf("Note: Since the matrix is not square, the diagonal and anti-diagonal values were not calculated");

    // Set all pointer pointers to NULL
    for(size_t d = 0; d < (size_t)row; d++)
    	a[d] = NULL;

    //Delete original Pointers and close file
    free(a);
    fclose(data);
    return 0;
}

double find_avg(double ** a, int row, int col)
{
    double avg = 0;

    for(int c = 0; c < col; c++)
	for(int r = 0; r < row; r++)
	    avg += a[c][r];
	
    avg /= row*col;
    return avg;
}

double find_sum_corner(double ** a, int row, int col)
{
    double sum = a[0][0] + a[col-1][row-1] + a[col-1][0] + a[0][row-1];
    return sum;
}
double find_sum_diag(double ** a, int row, int col, double * a_diag)
{
    double sum = 0;
    
    if (row == col)
    {
	for(int i =0; i < row; i++)
	{
	    sum  += a[i][i];
	}
	for(int j = 0; j < row; j++)
	{
	    *a_diag = a[(col-1) - j][(row-1)-j];
	}
	return sum;
    }
    return 0;
}

double find_sum_border(double ** a, int row, int col)
{
    double sum = 0;
    
    for(int c = 0; c < col ; c++)
    {
	sum += a[c][0] + a[c][row-1];
    }
    for(int r = 0; r < row ; r++)
    {
	sum += a[col-1][r] + a[0][r];
    }

    sum -= a[0][0] + a[col-1][row-1] + a[col-1][0] + a[0][row-1];

    return sum;
}
double find_avg_col(double ** a, int rows, int c_a)
{
    double avg = 0;
    
    for(int r = 0; r < rows; r++)
	avg += a[c_a-1][r];
    avg /= rows;
    return avg;
    
}
double find_sum_row(double ** a, int col, int r_a)
{
    double sum = 0;

    for(int c = 0; c < col; c++)
	sum += a[c][r_a-1];
    
    return sum;
}

void print_matrix(double **a, int row, int col)
{
    for(int r = 0; r < row; r++)
    {
	for (int c = 0; c < col; c++)
	{
	    printf("%lf\t", a[c][r]);
	}
	printf("\n");
    }
}
