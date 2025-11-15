/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:31 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 15:26:05 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_element(t_map s_map, int y)
{
	int x;

	x = 0;
	while (y < s_map.height && s_map.map[y][x])
	{
		if ((y == 0 || y == s_map.height) && s_map.map[y][x] != '1')
			return (-1);
		if ((x == 0 || x == s_map.width) && s_map.map[y][x] != '1')
			return (-1);
		if ((s_map.map[y][x] == 'P' && s_map.player.x) || (s_map.map[y][x] == 'E' && s_map.exit.x))
			return (-1);
		if (s_map.map[y][x] == 'P')
			s_map.player = (t_point){x, y};
		if (s_map.map[y][x] == 'E')
			s_map.exit = (t_point){x, y};
		if (s_map.map[y][x] == 'C')
			s_map.collectibles++;
		x++;
	}
	if (!(s_map.player.x && s_map.player.y) || !(s_map.exit.x && s_map.exit.y))
		return (-1);
	return(0);
}

int load_map(t_map s_map)
{
	int map_fd;
	int i;
	
	map_fd = open(s_map.file_name, O_RDONLY);
	if (map_fd <= 2)	
		return (-1);
	i = 0;
	while (s_map.map[i])
	{
		if (i == 0)
			s_map.width = ft_strlen(s_map.map[i]);
		if (ft_strlen(s_map.map[i]) != s_map.width)
			return (-1);
		i++;
	}
	s_map.collectibles = 0;
	s_map.height = i;
	i = 0;
	while (s_map.map[i++])
		if (check_map_element(s_map, i) == -1)
			return (-1);
	return (0);
}

int get_map(int map_fd, char *map_file, t_map s_map)
{
	char	*extension;
	int 	cmp;
	char	*lines;
	char	*line;

	extension = ".ber";
	cmp = 0;
	map_file += ft_strlen(map_file) - 4;
	while (*map_file != '\0')
	{	
		cmp += *map_file - *extension;
		map_file++;
		extension++;
	}
	if (cmp != 0)
		return (-1);
	lines = "";
	while ((line = get_next_line(map_fd)))
	{
		lines = ft_strjoin(lines, line);
		free(line);
	}
	s_map.map = ft_split(lines, '\n');
	
	return (load_map(s_map));
}

int	validate_map(char *map_file)
{
	int map_fd;
	t_map s_map;
	
	s_map.file_name = map_file;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd <= 2 || get_map(map_fd, map_file, s_map))	
		return (-1);
	close(map_fd);
	return (0);
}