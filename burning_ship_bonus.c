/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:17:17 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:05:02 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ab(double x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

unsigned int	buring_ship_color(t_fractol fractol, double i, double j)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	c.r = (fractol.r_max - fractol.r_min) * i / 600 + fractol.r_min;
	c.i = (fractol.i_min - fractol.i_max) * j / 600 - fractol.i_min;
	z.r = 0;
	z.i = 0;
	while (z.r * z.r + z.i * z.i < 4)
	{
		tmp = z.r;
		z.r = ab(z.r * z.r) - ab(z.i * z.i) + c.r;
		z.i = -2 * ab(tmp * z.i) + c.i;
		if (fractol.max == 600)
			break ;
		fractol.max++;
	}
	if (fractol.max == 200)
		return (0x0);
	else
		return (rgba(fractol.c, &fractol));
}

void	buring_ship(t_fractol fractol)
{
	double	i;
	double	j;

	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			my_mlx_pixel_put(&fractol, i, j, buring_ship_color(fractol, i, j));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.image, 0, 0);
}
