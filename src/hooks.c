#include "../includes/game_of_life.h"

int mouse_click(int button, int x, int y, t_game *game)
{
	char	**map;
	
	map = game->map;
	if (button == 1)
	{
		if (map[y / CELL_HEIGHT][x / CELL_WIDTH] == '0')
			map[y / CELL_HEIGHT][x / CELL_WIDTH] = '1';

	}
	else if (button == 2)
	{
		if (map[y / CELL_HEIGHT][x / CELL_WIDTH] == '1')
			map[y / CELL_HEIGHT][x / CELL_WIDTH] = '0';
	}
	print_cells(game);
	return (EXIT_SUCCESS);
}

int	key_press(int keycode, t_game *game)
{
	(void)game;
	// printf("keycode: %d\n", keycode);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_SPACE)
		game->pause = !game->pause;
	if (keycode == 8)
	{
		for (int i = 0; i < HEIGHT / CELL_HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH / CELL_WIDTH; j++)
				game->map[i][j] = '1';
		}
		print_cells(game);
	}
	if (keycode == 45)
	{
		for (int i = 0; i < HEIGHT / CELL_HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH / CELL_WIDTH; j++)
				game->map[i][j] = '0';
		}
		print_cells(game);
	}
	return (EXIT_SUCCESS);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
