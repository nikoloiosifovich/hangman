/*
    A C + allegro4 Game, created by
    Vieira Neto AKA Nikölo Iosifovich
    version 0.1-rev_20191110
*/

// Includes
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

// Global vars
int done = 0;

// Functions
// --> ToCloseGame
void end(){ done = 1; }

// --> ToRunAllegro
void allegro_start(char *title, int width, int height){

  allegro_init();
  set_color_depth(24);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);
  set_window_title(title);
  set_close_button_callback(end);

  install_keyboard();
  install_mouse();
  install_timer();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
}

// --> ToDrawAllOnScreen
void update_screen(BITMAP *buffer){

  draw_sprite(screen, buffer, 0, 0);
  rest(10);
  clear(buffer);
}

// Main Game
int main(){

  allegro_start("Hangman v0.1 - @Nikölo", 640, 480);

  BITMAP *buffer;
  buffer = create_bitmap(screen->w, screen->h);

  // Loop Game
  while(!done){

    if(key[KEY_ESC]){ end(); }


    update_screen(buffer);
  }

  return 0;
}
