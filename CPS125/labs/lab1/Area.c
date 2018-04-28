#include <stdio.h>
#define PI 3.14159265

/*

Created by Elston Almieda

RYERSON UNIVERSITY

LAB EXTRA 

*/

float CalculateArea(float);

int main()
{

    float r;
    float area;
    
    printf("Please enter the radius of a circle: ");
    
    scanf("%f",&r);

    area = CalculateArea(r);

    printf("The area for such a circle is: %5.2f", area);
	   
    return 0;

}


float CalculateArea(float r)
{
    float a = PI*r*r;
    
    return a;
}
