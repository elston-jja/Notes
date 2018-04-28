#include <stdio.h>

int main()
{
    int a1,a2,t1,t2, sum;
    double avg;
    char grade;


    printf("Input 2 assignment marks: ");
 
    while(scanf("%d %d", &a1,&a2) == EOF || a1 > 100 || a2 > 100)
    {
	printf("\nPlease enter valid integer values\n");
	printf("Input 2 assignment marks: ");
    }
    printf("Input 2 test marks: ");

    while(scanf("%d %d", &t1,&t2) == EOF || t1 > 100 || t2 > 100)
    {
	printf("Please enter valid integer values\n");
	printf("Input 2 test marks: ");
    }

    sum = (a1 + a2 + t1 + t2);

    avg = (double)sum /4;

    printf("The average of the marks input: %.2lf", avg);
    
    if( avg >= 80)
	grade = 'A';
    else 
	if (avg >= 70)
	    grade = 'B';
	else
	    if (avg >= 60)
		grade = 'C';
	    else
		if (avg >= 50)
		    grade = 'D';
		else
		    grade = 'F';

    printf("\nBased of the mark average above, you currently have a mark: %c", grade);

    return 0;
}
