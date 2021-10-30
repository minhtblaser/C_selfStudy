#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORDS 31
#define BSIZE 80

struct calendar {
	int year;
	char *month;
	int day;
};
struct temperature_data {
	struct calendar date;
	float high;
	float low;
};

float average_high(struct temperature_data w[]);
float average_low(struct temperature_data w[]);
int highest_high(struct temperature_data w[]);
int lowest_high(struct temperature_data w[]);
int highest_low(struct temperature_data w[]);
int lowest_low(struct temperature_data w[]);

int main()
{
	struct temperature_data winter[RECORDS];
	char filename[] = "weather_data.csv";
	char buffer[BSIZE];
	FILE *f;
	char *field;
	int month,r,h,l;
	char *months[] = { "January", "February", "March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December" };

/* open the CSV file */
	f = fopen(filename,"r");
	if( f == NULL)
	{
		printf("Unable to open file '%s'\n",filename);
		exit(1);
	}

	/* process the data */
	/* the file contains 5 fields in a specific order:
	   year,month,day,high,low
	   separated by commas */
	r = 0;	/* record counter */
	while(fgets(buffer,BSIZE,f))
	{
		/* get year */
		field=strtok(buffer,",");
		winter[r].date.year=atoi(field);
		/* get month */
		field=strtok(NULL,",");
		month=atoi(field);
		month--;	/* for the months[] array */
		/* copying pointers here */
		winter[r].date.month = months[month];
		/* get day */
		field=strtok(NULL,",");
		winter[r].date.day=atoi(field);
		/* get high */
		field=strtok(NULL,",");
		winter[r].high=atof(field);
		/* get low */
		field=strtok(NULL,",");
		winter[r].low=atof(field);
		/* increment record counter */
		r++;
		if( r > RECORDS)
		{
			puts("Record count exceeded");
			exit(1);
		}
	}

	/* close file */
	fclose(f);

	printf("Date range from %s %d, %d to %s %d, %d:\n",
			winter[0].date.month,
			winter[0].date.day,
			winter[0].date.year,
			winter[RECORDS-1].date.month,
			winter[RECORDS-1].date.day,
			winter[RECORDS-1].date.year
			);
	printf("The average high was %.2f\n",average_high(winter));
	printf("The average low was %.2f\n",average_low(winter));
	h = highest_high(winter);
	printf("The highest high was %.1f on %s %d, %d\n",
			winter[h].high,
			winter[h].date.month,
			winter[h].date.day,
			winter[h].date.year
			);
	l = lowest_high(winter);
	printf("The lowest high was %.1f on %s %d, %d\n",
			winter[l].high,
			winter[l].date.month,
			winter[l].date.day,
			winter[l].date.year
			);
	h = highest_low(winter);
	printf("The highest low was %.1f on %s %d, %d\n",
			winter[h].low,
			winter[h].date.month,
			winter[h].date.day,
			winter[h].date.year
			);
	l = lowest_low(winter);
	printf("The lowest low was %.1f on %s %d, %d\n",
			winter[l].low,
			winter[l].date.month,
			winter[l].date.day,
			winter[l].date.year
			);

	return(0);
}

/* return the average of all the high temp values */
float average_high(struct temperature_data w[])
{
	int x;
	float total = 0.0;
	
	for(x=0;x<RECORDS;x++)
		total += w[x].high;
		
	return(total/(float)RECORDS);
}

/* return the average of all the low temp values */
float average_low(struct temperature_data w[])
{
	int x;
	float total = 0.0;
	
	for(x=0;x<RECORDS;x++)
		total += w[x].low;
		
	return(total/(float)RECORDS);
}

/* obtain the element number for the highest high
   This function is similar to a max() function */
int highest_high(struct temperature_data w[])
{
	int x,r;
	float highest;
	
	/* assume the first element is the greatest */
	highest = w[0].high;
	r = 0;		/* store the max value element number */
	for(x=0;x<RECORDS;x++)
	{
		if(w[x].high > highest)
		{
			/* update the max */
			highest = w[x].high;
			r = x;
		}
	}

	return(r);	/* return the element number */
}

/* obtain the element number for the lowest high
   This code is a copy-and-paste of the highest_high()
   function, with the > sign reversed */
int lowest_high(struct temperature_data w[])
{
	int x,r;
	float lowest;
	
	lowest = w[0].high;
	r = 0;
	for(x=0;x<RECORDS;x++)
	{
		if(w[x].high < lowest)
		{
			lowest = w[x].high;
			r = x;
		}
	}

	return(r);
}

/* This code is also a copy-and-paste, but focused on
   the weather[].low member */
int highest_low(struct temperature_data w[])
{
	int x,r;
	float highest;
	
	highest = w[0].low;
	r = 0;
	for(x=0;x<RECORDS;x++)
	{
		if(w[x].low > highest)
		{
			highest = w[x].low;
			r = x;
		}
	}

	return(r);
}

/* ditto */
int lowest_low(struct temperature_data w[])
{
	int x,r;
	float lowest;
	
	lowest = w[0].low;
	r = 0;
	for(x=0;x<RECORDS;x++)
	{
		if(w[x].low < lowest)
		{
			lowest = w[x].low;
			r = x;
		}
	}

	return(r);
}