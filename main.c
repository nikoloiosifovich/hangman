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
int i, done = 0;

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

// --> ToLoadSprites
void load_sprites(BITMAP *sprites[]){

  char path_sprites[][23] = {
    "src/sprites/live01.bmp", "src/sprites/live02.bmp",
    "src/sprites/live03.bmp", "src/sprites/live04.bmp",
    "src/sprites/live05.bmp", "src/sprites/live06.bmp",

    "src/sprites/dead01.bmp", "src/sprites/dead02.bmp",
    "src/sprites/dead03.bmp", "src/sprites/dead04.bmp",
    "src/sprites/dead05.bmp", "src/sprites/dead06.bmp"
  };
  for(i=0;i<12;i++){
    sprites[i] = load_bitmap(path_sprites[i], NULL);
  }
}

// Main Game
int main(){

  allegro_start("Hangman v0.1 - @Nikölo", 640, 480);

  BITMAP *buffer, *sprites[13];

  buffer = create_bitmap(screen->w, screen->h);
  load_sprites(sprites);

  // Loop Game
  while(!done){

    if(key[KEY_ESC]){ end(); }


    update_screen(buffer);
  }

  return 0;
}
