/*
** wolf3d.h for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 09:40:20 2015 puente_t
** Last update Sun Dec 27 11:52:00 2015 puente_t
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define END	3
# define DEAD	4
# define EXIT_ESC 10

# define SCOPE lev->level
# define WIN_X 1000
# define WIN_Y 1000
# define UNIT 10000
# define MOVE 5
# define SPRINT 10
# define WALL_WIDTH wall->clipable.clip_height
# define SKY_WIDTH sky->clipable.clip_height

# define MAP_SIZE map->mini_map
# define MAP_GROUND WHITE
# define MAP_WALL 0x5F5F5F
# define MAP_H_WALL 0x505050
# define PLAYER_MAP RED
# define MAP map->data
# define MINI_MAP MAP[pos[0].y][pos[0].x]
# define FOV (double)(0.5)

# define TILE_IS MAP[tmp.y][tmp.x]
# define VICTORY_DELAY 4
# define DEATH_DELAY 6

# define HELP_FIRST "Reach the finish line before time run out"
# define HELP_SECOND "Press arrow to move around"
# define HELP_THIRD "Press M to expand the mini map"
# define HELP_LAST "Press e to destroy breakebleable block"
# define HELP_LAST2 "in front of you"

typedef struct		s_cut
{
  int			k;
  int			cut;
  int			block;
}			t_cut;

typedef struct		s_level
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  char			level[4];
  t_bunny_pixelarray	*text;
  char			mouse;
  char			aa;
}			t_level;

typedef struct		s_pl_pos
{
  int			x;
  int			y;
  int			o_x;
  int			o_y;
  double		gaze;
  int			status;
  int			timer;
  int			mtime;
}			t_pl_pos;

typedef struct		s_map
{
  char			**data;
  int			x;
  int			y;
  int			mini_map;
  int			status;
}
			t_map;

# define	PL_X	pl_pos->x
# define	PL_Y	pl_pos->y
# define	P_X	(pl_pos->x >> 6)
# define	P_Y	(pl_pos->y >> 6)
# define	GAZE	pl_pos->gaze
# define	Z(c, d) ((c >= 0 && d >= 0) ? (1) : (0))
# define	I(c, d, cm, dm) ((c < cm && d < dm) ? (1) : (0))

t_map			*reset_level(t_map *map);
double			vecnorm(t_pl_pos *coord0,
				int x, int y);
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);
int			print_map(t_pl_pos *pl_pos, t_map *map, t_bunny_pixelarray *pix);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
int			fdf_atoi(const char *str);

int			print_screen(t_pl_pos *pl_pos, t_map *map, t_bunny_pixelarray *pix);
void			free_array(char **array, int h);
t_map			*load_map(t_bunny_ini *ini, t_pl_pos *pl_pos, t_level *lev, t_map *map);
t_pl_pos		*init_player(t_bunny_ini *ini,
				     t_pl_pos *pl_pos,
				     t_map *map,
				     t_level *lev);
int			get_status(t_pl_pos *pl_pos, t_map *mapo, t_bunny_pixelarray *pix);

t_bunny_pixelarray	*load_bitmap(const char *file);
typedef struct		s_bitheader
{
  short			type;
  int			size;
  int			empty;
  int			offset;
  int			size_head;
  int			width;
  int			height;
  short			nb_bit;
  short			byte_pix;
  int			compress;
  int			bytesize;
  int			ppi_y;
  int			ppi_x;
  int			palette_size;
  int			imp_color;
}			__attribute__((packed)) t_bitheader;

int			death_victory(t_pl_pos *pl_pos, t_map *map);

void			stretch(t_bunny_pixelarray *pix,
				const t_bunny_pixelarray *ori);
t_color			getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos);
int			degrade(t_bunny_pixelarray *pix, unsigned int color, char *str);
void			tekwrite(t_bunny_pixelarray *pix,
				 t_bunny_position start,
				 t_color colo,
				 char *str);
char			**menu_init();
void			bunny_my_fill(t_bunny_pixelarray *pix, unsigned int color);

int			move_cur(int cur);
t_pl_pos		*move(t_pl_pos *pl_pos, t_map *map, t_level *level);
int			walking(int is);

t_bunny_response	exit_esc(t_bunny_event_state state,
				 t_bunny_keysym key,
				 void *_win);

int			main_game(t_level *lev);
t_bunny_response	menu(void *_win);

void			tekpixel_(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  t_color color);
void			tekwrite_s(t_bunny_pixelarray *pix,
				   t_bunny_position start,
				   unsigned int colo,
				   char *str);
void			bunny_my_blit(t_bunny_position *po,
				      t_bunny_pixelarray *dest,
				      t_bunny_pixelarray *ori);
t_bunny_pixelarray	*choose_wall(t_cut ret);
char			my_revatoi(int nb, t_map *map, t_bunny_pixelarray *pix);
int			bunny_my_fill_wolf(t_bunny_pixelarray *pix);

void			tekwritec(t_bunny_pixelarray *pix,
				  t_bunny_position start,
				  t_color colo,
				  char str);

int			help_menu(t_level *level);
t_color			getpixel_shadowed(t_bunny_pixelarray *pix,
					  t_bunny_position *p, int k);
int			menu_select(int ret, t_level *level);
t_bunny_response	mouse(const t_bunny_position *relative,
			      void *dat);
int			antialias(t_bunny_pixelarray *pix);

#endif /* !WOLF3D_H_ */
