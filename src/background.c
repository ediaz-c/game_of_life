#include "../includes/game_of_life.h"

int	create_background(t_game *game)
{
	t_img	*bg;

	bg = &game->bg;
	bg->img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	bg->addr = (int *)mlx_get_data_addr(bg->img, &bg->bits_per_pixel, &bg->line_length, &bg->endian);
	for (int i = 1; i < WIDTH; i++)
	{
		if (i % CELL_WIDTH == 0)
		{
			for (int j = 0; j < HEIGHT; j++)
				bg->addr[j * WIDTH + i] = 0x00FFFFFF; // Blanco
		}
	}
	for (int i = 1; i < HEIGHT; i++)
	{
		if (i % CELL_HEIGHT == 0)
		{
			for (int j = 0; j < WIDTH; j++)
				bg->addr[i * WIDTH + j] = 0x00FFFFFF; // Blanco
		}
	}
	return (EXIT_SUCCESS);
}