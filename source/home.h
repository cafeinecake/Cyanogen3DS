#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <3ds.h>
#include <sf2d.h>
#include <sftd.h>

#include "Roboto_ttf.h"

sftd_font *roboto;

sf2d_texture *background;
sf2d_texture *backdrop;
sf2d_texture *cursor;

//App icon assets
sf2d_texture *ic_allapps;
sf2d_texture *ic_allapps_pressed;
sf2d_texture *ic_launcher_browser;
sf2d_texture *ic_launcher_messenger;
sf2d_texture *ic_launcher_apollo;
sf2d_texture *ic_launcher_settings;

// Navbar Assets
sf2d_texture *navbar;
sf2d_texture *backicon;
sf2d_texture *homeicon;
sf2d_texture *multicon;

// Battery Icon assets (1-5)
sf2d_texture *_100;
sf2d_texture *_80;
sf2d_texture *_60;
sf2d_texture *_40;
sf2d_texture *_20;

// Widget Assets
sf2d_texture *dayWidget;
sf2d_texture *nightWidget;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} background_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} backdrop_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_browser_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_messenger_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_apollo_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_launcher_settings_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} navbar_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} backicon_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} homeicon_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} multicon_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} ic_allapps_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} _100_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} cursor_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} day_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} night_img;

u16 touch_x;
u16 touch_y;
touchPosition touch;

int cursorController();
int batteryStatus(int x, int y);
void appDrawerIcon();
int navbarControls();
int dayNightWidget();
int home();