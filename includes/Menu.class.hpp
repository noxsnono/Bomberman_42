#ifndef MENU_CLASS_HPP
# define MENU_CLASS_HPP

# include <ft42.class.hpp>

enum MENU_SELECTED {
  RESUME_GAME = 0,
  MENU_CAMPAIGN,
  MENU_ARENA,
  MENU_MULTIPLAYER,
  MENU_CONFIG,
  MENU_EXIT,

  MENU_CAMPAIGN_NEW,
  MENU_CAMPAIGN_CONTINUE,
  MENU_CAMPAIGN_COOP,
  MENU_CAMPAIGN_RETURN,
  MENU_ARENA_2P,
  MENU_ARENA_3P,
  MENU_ARENA_4P,
  MENU_ARENA_RETURN,
  MENU_MULTI_2P,
  MENU_MULTI_3P,
  MENU_MULTI_4P,
  MENU_MULTI_RETURN,
  MENU_CONFIG_NAME,
  MENU_CONFIG_NAMEA,
  MENU_CONFIG_NAMEB,
  MENU_CONFIG_RETURN,
  MENU_EXIT_CONFIRM,
  MENU_EXIT_RETURN

};

enum MENU_SELECTED_PRINCIPAL {
  BIG_MENU = 0,
  CAMPAIGN,
  ARENA,
  MULTIPLAYER,
  CONFIG,
  EXIT
};
class Event;

class Menu : public ft42 {
public:

  Event *         event;
  SDL_Surface *   current;
  SDL_Surface *   ecran_menu;
  bool            introstart;
  bool            launch_action;
  TTF_Font *      SansPosterBold;
  SDL_GameController * manette1;

  SDL_Color       white;
  SDL_Color       blue;
  SDL_Color       red;
  SDL_Rect        position;

  int             menu_selected;
  int             detail_menu_selected;
  SDL_Surface *   str_return;
  SDL_Surface *   str_return_selected;
  SDL_Surface *   str_resume_game;
  SDL_Surface *   str_resume_game_selected;
  SDL_Surface *   str_campaign;
  SDL_Surface *   str_campaign_selected;
  SDL_Surface *   str_campaign_new;
  SDL_Surface *   str_campaign_new_selected;
  SDL_Surface *   str_campaign_coop;
  SDL_Surface *   str_campaign_coop_selected;
  SDL_Surface *   str_campaign_continue;
  SDL_Surface *   str_campaign_continue_selected;
  SDL_Surface *   str_arena;
  SDL_Surface *   str_arena_selected;
  SDL_Surface *   str_multiplayer;
  SDL_Surface *   str_multiplayer_selected;
  SDL_Surface *   str_2players;
  SDL_Surface *   str_2players_selected;
  SDL_Surface *   str_3players;
  SDL_Surface *   str_3players_selected;
  SDL_Surface *   str_4players;
  SDL_Surface *   str_4players_selected;
  SDL_Surface *   str_5players;
  SDL_Surface *   str_5players_selected;
  SDL_Surface *   str_config;
  SDL_Surface *   str_config_selected;
  SDL_Surface *   str_exit;
  SDL_Surface *   str_exit_selected;
  SDL_Surface *   str_exit_confirm;
  SDL_Surface *   str_exit_confirm_selected;





  Menu(Event * event);
  virtual ~Menu();

  void            campaign();
  void            config();
  void            arena();
  void            multiplayer();
  void            exit_game();
  void            exit_confirm();
  void            intro_start() ;
  void            main_loop();
  void            menu_keyboard();
  void            big_menu();
  void            init();
  void            print_surface(SDL_Surface * str, SDL_Surface * str_select, int x, int y, int type);
  void            move_menu_ver(int dir);
  void            menu_selection();
  void            change_menu();

private:
  Menu( void );
};

#endif
