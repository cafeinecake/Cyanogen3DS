#include "clock.h"
#include "gfx.h"
#include "home.h"
#include "powerMenu.h"

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} power_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} power1_img;

int powerMenu()
{
	power = sf2d_create_texture_mem_RGBA8(power_img.pixel_data, power_img.width, power_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	power1 = sf2d_create_texture_mem_RGBA8(power1_img.pixel_data, power1_img.width, power1_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		
		sf2d_draw_texture(background, 0, 0);
		
		sf2d_draw_texture(ic_launcher_browser, 49, 135);
		sf2d_draw_texture(ic_launcher_messenger, 114, 135);
		sf2d_draw_texture(ic_allapps, 179, 148);
		sf2d_draw_texture(ic_launcher_apollo, 241, 135);
		sf2d_draw_texture(ic_launcher_settings, 306, 135);
		sf2d_draw_texture(navbar, 70, 201);

		sf2d_draw_texture(power, 62, 90);
		if (touch.px  >= 62 && touch.px  <= 338 && touch.py >= 70 && touch.py <= 149)
		{
			sf2d_draw_texture(power1, 62, 90);
			if (kDown & KEY_A)
				break;
		}	
		
		digitalTime(350, 2); 
		batteryStatus(316, 2); 
		cursorController();
		
		sf2d_end_frame();
		
		if (kDown & KEY_B)
		{
			sf2d_free_texture(power);
			sf2d_free_texture(power1);
			return 1;
		}
		
		sf2d_swapbuffers();
	}
	
	sf2d_free_texture(power);
	sf2d_free_texture(power1);
	
	return 0;
}
