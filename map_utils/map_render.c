/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 07:35:52 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/29 17:56:02 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_images(t_map *map)
{
	int		x;
	int		y;
	t_img	img;

	map->win.floor = "img/floor.xpm";
	map->win.exit = "img/exit.xpm";
	map->win.exit2 = "img/exit2.xpm";
	map->win.wall = "img/wall.xpm";
	map->win.play1 = "img/player/player1.xpm";
	map->win.play2 = "img/player/player2.xpm";
	map->win.play3 = "img/player/player3.xpm";
	map->win.play4 = "img/player/player4.xpm";
	map->win.coin = "img/animation/coins0.xpm";
	render_staff(map);
	img.floo = mlx_xpm_file_to_image(map->win.mlx, map->win.floor, &x, &y);
	img.exit = mlx_xpm_file_to_image(map->win.mlx, map->win.exit, &x, &y);
	img.exit2 = mlx_xpm_file_to_image(map->win.mlx, map->win.exit2, &x, &y);
	img.wall = mlx_xpm_file_to_image(map->win.mlx, map->win.wall, &x, &y);
	img.play1 = mlx_xpm_file_to_image(map->win.mlx, map->win.play1, &x, &y);
	img.play2 = mlx_xpm_file_to_image(map->win.mlx, map->win.play2, &x, &y);
	img.play3 = mlx_xpm_file_to_image(map->win.mlx, map->win.play3, &x, &y);
	img.play4 = mlx_xpm_file_to_image(map->win.mlx, map->win.play4, &x, &y);
	img.coin = mlx_xpm_file_to_image(map->win.mlx, map->win.coin, &x, &y);
	map->img = img;
}

void	render_staff_2(t_map *map, void **imgs, int x)
{
	imgs[16] = mlx_xpm_file_to_image(map->win.mlx, "img/down/0.xpm", &x, &x);
	imgs[17] = mlx_xpm_file_to_image(map->win.mlx, "img/down/1.xpm", &x, &x);
	imgs[18] = mlx_xpm_file_to_image(map->win.mlx, "img/down/2.xpm", &x, &x);
	imgs[19] = mlx_xpm_file_to_image(map->win.mlx, "img/down/3.xpm", &x, &x);
	imgs[20] = mlx_xpm_file_to_image(map->win.mlx, "img/down/4.xpm", &x, &x);
	imgs[21] = mlx_xpm_file_to_image(map->win.mlx, "img/down/5.xpm", &x, &x);
	imgs[22] = mlx_xpm_file_to_image(map->win.mlx, "img/down/6.xpm", &x, &x);
	imgs[23] = mlx_xpm_file_to_image(map->win.mlx, "img/down/7.xpm", &x, &x);
	imgs[24] = mlx_xpm_file_to_image(map->win.mlx, "img/up/0.xpm", &x, &x);
	imgs[25] = mlx_xpm_file_to_image(map->win.mlx, "img/up/1.xpm", &x, &x);
	imgs[26] = mlx_xpm_file_to_image(map->win.mlx, "img/up/2.xpm", &x, &x);
	imgs[27] = mlx_xpm_file_to_image(map->win.mlx, "img/up/3.xpm", &x, &x);
	imgs[28] = mlx_xpm_file_to_image(map->win.mlx, "img/up/4.xpm", &x, &x);
	imgs[29] = mlx_xpm_file_to_image(map->win.mlx, "img/up/5.xpm", &x, &x);
	imgs[30] = mlx_xpm_file_to_image(map->win.mlx, "img/up/6.xpm", &x, &x);
	imgs[31] = mlx_xpm_file_to_image(map->win.mlx, "img/up/7.xpm", &x, &x);
	map->imgs = imgs;
}

void	render_staff(t_map *map)
{
	int		x;
	void	**imgs;

	imgs = map->imgs;
	imgs[0] = mlx_xpm_file_to_image(map->win.mlx, "img/right/0.xpm", &x, &x);
	imgs[1] = mlx_xpm_file_to_image(map->win.mlx, "img/right/1.xpm", &x, &x);
	imgs[2] = mlx_xpm_file_to_image(map->win.mlx, "img/right/2.xpm", &x, &x);
	imgs[3] = mlx_xpm_file_to_image(map->win.mlx, "img/right/3.xpm", &x, &x);
	imgs[4] = mlx_xpm_file_to_image(map->win.mlx, "img/right/4.xpm", &x, &x);
	imgs[5] = mlx_xpm_file_to_image(map->win.mlx, "img/right/5.xpm", &x, &x);
	imgs[6] = mlx_xpm_file_to_image(map->win.mlx, "img/right/6.xpm", &x, &x);
	imgs[7] = mlx_xpm_file_to_image(map->win.mlx, "img/right/7.xpm", &x, &x);
	imgs[8] = mlx_xpm_file_to_image(map->win.mlx, "img/left/0.xpm", &x, &x);
	imgs[9] = mlx_xpm_file_to_image(map->win.mlx, "img/left/1.xpm", &x, &x);
	imgs[10] = mlx_xpm_file_to_image(map->win.mlx, "img/left/2.xpm", &x, &x);
	imgs[11] = mlx_xpm_file_to_image(map->win.mlx, "img/left/3.xpm", &x, &x);
	imgs[12] = mlx_xpm_file_to_image(map->win.mlx, "img/left/4.xpm", &x, &x);
	imgs[13] = mlx_xpm_file_to_image(map->win.mlx, "img/left/5.xpm", &x, &x);
	imgs[14] = mlx_xpm_file_to_image(map->win.mlx, "img/left/6.xpm", &x, &x);
	imgs[15] = mlx_xpm_file_to_image(map->win.mlx, "img/left/7.xpm", &x, &x);
	render_staff_2(map, imgs, x);
}
