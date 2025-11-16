/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:02:19 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 15:42:39 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	record_player(t_map *s_map, int x, int y)
{
	if (s_map->player.x || s_map->player.y)
		return (-1);
	s_map->player = (t_point){x, y};
	return (0);
}

static int	record_exit(t_map *s_map, int x, int y)
{
	if (s_map->exit.x || s_map->exit.y)
		return (-1);
	s_map->exit = (t_point){x, y};
	return (0);
}

int	check_map_element(t_map *s_map, int y)
{
	int	x;

	if (!s_map || y < 0 || y >= s_map->height)
		return (-1);
	x = -1;
	while (s_map->map[y][++x])
	{
		if ((y == 0 || y == s_map->height - 1) && s_map->map[y][x] != '1')
			return (-1);
		if ((x == 0 || x == s_map->width - 1) && s_map->map[y][x] != '1')
			return (-1);
		if (s_map->map[y][x] == 'P' && record_player(s_map, x, y) == -1)
			return (-1);
		else if (s_map->map[y][x] == 'E' && record_exit(s_map, x, y) == -1)
			return (-1);
		else if (s_map->map[y][x] == 'C')
			s_map->collectibles++;
		else if (!ft_strchr("10ECP", s_map->map[y][x]))
			return (-1);
	}
	if (y == s_map->height - 1)
		if (!(s_map->player.x && s_map->player.y)
			|| !(s_map->exit.x && s_map->exit.y))
			return (-1);
	return (0);
}
