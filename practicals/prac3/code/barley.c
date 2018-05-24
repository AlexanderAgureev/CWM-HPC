/**************************************************
 *                                                *
 * First attempt at a code to calcule lost barley *
 * by A. Farmer                                   *
 * 18/05/18                                       *
 *                                                *
 **************************************************/

// Include any headers from the C standard library here
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define any constants that I need to use here
#define PI = 3.14 

// This is where I should put my function prototypes
float area_of_circle(float radius); 

// Now I start my code with main()
int main() {

    // In here I need to delare my variables
	FILE *fp;
	char filename[200];
	int number_of_circles = 0;
	float TOTAL_AREA = 0;
	float TOTAL_LOSS;
	int i;
	float *radii, *areas;

    // Next I need to get input from the user.
    // I'll do this by using a printf() to ask the user to input the radii.
	printf("\nEnter number of circles: ");
        scanf("%d", &number_of_circles);
 
        printf("\nEnter	your file: ");
        scanf("%s", filename);
	
	radii = (float *)malloc(number_of_circles*sizeof(float));
        areas = (float *)malloc(number_of_circles*sizeof(float));

	
	fp=fopen(filename,"r");
	for (i=0; i<number_of_circles; i++) {
		fscanf(fp, "%f", &radii[i]);
		}
	for (i = 0; i < number_of_circles; i++) {
		areas[i] = area_of_circle(radii[i]);
	}

	for (i = 0; i < number_of_circles; i++) {
		TOTAL_AREA = TOTAL_AREA + areas[i];
	}
	

 
   // Now I need to loop through the radii caluclating the area for each
			
    // Next I'll sum up all of the individual areas

    /******************************************************************
     *                                                                *
     * Now I know the total area I can use the following information: *
     *                                                                *
     * One square meter of crop produces about 135 grams of barley    *
     *                                                                *
     * One kg of barley sells for about 10 pence                      *
     *                                                                *
     ******************************************************************/

    // Using the above I'll work out how much barley has been lost.
    TOTAL_LOSS = TOTAL_AREA*0.135;

    // Finally I'll use a printf() to print this to the screen.
    printf("\nTotal area lossed in m^2 is:\t%f\n", TOTAL_AREA);
    printf("Total loss in kg is:\t\t%f\n", TOTAL_LOSS);

    return(0);
}

// I'll put my functions here:
float area_of_circle(float radius)
        {
		float area;
                area = 3.14*radius*radius;
                return(area);
        }
