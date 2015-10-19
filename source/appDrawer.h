#include <3ds.h>
#include <sf2d.h>

sf2d_texture *ic_launcher_clock;
sf2d_texture *ic_launcher_filemanager;
sf2d_texture *ic_launcher_gallery;
sf2d_texture *ic_launcher_game;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_clock_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_filemanager_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_gallery_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_game_img;

void appDrawerUnload();
int appDrawer();