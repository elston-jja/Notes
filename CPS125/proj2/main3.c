#include <stdio.h>
#include <stdlib.h>

double average(double a[][200], int row, int col)
{
    double avg = 0;
    
    for(int i =0 ;i< row; i++ )
    {
	for(int k = 0; k< col; k++)
	{
	    avg =  avg  + a[i][k];
	}
    }
    avg = avg/(row*col);
    return avg;
}

double corner(double a[][200], int row, int col)
{
    double corner_sum  = a[0][0] + a[0][col-1] + a[row-1][0] + a[row-1][col-1];
    return corner_sum;
}

double row_avg(double a[][200], int row, int col, int r_c)
{
    double row_avg = 0;
    for(int i =0 ;i< col; i++)
    {
	row_avg += a[r_c-1][i];
		
    }
    row_avg /= col;
}

double thot_border(double a[][200], int row, int col)
{
    double avg = 0;

    	for(int k = 0; k< col; k++)
	{
	    avg =  avg  + a[0][k] + a[row-1][k];
	}
	for(int r = 0; r< row; r++)
	{
	    avg =  avg  + a[r][0] + a[r][col-1];
	}
	avg -= corner(a, row, col);
	
}


double diag(double a[][200], int row)
{
    double avg = 0;
    
    for(int i =0 ;i< row; i++ )
    {
	avg  += a[i][i];
    }
    avg /= row;
    return avg;
}


int main(void)
{
    FILE * data = fopen("data.dat", "r");
    int row, col;
    int r_c, c_c;

    fscanf(data, "%d %d", &row, &col);

    double a[row][col];

    for(int i = 0; i < row; i++)
    {
	for (int j = 0; j < col; j++)
	{
	    fscanf(data,"%lf",&a[i][j]);
	}
    }

    for(int k = 0; k < row; k++)
    {
	for(int c = 0; c< col; c++)
	{
	    printf("%lf\t", a[k][c]);
	}
	printf("\n");
    }

    fscanf(data,"%d %d", &r_c, &c_c);

    printf("AVERAGE: %lf", average(a, row, col));
    printf("ROW: %lf", row_avg(a, row, col, r_c));
    
    fclose(data);
    
}
