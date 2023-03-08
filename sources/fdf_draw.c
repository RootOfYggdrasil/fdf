/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:41:47 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/08 16:05:03 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

# define MAX(a, b) (a > b ? a : b)
# define ABS(a) ((a < 0) ? -a : a)

void    ft_isometric(float *x, float *y, double angle, int z)
{
    *x = (*x - *y) * cos(angle);
    *y = (*x + *y) * sin(angle) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    ft_bresenham(float x, float y, float x1, float y1, t_data *data)
{
    float x_step;
    float y_step;
    float max;
    int clr;
    int z;

    clr = data->map->point_array[(int)y][(int)x].clr;
    z = data->map->point_array[(int)y][(int)x].z;
    x *= data->map->zoom;
    y *= data->map->zoom;
    x1 *= data->map->zoom;
    y1 *= data->map->zoom;

    //ft_isometric(&x, &y, 0.8, data->map->point_array[(int)y][(int)x].z);
    //ft_isometric(&x1, &y1, 0.8, data->map->point_array[(int)y1][(int)x1].z);
    //ft_isometric(&x, &y, 0.5, 0);
    //ft_isometric(&x1, &y1, 0.5, 0);

    x += 50;
    y += 50;
    x1 += 50;
    y1 += 50;

    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX(ABS(x_step), ABS(y_step));
    if (max != 0)
    {
        x_step /= max;
        y_step /= max;
    }
    else
    {
        x_step = 0;
        y_step = 0;   
    }
    
    while ((int)(x - x1) || (int)(y - y1))
    {
        if (clr)
        {
            mlx_pixel_put(data->mlx, data->mlx_win, x, y, clr);
        }
        else if(z)
        {
            mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0xe80c00);
        }
        else
        {
            mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0xFFFFFF);
        }
        x += x_step;
        y += y_step;
    }
    
}

void    test_draw(t_data *img)
{
    float x;
    float y;

    y = 0;
    while (y < img->map->height)
    {
        x = 0;
        while (x < img->map->width)
        {
            if (x < img->map->width - 1)
                ft_bresenham(x, y, x + 1, y, img);
            if (y < img->map->height - 1)
                ft_bresenham(x, y, x, y + 1, img);
            x++;
        }
        y++;
    }
}