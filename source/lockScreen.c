#include "clock.h"
#include "homeMenu.h"
#include "lockScreen.h"

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} lockscreen_img;

int lockScreen()
{
	lockscreenBg = sf2d_create_texture_mem_RGBA8(lockscreen_img.pixel_data, lockscreen_img.width, lockscreen_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);

	int hours = timeStruct->tm_hour;
	int minutes = timeStruct->tm_min;
	int day = timeStruct->tm_mday;
	
	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));

	while (1)
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(background, 0, 0);
		sf2d_draw_texture(lockscreenBg, 0, 0);
		
		sftd_draw_textf(roboto, 142, 20, RGBA8(255, 255, 255, 255), 34, "0%2d : %02d", hours, minutes);
		sftd_draw_textf(roboto, 140, 80, RGBA8(255, 255, 255, 255), 10, "Monday");
		sftd_draw_textf(roboto, 200, 80, RGBA8(255, 255, 255, 255), 10, "%d", day);
		sftd_draw_textf(roboto, 220, 80, RGBA8(255, 255, 255, 255), 10, "October");
		
		digitalTime(350, 2); 
		batteryStatus(316, 2); 
		cursorController();
		
		sf2d_end_frame();
		
		if ((touch.px  >= 160 && touch.px  <= 235 && touch.py >= 210 && touch.py <= 240) && (kDown & KEY_A))
		{	
			sf2d_free_texture(lockscreenBg);
			return 1;
		}
			
		sf2d_swapbuffers();
	}
	
	sf2d_free_texture(lockscreenBg);
	
	return 0;
}
