/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:03:58 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 22:14:35 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *s_game, char tile, int x, int y)
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
		mlx_put_image_to_window(s_game->mlx_ptr, s_game->win_ptr, img, px, py);
	}
}

void	show_in_window(t_game *s_game)
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
			render_tile(s_game, tile, x, y);
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
