/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:25:59 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 12:28:35 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "GetNextLine/get_next_line.h"
# include "Libft/libft.h"
# include "mlx.h"

# define WALL "textures/wall.xpm"
# define COIN "textures/cole.xpm"
# define GUY  "textures/player.xpm"
# define EXIT "textures/exit.xpm"
# define BCG  "textures/floor.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	t_point	player;
	int		collectibles;
	t_point	exit;
	char	*file_name;
	int		found_coins;
	int		found_exits;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_txt;
	void	*coin_txt;
	void	*plr_txt;
	void	*exit_txt;
	void	*bckg_txt;
	int		points;
	int		moves;
	char	**map;
	t_map	*s_map;
}	t_game;

int		validate_map(t_map *s_map, t_game *s_game);
void	get_direction(int keycode, t_game *s_game);
void	show_in_window(t_game *s_game);
int		ft_exit(int status, t_game *s_game);
int		check_map_element(t_map *s_map, int y);
void	texture_check(t_game *s_game, void *mlx_ptr);
void	flood_verify(t_game *s_game, t_map *s_map);
int		ft_key(int keycode, t_game *s_game);

#endif
