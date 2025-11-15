/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:25:59 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 16:47:44 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "GetNextLine/get_next_line.h"
#include "Libft/libft.h"
#include "mlx.h"

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
}	t_map;

int	validate_map(t_map *s_map);