/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:12:52 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 21:43:10 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *s_game, void *mlx_ptr, char tile, int x, int y)
{
	void	*img;
	int		px;
	int		py;

	img = NULL;
	if (tile == '1')
		img = s_game->wall_txt;
	else if (tile == '0')
		img = s_game->bckg_txt;
	else if (tile == 'P')
		img = s_game->plr_txt;
	else if (tile == 'C')
		img = s_game->coin_txt;
	else if (tile == 'E')
		img = s_game->exit_txt;
	if (img)
	{
		px = x * 64;
		py = y * 64;
		mlx_put_image_to_window(mlx_ptr, s_game->win_ptr, img, px, py);
	}
}

void	show_in_window(t_game *s_game, void *mlx_ptr)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (s_game->map[y])
	{
		x = 0;
		while (s_game->map[y][x])
		{
			tile = s_game->map[y][x];
			render_tile(s_game, mlx_ptr, tile, x, y);
			x++;
		}
		y++;
	}
}

void	texture_check(t_game *s_game, void *mlx_ptr)
{
	int	tile;

	tile = 64;
	s_game->wall_txt = mlx_xpm_file_to_image(mlx_ptr, WALL, &tile, &tile);
	s_game->exit_txt = mlx_xpm_file_to_image(mlx_ptr, EXIT, &tile, &tile);
	s_game->coin_txt = mlx_xpm_file_to_image(mlx_ptr, COIN, &tile, &tile);
	s_game->plr_txt = mlx_xpm_file_to_image(mlx_ptr, GUY, &tile, &tile);
	s_game->bckg_txt = mlx_xpm_file_to_image(mlx_ptr, BCG, &tile, &tile);
}

int	ft_exit(int status)
{
	exit(status);
	return (0);
}

int	ft_key(int keycode, t_game *s_game)
{
	get_direction(keycode, s_game);
	//ft_printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_game	s_game;
	t_map	s_map;

	s_game.s_map = &s_map;
	s_game.points = 0;
	s_game.moves = 0;
	s_map.file_name = "map.ber";
	if (validate_map(&s_map, &s_game) == -1)
		ft_printf("Map validation failed\n");
	s_game.mlx_ptr = mlx_init();
	s_game.win_ptr = mlx_new_window(s_game.mlx_ptr,
			s_map.width * 64, s_map.height * 64, "gernig");
	ft_printf("Map validated: width=%d height=%d collectibles=%d\n",
		s_map.width, s_map.height, s_map.collectibles);
	texture_check(&s_game, s_game.mlx_ptr);
	show_in_window(&s_game, s_game.mlx_ptr);
	mlx_hook(s_game.win_ptr, 17, 0, ft_exit, NULL);
	mlx_hook(s_game.win_ptr, 2, 1l << 0, ft_key, &s_game);
	mlx_loop(s_game.mlx_ptr);
	return (0);
}


//W = 119
//S = 115
//A = 97
//D = 100