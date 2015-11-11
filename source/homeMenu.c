#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "language.h"
#include "lockScreen.h"
#include "main.h"
#include "powerMenu.h"
#include "settingsMenu.h"

int notif_y = -240;
int yPos1 = -240;
int yPos2 = -240;
int yLine1 = -240;
int yLine2 = -240;

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

	sf2d_draw_texture(_100, 300, y);
	sftd_draw_textf(roboto, x, y, RGBA8(255, 255, 255, 255), 12, "%d%%", batt);
	
	return 0;
}

void appDrawerIcon() //Draws the app drawer icon. Draws a different icon of the same size once hovered with the cursor.
{
	if (touch.px  >= 170 && touch.px  <= 210 && touch.py >= 145 && touch.py <= 190)
		sf2d_draw_texture(ic_allapps_pressed, 179, 158);
	
	else
		sf2d_draw_texture(ic_allapps, 179, 158);
}

int navbarControls(int type)
{
	if (type == 0)
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
	}
	
	else if (type == 1)
	{
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		
		if (touch.px  >= 44 && touch.px  <= 119 && touch.py >= 201 && touch.py <= 240)
			sf2d_draw_texture(backicon, 30, 201);
		else
			sf2d_draw_texture(navbar, 30, 201);

		if (touch.px  >= 120 && touch.px  <= 195 && touch.py >= 201 && touch.py <= 240)
			sf2d_draw_texture(homeicon, 30, 201);
		else
			sf2d_draw_texture(navbar, 30, 201);
	
		if (touch.px  >= 196 && touch.px  <= 271 && touch.py >= 201 && touch.py <= 240)
			sf2d_draw_texture(multicon, 30, 201);
		else
			sf2d_draw_texture(navbar, 30, 201);
			
		sf2d_end_frame();
	}
	
	return 0;
}

void androidQuickSettings()
{
	u32 kDown = hidKeysDown();
	u32 kHeld = hidKeysHeld();

	int notif_up;
	int notif_down;
	int notif_enabled;
	
	sf2d_draw_texture(quickSettings, 0, notif_y);
	
	batteryStatus(350, yPos2-4);
	
	sftd_draw_textf(roboto, 115, yLine1, RGBA8(255, 255, 255, 255), 10, "%s", lang_quickSettings[language][0]);
	sftd_draw_textf(roboto, 245, yLine1, RGBA8(255, 255, 255, 255), 10, "%s", lang_quickSettings[language][2]);
	sftd_draw_textf(roboto, 170, yLine2, RGBA8(255, 255, 255, 255), 10, "%s", lang_quickSettings[language][4]);
	
	digitalTime(25, yPos1);
	getMonthOfYear(25, yPos1+14, 10);

	notif_enabled = 0;
	
	if ((kHeld & KEY_TOUCH) && (touch.px >= 0 && touch.px <= 400 && touch.py >= 0 && touch.py <= 20)) 
	{
		notif_down = 1;
	}

	else if ((kHeld & KEY_TOUCH) && (touch.px >= 0 && touch.px <= 400 && touch.py >= 220 && notif_y == 0))
	{
		notif_up = 1;
	}
			
	if (notif_down == 1)
	{				
		if ((kHeld & KEY_TOUCH) && (touch_y >= 50))
		{
			notif_y = notif_y+6;
			yPos1 = yPos1+6;
			yPos2 = yPos2+6;
			yLine1 = yLine1+6;
			yLine2 = yLine2+6;
		}
		
		if (notif_y >= 0)
		{
			notif_y = 0;
		}
		
		if (yPos1 >= 10)
		{
			yPos1 = 10;
		}
		if (yPos2 >= 20)
		{
			yPos2 = 20;
		}
		if (yLine1 >= 155)
		{
			yLine1 = 155;
		}
		if (yLine2 >= 220)
		{
			yLine2 = 220;
		}
		if (yLine2 >= 200)
		{
			notif_enabled = 1;
		}
	}
	
	if (notif_enabled == 1)
	{	
		if ((touch.px >= 386 && touch.px <= 414 && touch.py >= 12 && touch.py <= 38) && (kDown & KEY_TOUCH))
		{	 
			notif_y = notif_y-240;
			yPos1 = yPos1-240;
			yPos2 = yPos2-240;
			yLine1 = yLine1-240;
			yLine2 = yLine2-240;
			settingsMenu();
		}
		
		if ((touch.px >= 198 && touch.px <= 240 && touch.py >= 204 && touch.py <= 258) && (kDown & KEY_TOUCH))
		{
			notif_y = notif_y-240;
			yPos1 = yPos1-240;
			yPos2 = yPos2-240;
			yLine1 = yLine1-240;
			yLine2 = yLine2-240;
			lockScreen();
		}
	}
	if ((notif_down == 1) && (kDown & KEY_B))
	{
		notif_y = notif_y-240;
		yPos1 = yPos1-240;
		yPos2 = yPos2-240;
		yLine1 = yLine1-240;
		yLine2 = yLine2-240;
	}
	
	if (notif_up == 1)
	{		
		notif_enabled = 0;
		
		if ((kHeld & KEY_TOUCH) && (touch_y <= 50))
		{
			notif_y = notif_y-6;
			yPos1 = yPos1-6;
			yPos2 = yPos2-6;
			yLine1 = yLine1-6;
			yLine2 = yLine2-6;
		}
		
		if (notif_y <= -240)
		{	
			notif_y = -240;
			yPos1 = -240;
			yPos2 = -240;
			yLine1 = -240;
			yLine2 = -240;
		}
	}
}

