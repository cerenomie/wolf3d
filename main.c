/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:17:50 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/10 15:51:39 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int			main(void)
{
	t_env	e;

	map(e.map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "WOLF3D");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sizeline), &(e.endian));
	background(&e);
	mlx_hook(e.win, 2, (1L << 0), key, &e);
	e.x = 1;
	e.y = 7;
	e.angle = -M_PI / 2;
	screen(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
