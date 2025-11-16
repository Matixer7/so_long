/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:12:52 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 12:28:56 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int status, t_game *s_game)
{
	free(s_game->map);
	free(s_game->s_map->map);
	mlx_clear_window(s_game->mlx_ptr, s_game->win_ptr);
	mlx_destroy_display(s_game->mlx_ptr);
	mlx_destroy_window(s_game->mlx_ptr, s_game->win_ptr);
	exit(status);
	return (0);
}

int	ft_key(int keycode, t_game *s_game)
{
	get_direction(keycode, s_game);
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
		return (ft_printf("Map validation failed\n"), ft_exit(0, &s_game));
	flood_verify(&s_game, &s_map);
	s_game.mlx_ptr = mlx_init();
	s_game.win_ptr = mlx_new_window(s_game.mlx_ptr,
			s_map.width * 64, s_map.height * 64, "gernig");
	ft_printf("Map validated: width=%d height=%d collectibles=%d\n",
		s_map.width, s_map.height, s_map.collectibles);
	texture_check(&s_game, s_game.mlx_ptr);
	show_in_window(&s_game);
	mlx_hook(s_game.win_ptr, 17, 0, ft_exit, &s_game);
	mlx_hook(s_game.win_ptr, 2, 1l << 0, ft_key, &s_game);
	mlx_loop(s_game.mlx_ptr);
	return (0);
}
