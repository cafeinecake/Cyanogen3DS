#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "language.h"
#include "lockScreen.h"
#include "powerMenu.h"
#include "settingsMenu.h"

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} settings_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} about_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} about_highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} display_highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} developeroptions_highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} performance_highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} security_highlight_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} wifi_highlight_img;

int aboutMenu()
{
	aboutBg = sf2d_create_texture_mem_RGBA8(about_img.pixel_data, about_img.width, about_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	highlight = sf2d_create_texture_mem_RGBA8(highlight_img.pixel_data, highlight_img.width, highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));
	
	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(aboutBg, 0, 0);
		
		sftd_draw_textf(roboto, 20, 68, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsAbout[language][0]);
		sftd_draw_textf(roboto, 20, 83, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsAbout[language][1]);
		sftd_draw_textf(roboto, 20, 116, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsAbout[language][2]);
		//sftd_draw_textf(roboto, 20, 132, RGBA8(0, 0, 0, 255), 12, "Model = NULL");
		sftd_draw_textf(roboto, 20, 168, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsAbout[language][5]);
		//sftd_draw_textf(roboto, 20, 183, RGBA8(0, 0, 0, 255), 12, "NinjaHax version: NULL");
		
		if (touch.px  >= 0 && touch.px  <= 480 && touch.py >= 58 && touch.py <= 105)
		{
			sf2d_draw_texture(highlight, 0, 56);
			sftd_draw_textf(roboto, 20, 68, RGBA8(0, 0, 0, 255), 12, "Cyanogen3DS Updates");
			sftd_draw_textf(roboto, 20, 83, RGBA8(0, 0, 0, 255), 12, "Click for, view or isntall available updates");
		}
		else if (touch.px  >= 0 && touch.px  <= 480 && touch.py >= 106 && touch.py <= 157)
		{
			sf2d_draw_texture(highlight, 0, 105);
			sftd_draw_textf(roboto, 20, 116, RGBA8(0, 0, 0, 255), 12, "Cyanogen3DS version: 0.01-20151019-UNOFFICIAL");
			sftd_draw_textf(roboto, 20, 132, RGBA8(0, 0, 0, 255), 12, "Model = NULL");
		}
		 
		digitalTime(350, 2); 
		batteryStatus(316, 2); 
		androidQuickSettings();
		cursorController();
		
		sf2d_end_frame();
		
		navbarControls(1);
		
		if (kDown & KEY_Y)
			powerMenu(); 
		
		if (kDown & KEY_L)
			lockScreen();
		
		if (kDown & KEY_B)
		{
			sf2d_free_texture(aboutBg);
			sf2d_free_texture(highlight);
			settingsMenu();
		}
		
		if ((touch.px  >= 44 && touch.px  <= 119 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_A))
		{
			sf2d_free_texture(aboutBg);
			sf2d_free_texture(highlight);
			settingsMenu();
		}
		
		else if ((touch.px  >= 120 && touch.px  <= 195 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_A))
		{
			sf2d_free_texture(aboutBg);
			sf2d_free_texture(highlight);
			home();
		}
		
		sf2d_swapbuffers();
	}
	
	sf2d_free_texture(aboutBg);
	sf2d_free_texture(highlight);

	return 0;
}

