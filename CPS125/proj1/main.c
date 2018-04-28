#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Counters to develop the fibonacci sequence
    int a = 0, a_1 = 1, a_2 = 0, sequenceMax= 1000000;

    // Create Dynamic Array to store integers who have integer squareroots
    int *sqrtNums;
    sqrtNums = (int *)malloc(sizeof(int)*floor(sqrt(sequenceMax)));
    // Keep counters to know how big the array will get
    int amountSqrt = 0;

    // Keep a counter to how many numbers were calculated
    int amountNums = 1;

    // Placeholder variable to be added when its the 31 element
    int num31 = 0;

    double goldenRatio = 0;
    
    while(a <= sequenceMax)
    {

	printf("%d  ", a);

	if (a_1 != 0)
	{
	    goldenRatio = (float)a/a_1;
	    printf("%.3lf\n", goldenRatio);
	}
	else
	    printf("Skip\n");
	
	//The second last element is equal to the last element
	a_2 = a_1;
	// The last element is equal to the current element
	a_1 = a;
	// The new current element is a sum of the two previous elements
	a = a_1 + a_2;
	
	// check if the integer has a perfect integer squareroot
	if (sqrt((float)a) == floor(sqrt((float)a)))
	{

	    // If yes, then set it as an element in array sqrtNums 
	    sqrtNums[amountSqrt] = a;
	    // Keep track of the new element whcih was added
	    amountSqrt++;
	}

	amountNums++;
	// Save the 31 element in the sequence and will print it out later
	if (amountNums == 31)
	{
	    num31  = a;
	}

    }
    printf("\n\nThe amount of numbers displayed is %d", amountNums-1);

    printf("\n\nThe numbers that can perfectly be sqrt root into integers are: ");
	

    // Print all elements whcih exist inside the array.
    for(int i = 1; i != amountSqrt; i++)
    {
	printf("%d ", sqrtNums[i]);
    }
    
    if (num31)
	printf ("\nThe 31st number in the sequence is %d", num31);
    else
	printf("\nThere was not 31 elements in the fibonacci sequence up to %d", sequenceMax);

    return 0;
}
