#include "main.h"
#include "gfx.h"
#include "home.h"

int main(int argc, char **argv)
{
	sf2d_init();
	
	// Font loading
	sftd_init();	
	
	roboto = sftd_load_font_mem(Roboto_ttf, Roboto_ttf_size); //Loads font

	//Loading images
	background = sf2d_create_texture_mem_RGBA8(background_img.pixel_data, background_img.width, background_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	backdrop = sf2d_create_texture_mem_RGBA8(backdrop_img.pixel_data, backdrop_img.width, backdrop_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	cursor = sf2d_create_texture_mem_RGBA8(cursor_img.pixel_data, cursor_img.width, cursor_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	ic_allapps = sf2d_create_texture_mem_RGBA8(ic_allapps_img.pixel_data, ic_allapps_img.width, ic_allapps_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	navbar = sf2d_create_texture_mem_RGBA8(navbar_img.pixel_data, navbar_img.width, navbar_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	backicon = sf2d_create_texture_mem_RGBA8(backicon_img.pixel_data, backicon_img.width, backicon_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	homeicon = sf2d_create_texture_mem_RGBA8(homeicon_img.pixel_data, homeicon_img.width, homeicon_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	multicon = sf2d_create_texture_mem_RGBA8(multicon_img.pixel_data, multicon_img.width, multicon_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	dayWidget = sf2d_create_texture_mem_RGBA8(day_img.pixel_data, day_img.width, day_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	nightWidget = sf2d_create_texture_mem_RGBA8(night_img.pixel_data, night_img.width, night_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	_100 = sf2d_create_texture_mem_RGBA8(_100_img.pixel_data, _100_img.width, _100_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	// Main loop
	while (aptMainLoop())
	{
		home();
	}

	sftd_fini();
	sf2d_fini();
	return 0;
}
