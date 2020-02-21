/* Program to determine day of the week */

#include <stdio.h>
#include <stdbool.h>

bool checkYear(int year) 
{ 
	return (((year % 4 == 0) && (year % 100 != 0)) || 
		(year % 400 == 0)); 
}

int main(int argc, char const *argv[])
{
	int a, b, c, d, e, day, month, year, numDays;
    int easter, count;

    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 

   	// printf ("Enter date between 1982 and 2048: ") ;
   	printf("Enter day, month and year: ");
	scanf("%d%d%d", &day,&month,&year);
    
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;
    easter = (22 + d + e);

    // calculate number of days from january 1 to input date
    for (int i = 0; i < month - 1; i++) 
	{
		day += monthDays[i];
	}

    /* 
	Pwede macalculate ang day of the week sa january 1 from easter
	If march, (easter+58) % 7
	If april, ((easter-31)+89) % 7
	+ 1 lang sa easter if leap year pero dili nako buhaton diri
	Result = 
	0 - SUNDAY
	1 - SATURDAY
	2 - FRIDAY
	...
	6 - MONDAY
	*/

    if (easter > 31) 
    {
        // printf("Easter is April %d\n", easter - 31);
        count = ((easter-31)+89) % 7;
    }
    else
    {
        // printf ("Easter is March %d\n", easter);
        count = (easter+58) % 7;
    }

    //increment
    for (int i = 1; i < day; i++)
    {
    	count--;
    	if (count < 0)
    	{
    		count = 6;
    		// printf("day reset: %d\n", count);
    	}	
    }

    //diri nalang iadjust if leap year
    if (checkYear(year) == 1 && (month < 3))
    {
    	// printf("LEAP YEAR DETECTED\n");
    	count++;
    	if (count > 6)
    	{
    		count = 0;
    	}
    }


    // printf("day of the week is: %d\n", count);

	switch(count) {
		case 0:
			printf("Sunday\n");
			break;
		case 6:
			printf("Monday\n");
			break;
		case 5:
			printf("Tuesday\n");
			break;
		case 4:
			printf("Wednesday\n");
			break;

		case 3:
			printf("Thursday\n");
			break;
		case 2:
			printf("Friday\n");
			break;
		case 1:
			printf("Saturday\n");
			break;
}
    return 0;
}