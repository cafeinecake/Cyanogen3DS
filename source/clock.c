#include "clock.h"
#include "drawing.h"
#include "home.h"

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