int dayNightWidget()
{
	time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);

	int hours = timeStruct->tm_hour;
	int minutes = timeStruct->tm_min;
	
	if (hours < 6)
		sf2d_draw_texture(dayWidget, 172, 60);
	else
		sf2d_draw_texture(nightWidget, 167, 60);
		
	sftd_draw_textf(roboto, 142, 20, RGBA8(255, 255, 255, 255), 34, "0%2d : %02d", hours, minutes);
	sftd_draw_textf(roboto, 130, 80, RGBA8(255, 255, 255, 255), 10, "Tuesday");
	getMonthOfYear(230, 80, 10);
	
	return 0;
}

int home()
{
	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));

	ic_allapps = sf2d_create_texture_mem_RGBA8(ic_allapps_img.pixel_data, ic_allapps_img.width, ic_allapps_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
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
		
		sf2d_draw_texture(ic_launcher_browser, 49, 145);
		sf2d_draw_texture(ic_launcher_messenger, 114, 145);
		sf2d_draw_texture(ic_launcher_apollo, 241, 145);
		sf2d_draw_texture(ic_launcher_settings, 306, 145);
		appDrawerIcon();

		dayNightWidget();
		
		navbarControls(0); //Displays navbar
		digitalTime(350, 2); //Displays digital time
		batteryStatus(316, 2); //Displays battery status
		androidQuickSettings();
		cursorController();
		
		sf2d_end_frame();
		
		if ((touch.px  >= 170 && touch.px  <= 210 && touch.py >= 148 && touch.py <= 190) && (kDown & KEY_TOUCH))
		{
			sf2d_free_texture(ic_allapps);
			sf2d_free_texture(ic_allapps_pressed);
			appDrawer(); //Opens app drawer
		}
		
		if ((touch.px  >= 306 && touch.px  <= 351 && touch.py >= 145 && touch.py <= 190) && (kDown & KEY_TOUCH))
		{
			sf2d_free_texture(ic_allapps);
			sf2d_free_texture(ic_allapps_pressed);
			settingsMenu(); //Opens settings menu
		}
		
		if (kDown & KEY_Y)
			powerMenu(); //Opens power menu
		
		if (kDown & KEY_L)
			lockScreen(); //Takes you to lock screen

		// Flush and swap framebuffers
		sf2d_swapbuffers();
	}

	sf2d_free_texture(ic_allapps);
	sf2d_free_texture(ic_allapps_pressed);
	
	return 0;
}
