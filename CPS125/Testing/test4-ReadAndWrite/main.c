#include <stdio.h>

int main(void)
{
    int num1;
    int num_samples, num_orgs_per_100;
    FILE *data;
    int num_file;
    
    /* printf("Enter a number to be printed: "); */
    /* scanf("%d", &num1); */
    /* printf("You entred: %d\n", num1); */

    /* for(int i = 0; i < 5; i++) */
    /* { */
    /* 	printf("%d\n",i); */
    /* } */
    
    printf("Input the number of samples: ");
    scanf("%d", &num_samples);

    data = fopen("DATA.txt","w+");
    
    if (data)
    {
	for (int r = 0; r < num_samples; r++)
	{
	    printf("Input Sample:");
	    scanf("%d", &num_orgs_per_100);
	    fprintf(data, "%d\n", num_orgs_per_100);
	}

	// Go back to top of file
	rewind(data);

	// While not at the end of the file
	while(!feof(data))
	{
	    fscanf(data, "%d", &num_file);
	    printf("%d\n", num_file);
	}

	fclose(data);
    }
    else
	printf("Unable to read/write into file DATA.txt");
}
