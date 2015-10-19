#include "appDrawer.h"
#include "clock.h"
#include "drawing.h"
#include "gfx.h"
#include "home.h"
#include "lockScreen.h"
#include "main.h"
#include "powerMenu.h"

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_allapps_pressed_img;

int cursorController()
{
	//hidKeysHeld returns information about which buttons have are held down in this frame
	u32 kHeld = hidKeysHeld();
	
	//Read the touch screen coordinates
	if (kHeld & KEY_TOUCH) 
	{
		hidTouchRead(&touch);
		touch_x = touch.px;
		touch_y = touch.py;
	}

	sf2d_draw_texture(cursor, touch_x, touch_y);
	
	return 0;
}

int batteryStatus(int x, int y)
{
	int batt = 100; //This is temporary until I find how to get battery status. I know 3DS doesn't use percentages, but only values from 1-5.

	sf2d_draw_texture(_100, 300, 2);
	sftd_draw_textf(roboto, x, y, RGBA8(255, 255, 255, 255), 12, "%d%%", batt);
	
	return 0;
}

void appDrawerIcon() //Draws the app drawer icon. Draws a different icon of the same size once hovered with the cursor.
{
	if (touch.px  >= 170 && touch.px  <= 210 && touch.py >= 130 && touch.py <= 180)
		sf2d_draw_texture(ic_allapps_pressed, 179, 148);
	
	else
		sf2d_draw_texture(ic_allapps, 179, 148);
}

int navbarControls()
{
	if (touch.px  >= 84 && touch.px  <= 159 && touch.py >= 201 && touch.py <= 240)
		sf2d_draw_texture(backicon, 70, 201);
	else
		sf2d_draw_texture(navbar, 70, 201);

	if (touch.px  >= 160 && touch.px  <= 235 && touch.py >= 201 && touch.py <= 240)
		sf2d_draw_texture(homeicon, 70, 201);
	else
		sf2d_draw_texture(navbar, 70, 201);
	
	if (touch.px  >= 236 && touch.px  <= 311 && touch.py >= 201 && touch.py <= 240)
		sf2d_draw_texture(multicon, 70, 201);
	else
		sf2d_draw_texture(navbar, 70, 201);
		
	return 0;
}

int dayNightWidget()
{
	time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);

	int hours = timeStruct->tm_hour;
	int minutes = timeStruct->tm_min;
	int day = timeStruct->tm_mday;
	//int month = timeStruct->tm_mon;
	
	if (hours < 6)
		sf2d_draw_texture(dayWidget, 172, 60);
	else
		sf2d_draw_texture(nightWidget, 167, 60);
		
	sftd_draw_textf(roboto, 142, 20, RGBA8(255, 255, 255, 255), 34, "0%2d : %02d", hours, minutes);
	sftd_draw_textf(roboto, 130, 80, RGBA8(255, 255, 255, 255), 10, "Monday");
	sftd_draw_textf(roboto, 230, 80, RGBA8(255, 255, 255, 255), 10, "%d", day);
	sftd_draw_textf(roboto, 245, 80, RGBA8(255, 255, 255, 255), 10, "October");
	
	return 0;
}

int home()
{
	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));

	ic_allapps_pressed = sf2d_create_texture_mem_RGBA8(ic_allapps_pressed_img.pixel_data, ic_allapps_pressed_img.width, ic_allapps_pressed_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	ic_launcher_browser = sf2d_create_texture_mem_RGBA8(ic_launcher_browser_img.pixel_data, ic_launcher_browser_img.width, ic_launcher_browser_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_messenger = sf2d_create_texture_mem_RGBA8(ic_launcher_messenger_img.pixel_data, ic_launcher_messenger_img.width, ic_launcher_messenger_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_apollo = sf2d_create_texture_mem_RGBA8(ic_launcher_apollo_img.pixel_data, ic_launcher_apollo_img.width, ic_launcher_apollo_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_settings = sf2d_create_texture_mem_RGBA8(ic_launcher_settings_img.pixel_data, ic_launcher_settings_img.width, ic_launcher_settings_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	// Main loop
	while (aptMainLoop())
	{

		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		
		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
		//hidKeysUp returns information about which buttons have been just released
		//u32 kUp = hidKeysUp();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(background, 0, 0);
		
		sf2d_draw_texture(ic_launcher_browser, 49, 135);
		sf2d_draw_texture(ic_launcher_messenger, 114, 135);
		sf2d_draw_texture(ic_launcher_apollo, 241, 135);
		sf2d_draw_texture(ic_launcher_settings, 306, 135);
		appDrawerIcon();

		dayNightWidget();
		
		navbarControls(); //Displays navbar
		digitalTime(350, 2); //Displays digital time
		batteryStatus(316, 2); //Displays battery status
		cursorController();
		
		sf2d_end_frame();
		
		if ((touch.px  >= 170 && touch.px  <= 210 && touch.py >= 148 && touch.py <= 190) && (kDown & KEY_A))
		{
			sf2d_free_texture(ic_allapps_pressed);
			appDrawer(); //Open app drawer
		}
		
		if (kDown & KEY_Y)
			powerMenu(); //Open power menu
		
		if (kDown & KEY_L)
			lockScreen(); //Locks the screen

		// Flush and swap framebuffers
		sf2d_swapbuffers();
	}

	sf2d_free_texture(ic_allapps_pressed);
	
	return 0;
}
