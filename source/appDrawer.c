#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "language.h"
#include "lockScreen.h"
#include "powerMenu.h"
#include "settingsMenu.h"

void appDrawerUnload()
{
	sf2d_free_texture(backdrop);
	sf2d_free_texture(ic_launcher_clock);
	sf2d_free_texture(ic_launcher_filemanager);
	sf2d_free_texture(ic_launcher_gallery);
	sf2d_free_texture(ic_launcher_game);
}

int appDrawer()
{	
	backdrop = sf2d_create_texture_mem_RGBA8(backdrop_img.pixel_data, backdrop_img.width, backdrop_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_clock = sf2d_create_texture_mem_RGBA8(ic_launcher_clock_img.pixel_data, ic_launcher_clock_img.width, ic_launcher_clock_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_filemanager = sf2d_create_texture_mem_RGBA8(ic_launcher_filemanager_img.pixel_data, ic_launcher_filemanager_img.width, ic_launcher_filemanager_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_gallery = sf2d_create_texture_mem_RGBA8(ic_launcher_gallery_img.pixel_data, ic_launcher_gallery_img.width, ic_launcher_gallery_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_launcher_game = sf2d_create_texture_mem_RGBA8(ic_launcher_game_img.pixel_data, ic_launcher_game_img.width, ic_launcher_game_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	sf2d_set_clear_color(RGBA8(0, 0, 0, 0));
	
	while (aptMainLoop())
	{	
		hidScanInput();
		
		u32 kDown = hidKeysDown();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(background, 0, 0);
		sf2d_draw_texture(backdrop, 0, 14);

		sf2d_draw_texture(ic_launcher_browser, 20, 35);
		sftd_draw_textf(roboto, 18, 90, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][0]);
		sf2d_draw_texture(ic_launcher_clock, 95, 35);
		sftd_draw_textf(roboto, 98, 90, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][1]);
		sf2d_draw_texture(ic_launcher_filemanager, 170, 35);
		sftd_draw_textf(roboto, 167, 90, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][2]);
		sf2d_draw_texture(ic_launcher_gallery, 245, 35);
		sftd_draw_textf(roboto, 247, 90, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][3]);
		sf2d_draw_texture(ic_launcher_game, 320, 35);
		sftd_draw_textf(roboto, 325, 90, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][4]);
		sf2d_draw_texture(ic_launcher_messenger, 20, 115);
		sftd_draw_textf(roboto, 16, 170, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][5]);
		sf2d_draw_texture(ic_launcher_apollo, 95, 115);
		sftd_draw_textf(roboto, 98, 170, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][6]);
		sf2d_draw_texture(ic_launcher_settings, 170, 115);
		sftd_draw_textf(roboto, 167, 170, RGBA8(0, 0, 0, 255), 12, "%s", lang_appDrawer[language][7]);
		
		navbarControls(0);
		digitalTime(350, 2); 
		batteryStatus(316, 2);
		androidQuickSettings();		
		cursorController();
		
		sf2d_end_frame();
		
		if (kDown & KEY_Y)
			powerMenu(); 
		
		if (kDown & KEY_L)
			lockScreen();
		
		if ((touch.px  >= 170 && touch.px  <= 215 && touch.py >= 115 && touch.py <= 160) && (kDown & KEY_TOUCH))
		{
			appDrawerUnload();
			settingsMenu();
		}
		
		//Navbar controls
		if ((touch.px  >= 84 && touch.px  <= 159 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_TOUCH))
		{
			appDrawerUnload();
			home(); // Pressing the back icon - takes you back to the homescreen
		}
		
		//Navbar controls
		else if ((touch.px  >= 160 && touch.px  <= 235 && touch.py >= 201 && touch.py <= 240) && (kDown & KEY_TOUCH))
		{
			appDrawerUnload();
			home(); // Pressing the home icon always returns to the home screen
		}
		
		if (kDown & KEY_B)
		{
			appDrawerUnload();
			home(); //Returns to home screen
		}
		
		sf2d_swapbuffers();	
	}
	
	appDrawerUnload();
	
	return 0;
}