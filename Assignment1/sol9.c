#include<stdio.h>
#include<time.h>

int main()
{
	time_t current_time;
	struct tm *tm_current_time;  // Declaring a current time structure
	int hours,min,sec;
	current_time=time(NULL);
	tm_current_time=localtime(&current_time);  // Convert time value passed in time_t to structure
	hours = tm_current_time->tm_hour;
	min = tm_current_time->tm_min;
	sec = tm_current_time->tm_sec;
	printf("The Time is %d : %d : %d\n",hours,min,sec);  // Obtain current time
}
	
	
