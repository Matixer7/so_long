/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:38:10 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 21:42:21 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//W = 119
//S = 115
//A = 97
//D = 100

void	player_move(t_game *s_game, t_map *s_map, int y, int x)
{
	int px;
	int py;

	px = s_map->player.x;
	py = s_map->player.y;
	if (s_game->map[py + y][px + x] != '1')
	{
		s_game->moves++;
		if (s_game->map[py + y][px + x] == 'C')
		{
			s_game->points++;
			ft_printf("%d/%d collected\n", s_game->points, s_map->collectibles);
		}
		if (s_game->map[py + y][px + x] == 'E' && s_game->points == s_map->collectibles)
			if (ft_printf("Game finished with %d moves!\n", s_game->moves) > 0)
				ft_exit(0);
		if (s_game->map[py + y][px + x] == 'E' && s_game->points != s_map->collectibles)
			return ;
		ft_printf("You moved %d times\n", s_game->moves);
		s_game->map[py][px] = '0';
		s_game->map[py + y][px + x] = 'P';
		s_map->player.y += y;
		s_map->player.x += x;
		show_in_window(s_game, s_game->mlx_ptr);
	}
}

void	get_direction(int keycode, t_game *s_game)
{
	if (keycode == 119)
		player_move(s_game, s_game->s_map, -1, 0);
	if (keycode == 115)
		player_move(s_game, s_game->s_map, 1, 0);
	if (keycode == 97)
		player_move(s_game, s_game->s_map, 0, -1);
	if (keycode == 100)
		player_move(s_game, s_game->s_map, 0, 1);
}