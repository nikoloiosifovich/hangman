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
int i, j, done = 0;

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

// --> ToLoadKeysForKeyboard
void load_keys(BITMAP *keys[]){
  
  char path_keys[][16] = {
    "src/keys/aN.bmp", "src/keys/bN.bmp", "src/keys/cN.bmp",
    "src/keys/dN.bmp", "src/keys/eN.bmp", "src/keys/fN.bmp",
    "src/keys/gN.bmp", "src/keys/hN.bmp", "src/keys/iN.bmp",
    "src/keys/jN.bmp", "src/keys/kN.bmp", "src/keys/lN.bmp",
    "src/keys/mN.bmp", "src/keys/nN.bmp", "src/keys/oN.bmp",
    "src/keys/pN.bmp", "src/keys/qN.bmp", "src/keys/rN.bmp",
    "src/keys/sN.bmp", "src/keys/tN.bmp", "src/keys/uN.bmp",
    "src/keys/vN.bmp", "src/keys/wN.bmp", "src/keys/xN.bmp",
    "src/keys/yN.bmp", "src/keys/zN.bmp",

    "src/keys/aH.bmp", "src/keys/bH.bmp", "src/keys/cH.bmp",
    "src/keys/dH.bmp", "src/keys/eH.bmp", "src/keys/fH.bmp",
    "src/keys/gH.bmp", "src/keys/hH.bmp", "src/keys/iH.bmp",
    "src/keys/jH.bmp", "src/keys/kH.bmp", "src/keys/lH.bmp",
    "src/keys/mH.bmp", "src/keys/nH.bmp", "src/keys/oH.bmp",
    "src/keys/pH.bmp", "src/keys/qH.bmp", "src/keys/rH.bmp",
    "src/keys/sH.bmp", "src/keys/tH.bmp", "src/keys/uH.bmp",
    "src/keys/vH.bmp", "src/keys/wH.bmp", "src/keys/xH.bmp",
    "src/keys/yH.bmp", "src/keys/zH.bmp",

    "src/keys/00.bmp" 
  };
  for(i=0;i<53;i++){
    keys[i] = load_bitmap(path_keys[i], NULL);
  }
}

// --> ToLoadButtons
void load_buttons(BITMAP *buttons[]){

  char path_buttons[][24] = {
    "src/buttons/bt_play.bmp", "src/buttons/bt_cred.bmp",
    "src/buttons/bt_plyH.bmp", "src/buttons/bt_crdH.bmp"
  };
  for(i=0;i<4;i++){
    buttons[i] = load_bitmap(path_buttons[i], NULL);
  }
}

// --> ToLoadMouseAsSprite
void load_cursor(BITMAP *mouse[]){

  char path_mouse_cursor[][23] = {
    "src/sprites/cursor.bmp"
  };
  for(i=0;i<1;i++){
    mouse[i] = load_bitmap(path_mouse_cursor[i], NULL);
  }
}

// --> ToLoadStagesBackgrounds
void load_backgrounds(BITMAP *backgrounds[]){

  char path_backgrounds[][19] = {
    "src/bgs/tela01.bmp", "src/bgs/tela02.bmp", 
    "src/bgs/tela03.bmp", "src/bgs/tela04.bmp"
  };
  for(i=0;i<4;i++){
    backgrounds[i] = load_bitmap(path_backgrounds[i], NULL);
  }
}

// --> ToChangeMouseCursorSysForMouseGameSprite
void v_mouse(BITMAP *buffer, BITMAP *cursor[], int mouse_x, int mouse_y){

  for(i=0;i<1;i++){
    draw_sprite(buffer, cursor[i], mouse_x, mouse_y);
  }
}

// --> ToDrawKeyboard
void v_keyboard(BITMAP *buffer, BITMAP *keys[], int start_x, int start_y){

  for(i=0;i<3;i++){
    for(j=0;j<9;j++){
      if(j==0){
        draw_sprite(buffer, keys[j+i*9], start_x, start_y+40*i);
      }else{
        if(j+i*9 != 26) draw_sprite(buffer, keys[j+i*9], start_x+40*j, start_y+40*i);
      }
    }
  }
}

// --> ToDrawButtonsWithMouseHoverEffect
void v_buttons(BITMAP *buffer, BITMAP *buttons[], int start_x, int start_y){

  for(i=0;i<2;i++){
    if(mouse_x>start_x && mouse_x<start_x+150 &&
       mouse_y>start_y+45*i && mouse_y<start_y+40+(45*i)){

      draw_sprite(buffer, buttons[i+2], start_x, start_y+(45*i));
    }else{
      draw_sprite(buffer, buttons[i], start_x, start_y+(45*i));
    }
  }
}

// --> ToDrawHangman
void v_sprites(BITMAP *buffer, BITMAP *sprites[]){

  draw_sprite(buffer, sprites[0], sprites[2]->cr, sprites[0]->ct);
  draw_sprite(buffer, sprites[1], sprites[2]->cr, sprites[0]->cb);
  draw_sprite(buffer, sprites[2], sprites[2]->cl, sprites[0]->cb);
  draw_sprite(buffer, sprites[3], sprites[0]->cr+sprites[2]->cr, sprites[0]->cb);
  draw_sprite(buffer, sprites[4], sprites[2]->cr/2, sprites[0]->cb+sprites[1]->cb);
  draw_sprite(buffer, sprites[5], sprites[2]->cr/2+sprites[4]->cr, sprites[0]->cb+sprites[1]->cb);
}

// --> ToShowInteractionsForMouseXKeyboard
void interactions_mouse_v_keyboard(BITMAP *keys[], int sta_keys[][9], int start_x, int start_y){

  for(i=0;i<3;i++){
    for(j=0;j<9;j++){
      if(mouse_x>start_x+40*j && mouse_x<start_x+40*(j+1) &&
         mouse_y>start_y+40*i && mouse_y<start_y+40*(i+1) &&
         mouse_b==1 && sta_keys[i][j]!=1){

        sta_keys[i][j]=1;
        keys[j+i*9] = (sta_keys[i][j] == 1) ? keys[26+(j+i*9)] : keys[j+i*9];
      }
    }
  }
}

// --> Main Game
int main(){

  allegro_start("Hangman v0.1 - @Nikölo", 640, 480);

  BITMAP *buffer, *sprites[13], *keys[53], *buttons[4], *cursor[1], *backgrounds[4];
  int posX_keyboard = SCREEN_W/3, posY_keyboard = (SCREEN_H/3)*2;
  int posX_button = 60, posY_button = 325;
  int sta_keys[3][9];

  buffer = create_bitmap(screen->w, screen->h);
  load_sprites(sprites);
  load_keys(keys);
  load_buttons(buttons);
  load_cursor(cursor);
  load_backgrounds(backgrounds);

  for(i=0;i<3;i++){
    for(j=0;j<9;j++){
      sta_keys[i][j] = 0;
    }
  }


  // Loop Game
  while(!done){

    if(key[KEY_ESC]){ end(); }

    interactions_mouse_v_keyboard(keys, sta_keys, posX_keyboard, posY_keyboard);
    v_keyboard(buffer, keys, posX_keyboard, posY_keyboard);
    v_buttons(buffer, buttons, posX_button, posY_button);
    v_sprites(buffer, sprites);

    v_mouse(buffer, cursor, mouse_x, mouse_y);
    update_screen(buffer);
  }

  return 0;
}
