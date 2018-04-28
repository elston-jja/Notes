#include <stdio.h>

int main()
{
    double convertedYards, convertedMiles, toConvert;
    int values[4] = {100,200,400,800}; 

    printf("-----------------------------------\n");
    printf("| Meters |   Yards    |    Miles  |\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < 4; i++)
    {
	convertedYards = (double)values[i] * 1.094;
	convertedMiles = (double)values[i] * 0.0006215;
	printf("| %6d | %9lf | %9lf |\n", values[i], convertedYards, convertedMiles);
    }

    printf("Please enter a value in meters to convert: ");
    scanf("%lf", &toConvert);

    convertedYards  = toConvert * 1.094;
    convertedMiles  = toConvert * 0.0006215;

    printf("Yards: %9lf\nMiles: %9lf", convertedYards, convertedMiles);
    
    return 0;
}
