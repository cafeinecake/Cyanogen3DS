#include "clock.h"
#include "homeMenu.h"

void digitalTime(int x, int y)
{
	time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);

	int hours = timeStruct->tm_hour;
	int minutes = timeStruct->tm_min;
	//int seconds = timeStruct->tm_sec;
	//int day = timeStruct->tm_mday;
	//int month = timeStruct->tm_mon;
	//int year = timeStruct->tm_year +1900;

	sftd_draw_textf(roboto, x, y, RGBA8(255, 255, 255, 255), 12, "%2d:%02d", hours, minutes);
	
	if (hours < 12)
		sftd_draw_textf(roboto, x+30, y+2, RGBA8(255, 255, 255, 255), 10, "AM");
	else 
		sftd_draw_textf(roboto, x+30, y+2, RGBA8(255, 255, 255, 255), 10, "PM");
}

void getMonthOfYear(int x, int y, int size)
{
	static const char months[12][16] =
	{
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
       
    time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);
	int month = timeStruct->tm_mon;
	int day = timeStruct->tm_mday;
	
    sftd_draw_textf(roboto, x, y, RGBA8(255, 255, 255, 255), size, "%d %s", day, months[month]);
}
