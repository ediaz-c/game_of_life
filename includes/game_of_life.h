#ifndef GAME_H
# define GAME_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "keycodes.h"

# define WIDTH 800
# define HEIGHT 600
# define CELL_WIDTH 20
# define CELL_HEIGHT 20
# define DEAD '0'
# define ALIVE '1'

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_cell
{
	t_img	*dead;
	t_img	*alive;
}	t_cell;

typedef struct	s_game
{
	t_mlx	mlx;
	t_cell	cell;
	char	**map;
	t_img	bg;
	int		pause;
	int		change;
}	t_game;

/* map.c */
int		create_map(t_game *game);
/* cells.c */
int		create_cells(t_game *game);

/* background.c*/
int		create_background(t_game *game);
/* game.c */
void	game_loop(t_game *game);
/* hooks.c */
int	close_window(t_game *game);
int	key_press(int keycode, t_game *game);
int mouse_click(int button, int x, int y, t_game *game);
/* print.c */
void	print_cells(t_game *game);
char	**update_map(t_game *game);

char	**new_mtx(void);
void	free_mtx(char **mtx);
#endif