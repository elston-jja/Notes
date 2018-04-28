#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **a, int matrix_size);

int main()
{

    FILE * data_file;
    char* data[] = {"dat1.dat"};
    int num_of_data_files = sizeof(data)/sizeof(data[0]);


    for(int i = 0; i < num_of_data_files; i++)
    {
	data_file = fopen(data[i], "r");

	// Gets the size of the matrix
	int matrix_size = 0;
	fscanf(data_file,"%d", &matrix_size);

	// Create an int array depending on the size
	int ** a = malloc(matrix_size*sizeof(int));
	for (int j = 0; j < matrix_size; j++)
	{
	    a[j] = malloc(matrix_size*sizeof(int));
	}

	
	for( int x = 0; x < matrix_size; x++)
	{
	    for (int y = 0; y < matrix_size; y++)
	    {
		fscanf(data_file,"%d", &a[x][y]);
	    }
	}

	print_matrix(a,matrix_size);
	printf("Now printing diagonal and cross diagonal\n");

	for(int t = 0; t < matrix_size; t++)
	{
	    printf("%d\t", a[t][t]);
	}
	printf("\n");
	for(int k = 0; k < matrix_size; k++)
	{
	    printf("%d\t", a[k][(matrix_size-1)-k]);
	}

	// end sequence, delete pointers
	for(int d = 0; d < matrix_size; d++)
	{
	    a[d] = NULL;
	}
	free(a);
	
	fclose(data_file);
    }
}

void print_matrix(int **a, int matrix_size)
{
    for( int x = 0; x < matrix_size; x++)
    {
	for (int y = 0; y < matrix_size; y++)
	{
	    printf("%d\t", a[x][y]);
	}
	printf("\n");
    }    
}
