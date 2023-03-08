/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:43:10 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/08 16:04:33 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/

void	ft_create_image(t_map *map)
{
	t_data	data;
	data.map = map;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "PACCIANI IS THE NEW RICOTTA");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	//mlx_key_hook(img.mlx_win, key_hook, &img);
	//img.map->zoom = 4;
	//ft_bresenham(10,10,100,100, &img);
	data.map->zoom = 10;
	    /*int x;
    int y;

    y = 0;
    while (y < img.map->height)
    {
        x = 0;
        while (x < img.map->width)
        {
            ft_bresenham(x, y, x + 1, y, &img);
            ft_bresenham(x, y, x, y + 1, &img);
            x++;
        }
        y++;
    }*/
	test_draw(&data);
	mlx_hook(data.mlx_win, 02, 1L<<0, key_hook, &data);
	mlx_loop(data.mlx);
}
