/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:12:52 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/16 19:50:53 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int status, t_game *s_game)
{
	if (s_game && s_game->mlx_ptr && s_game->win_ptr)
	{
		if (s_game->wall_txt)
			mlx_destroy_image(s_game->mlx_ptr, s_game->wall_txt);
		if (s_game->coin_txt)
			mlx_destroy_image(s_game->mlx_ptr, s_game->coin_txt);
		if (s_game->plr_txt)
			mlx_destroy_image(s_game->mlx_ptr, s_game->plr_txt);
		if (s_game->exit_txt)
			mlx_destroy_image(s_game->mlx_ptr, s_game->exit_txt);
		if (s_game->bckg_txt)
			mlx_destroy_image(s_game->mlx_ptr, s_game->bckg_txt);
		if (s_game->win_ptr)
			mlx_destroy_window(s_game->mlx_ptr, s_game->win_ptr);
		mlx_destroy_display(s_game->mlx_ptr);
		free(s_game->mlx_ptr);
	}
	if (s_game && s_game->map)
		ft_free_all(s_game->map);
	if (s_game && s_game->s_map && s_game->s_map->map)
		ft_free_all(s_game->s_map->map);
	exit(status);
	return (0);
}

static int	ft_exit_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	return (ft_exit(0, game));
}

int	ft_key(int keycode, t_game *s_game)
{
	get_direction(keycode, s_game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	s_game;
	t_map	s_map;

	ft_bzero(&s_game, sizeof(t_game));
	ft_bzero(&s_map, sizeof(t_map));
	s_game.s_map = &s_map;
	if (argc == 2)
		s_map.file_name = argv[1];
	else
		return (ft_printf("No map file given\n"), 0);
	if (validate_map(&s_map, &s_game) == -1)
		return (ft_printf("Map validation failed\n"), ft_exit(0, &s_game));
	flood_verify(&s_game, &s_map);
	s_game.mlx_ptr = mlx_init();
	s_game.win_ptr = mlx_new_window(s_game.mlx_ptr,
			s_map.width * 64, s_map.height * 64, "So Long My Friend");
	ft_printf("Map validated: width=%d height=%d collectibles=%d\n",
		s_map.width, s_map.height, s_map.collectibles);
	texture_check(&s_game, s_game.mlx_ptr);
	show_in_window(&s_game);
	mlx_hook(s_game.win_ptr, 17, 0, ft_exit_hook, &s_game);
	mlx_hook(s_game.win_ptr, 2, 1l << 0, ft_key, &s_game);
	mlx_loop(s_game.mlx_ptr);
	return (0);
}
