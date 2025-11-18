/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:29:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/18 18:35:11 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *s_map, int x, int y)
{
	if (s_map->map[y][x] == 'C')
		s_map->found_coins++;
	if (s_map->map[y][x] == 'E')
	{
		s_map->map[y][x] = '1';
		s_map->found_exits++;
		return ;
	}
	s_map->map[y][x] = '1';
	if ((y + 1) < s_map->height && s_map->map[y + 1][x] != '1')
		flood_fill(s_map, x, y + 1);
	if ((y - 1) < s_map->height && s_map->map[y - 1][x] != '1')
		flood_fill(s_map, x, y - 1);
	if ((x + 1) < s_map->width && s_map->map[y][x + 1] != '1')
		flood_fill(s_map, x + 1, y);
	if ((x - 1) < s_map->width && s_map->map[y][x - 1] != '1')
		flood_fill(s_map, x - 1, y);
}

void	flood_verify(t_game *s_game, t_map *s_map)
{
	int	x;
	int	y;

	x = s_map->player.x;
	y = s_map->player.y;
	flood_fill(s_map, x, y);
	if (s_map->found_coins != s_map->collectibles || s_map->collectibles == 0
		|| s_map->found_exits != 1)
	{
		ft_putstr_fd("Error\nMap validation failed\n", 2);
		ft_exit(0, s_game);
	}
}
