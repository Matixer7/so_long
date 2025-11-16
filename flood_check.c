/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:29:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 12:01:54 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *s_map, int x, int y)
{
	if (s_map->map[y][x] == 'C')
		s_map->found_coins++;
	if (s_map->map[y][x] == 'E')
		s_map->found_exits++;
	if ((y + 1) < s_map->height && s_map->map[y + 1][x] != '1')
	{
		s_map->map[y][x] = '1';
		flood_fill(s_map, x, y + 1);
	}
	if ((y - 1) < s_map->height && s_map->map[y - 1][x] != '1')
	{
		s_map->map[y][x] = '1';
		flood_fill(s_map, x, y - 1);
	}
	if ((x + 1) < s_map->width && s_map->map[y][x + 1] != '1')
	{
		s_map->map[y][x] = '1';
		flood_fill(s_map, x + 1, y);
	}
	if ((x - 1) < s_map->width && s_map->map[y][x - 1] != '1')
	{
		s_map->map[y][x] = '1';
		flood_fill(s_map, x - 1, y);
	}
	return ;
}

void	flood_verify(t_game *s_game, t_map *s_map)
{
	int	x;
	int	y;

	x = s_map->player.x;
	y = s_map->player.y;
	s_map->found_coins = 0;
	s_map->found_exits = 0;
	flood_fill(s_map, x, y);
	if (s_map->found_coins != s_map->collectibles || s_map->found_exits != 1)
	{
		ft_printf("Map validation failed\n");
		ft_exit(0, s_game);
	}
}