int settingsHighlight()
{
	u32 kDown = hidKeysDown();

	if (touch.px  >= 0 && touch.px  <= 198 && touch.py >= 75 && touch.py <= 133)
	{
		sf2d_draw_texture(wifi_highlight, 0, 87);
		sftd_draw_textf(roboto, 48, 106, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][0]);
		/*if (kDown & KEY_A)
		{
			settingsUnload();
		}*/
	}
	else if (touch.px  >= 0 && touch.px  <= 198 && touch.py >= 134 && touch.py <= 174)
	{
		sf2d_draw_texture(display_highlight, 0, 135);
		sftd_draw_textf(roboto, 48, 153, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][1]);
		/*if (kDown & KEY_A)
		{
			settingsUnload();
		}*/
	}
	else if (touch.px  >= 0 && touch.px  <= 198 && touch.py >= 175 && touch.py <= 240)
	{
		sf2d_draw_texture(developeroptions_highlight, 0, 183);
		sftd_draw_textf(roboto, 48, 202, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][2]);
		/*if (kDown & KEY_A)
		{
			settingsUnload();
		}*/
	}
	else if (touch.px  >= 203 && touch.px  <= 400 && touch.py >= 75 && touch.py <= 133)
	{
		sf2d_draw_texture(security_highlight, 199, 87);
		sftd_draw_textf(roboto, 250, 106, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][3]);
		/*if (kDown & KEY_A)
		{
			settingsUnload();
		}*/
	}
	else if (touch.px  >= 203 && touch.px  <= 400 && touch.py >= 134 && touch.py <= 174)
	{
		sf2d_draw_texture(performance_highlight, 203, 135);
		sftd_draw_textf(roboto, 250, 153, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][4]);
		/*if (kDown & KEY_A)
		{
			settingsUnload();
		}*/
	}
	else if (touch.px  >= 203 && touch.px  <= 400 && touch.py >= 175 && touch.py <= 240)
	{
		sf2d_draw_texture(about_highlight, 203, 183);
		sftd_draw_textf(roboto, 250, 202, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][5]);
		if (kDown & KEY_TOUCH)
		{
			settingsUnload();
			aboutMenu();
		}
	}
	
	return 0;
}

int settingsUnload()
{
	sf2d_free_texture(settingsBg);
	sf2d_free_texture(about_highlight);
	sf2d_free_texture(display_highlight);
	sf2d_free_texture(developeroptions_highlight);
	sf2d_free_texture(performance_highlight);
	sf2d_free_texture(security_highlight);
	sf2d_free_texture(wifi_highlight);
	
	return 0;
}

int settingsMenu()
{
	settingsBg = sf2d_create_texture_mem_RGBA8(settings_img.pixel_data, settings_img.width, settings_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	about_highlight = sf2d_create_texture_mem_RGBA8(about_highlight_img.pixel_data, about_highlight_img.width, about_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	display_highlight = sf2d_create_texture_mem_RGBA8(display_highlight_img.pixel_data, display_highlight_img.width, display_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	developeroptions_highlight = sf2d_create_texture_mem_RGBA8(developeroptions_highlight_img.pixel_data, developeroptions_highlight_img.width, developeroptions_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	performance_highlight = sf2d_create_texture_mem_RGBA8(performance_highlight_img.pixel_data, performance_highlight_img.width, performance_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	security_highlight = sf2d_create_texture_mem_RGBA8(security_highlight_img.pixel_data, security_highlight_img.width, security_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	wifi_highlight = sf2d_create_texture_mem_RGBA8(wifi_highlight_img.pixel_data, wifi_highlight_img.width, wifi_highlight_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));
	
	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(settingsBg, 0, 0);
		
		sftd_draw_textf(roboto, 48, 106, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][0]);
		sftd_draw_textf(roboto, 48, 153, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][1]);
		sftd_draw_textf(roboto, 48, 202, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][2]);
		sftd_draw_textf(roboto, 250, 106, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][3]);
		sftd_draw_textf(roboto, 250, 153, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][4]);
		sftd_draw_textf(roboto, 250, 202, RGBA8(0, 0, 0, 255), 12, "%s", lang_settingsMain[language][5]);
		
		settingsHighlight();
		
		digitalTime(350, 2); 
		batteryStatus(316, 2); 
		androidQuickSettings();
		cursorController();
		
		sf2d_end_frame();
		
		navbarControls(1); 
		
		if (kDown & KEY_Y)
			powerMenu(); 
		
		if (kDown & KEY_L)
			lockScreen();
		
		if (kDown & KEY_B)
		{
			settingsUnload();
			appDrawer();
		}
		
		if ((touch.px  >= 44 && touch.px  <= 119 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_A))
		{
			settingsUnload();
			appDrawer();
		}
		
		else if ((touch.px  >= 120 && touch.px  <= 195 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_A))
		{
			settingsUnload();
			home();
		}
		
		sf2d_swapbuffers();
	}
	
	settingsUnload();
	
	return 0;
}
