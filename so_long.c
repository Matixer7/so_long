/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:12:52 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 17:29:28 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	t_map s_map;

	s_map.file_name = "map.ber";
	if (validate_map(&s_map) == -1)
		ft_printf("Map validation failed\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, s_map.width * 64, s_map.height * 64, "gernig");
	ft_printf("Map validated: width=%d height=%d collectibles=%d\n", s_map.width, s_map.height, s_map.collectibles);
	mlx_loop(mlx_ptr);
	return (0);
}
