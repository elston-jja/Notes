#include <stdio.h>

int main(void)
{
    FILE* data = fopen("data.txt", "w+");

    int temp;
    int repeat;

    printf("Please enter the number of values to save: ");
    scanf("%d", &repeat);

    for (int i = 0; i < repeat; i++)
    {
	printf("value %d: ", i+1);
	scanf("%d", &temp);
	fprintf(data, "%d\n", temp);
    }

    // Go back to the top of the file
    rewind(data);

    printf("The values currently stored are: \n");
    
    while(!feof(data))
    {
	fscanf(data,"%d", &temp);
	printf("%d\n", temp);
    }
    
    fclose(data);
}
