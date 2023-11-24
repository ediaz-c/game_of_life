#include "../includes/game_of_life.h"

void	print_cells(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->bg.img, 0, 0);
	for (int y = 0; y < HEIGHT; y += CELL_HEIGHT)
	{
		for (int x = 0; x < WIDTH; x += CELL_WIDTH)
		{
			if (game->map[y / CELL_HEIGHT][x / CELL_WIDTH] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->cell.alive->img, x, y);
		}
	}
}

int	count_neighbors(char **map, int y, int x)
{
	int	count;
	int	nxC;
	int	nyC;

	nxC = WIDTH / CELL_WIDTH;
	nyC = HEIGHT / CELL_HEIGHT;
	count = 0;
	if (map[(y - 1 + nyC) % nyC][(x - 1 + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y - 1 + nyC) % nyC][(x + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y - 1 + nyC) % nyC][(x + 1 + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y + nyC) % nyC][(x - 1 + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y + nyC) % nyC][(x + 1 + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y + 1 + nyC) % nyC][(x - 1 + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y + 1 + nyC) % nyC][(x + nxC) % nxC] == ALIVE)
		count++;
	if (map[(y + 1 + nyC) % nyC][(x + 1 + nxC) % nxC] == ALIVE)
		count++;
	return (count);
}

char	**update_map(t_game *game)
{
	char	**new_map;
	int		ngb;

	new_map = new_mtx();
	for (int y = 0; game->map[y]; y++)
	{
		for (int x = 0; game->map[y][x]; x++)
		{
			ngb = count_neighbors(game->map, y, x);
			if (game->map[y][x] == ALIVE && (ngb == 2 || ngb == 3))
				new_map[y][x] = ALIVE;
			else if (game->map[y][x] == DEAD && ngb == 3)
				new_map[y][x] = ALIVE;
			else
				new_map[y][x] = DEAD;
		}
	}
	return (new_map);
}