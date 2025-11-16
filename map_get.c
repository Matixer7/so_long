/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:22:31 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 19:55:08 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_map *s_map)
{
	int		map_fd;
	int		i;

	map_fd = open(s_map->file_name, O_RDONLY);
	if (map_fd <= 2)
		return (close(map_fd), -1);
	i = -1;
	while (s_map->map[++i])
	{
		if (i == 0)
			s_map->width = ft_strlen(s_map->map[i]);
		if (ft_strlen(s_map->map[i]) != s_map->width)
			return (close(map_fd), -1);
	}
	s_map->collectibles = 0;
	s_map->player = (t_point){0, 0};
	s_map->exit = (t_point){0, 0};
	s_map->height = i;
	i = -1;
	while (s_map->map[++i])
		if (check_map_element(s_map, i) == -1)
			return (close(map_fd), -1);
	return (close(map_fd), 0);
}

static int	validate_extension(char *map_file)
{
	char	*ext;
	int		cmp;

	ext = ".ber";
	map_file += ft_strlen(map_file) - 4;
	cmp = 0;
	while (*map_file != '\0')
	{
		cmp += *map_file - *ext;
		map_file++;
		ext++;
	}
	if (cmp != 0)
		return (-1);
	return (0);
}

int	get_map(int map_fd, char *map_file, t_map *s_map, t_game *s_game)
{
	char	*lines;
	char	*line;
	char	*tmp;

	if (validate_extension(map_file) == -1)
		return (-1);
	lines = ft_strdup("");
	if (!lines)
		return (-1);
	line = get_next_line(map_fd);
	while (line)
	{
		tmp = ft_strjoin(lines, line);
		free(lines);
		if (!tmp)
			return (free(line), -1);
		lines = tmp;
		free(line);
		line = get_next_line(map_fd);
	}
	s_map->map = ft_split(lines, '\n');
	s_game->map = ft_split(lines, '\n');
	free(lines);
	return (load_map(s_map));
}

int	validate_map(t_map *s_map, t_game *s_game)
{
	int	map_fd;

	if (!s_map || !s_map->file_name)
		return (-1);
	map_fd = open(s_map->file_name, O_RDONLY);
	if (map_fd <= 2 || get_map(map_fd, s_map->file_name, s_map, s_game))
		return (-1);
	close(map_fd);
	return (0);
}
