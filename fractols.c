/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:35:32 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 15:06:44 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	julia_color(t_fractol fractol, double i, double j)
{
	t_complex	z;
	double		tmp;

	z.r = (fractol.r_max - fractol.r_min) * i / 600 + fractol.r_min;
	z.i = (fractol.i_min - fractol.i_max) * j / 600 - fractol.i_min;
	while (z.r * z.r + z.i * z.i < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + fractol.cr;
		z.i = 2 * tmp * z.i + fractol.ci;
		if (fractol.max == 200)
			break ;
		fractol.max++;
	}
	if (fractol.max == 200)
		return (0x0F7E9C6);
	else
		return (rgba(fractol.c, &fractol));
}

unsigned int	mandelbrot_color(t_fractol fractol, double i, double j)
{
	t_complex	c;
	t_complex	z;
	double		tmp;

	c.r = (fractol.r_max - fractol.r_min) * i / 600 + fractol.r_min;
	c.i = (fractol.i_min - fractol.i_max) * j / 600 - fractol.i_min;
	z.i = 0;
	z.r = 0;
	while (z.i * z.i + z.r * z.r < 4)
	{
		tmp = z.i;
		z.i = z.i * z.i - z.r * z.r + c.r;
		z.r = 2 * tmp * z.r + c.i;
		if (fractol.max == 200)
			break ;
		fractol.max++;
	}
	if (fractol.max == 200)
		return (0x0);
	else
		return (rgba(fractol.c, &fractol));
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot(t_fractol fractol)
{
	double	i;
	double	j;

	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			my_mlx_pixel_put(&fractol, i, j, mandelbrot_color(fractol, i, j));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.image, 0, 0);
}

void	julia(t_fractol fractol)
{
	double	i;
	double	j;

	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			my_mlx_pixel_put(&fractol, i, j, julia_color(fractol, i, j));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.image, 0, 0);
}
