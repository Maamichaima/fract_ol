/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:10:13 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:04:50 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw(t_fractol fractol)
{
	if (fractol.nom[0] == 'j')
	{
		fractol.cr = ft_atof(fractol.argv[2]);
		fractol.ci = ft_atof(fractol.argv[3]);
		julia(fractol);
	}
	else if (fractol.nom[0] == 'm')
		mandelbrot(fractol);
	else
		buring_ship(fractol);
}

int	main(int c, char **v)
{
	t_fractol	fractol;

	if (c > 1 && ((!ft_strcmp(v[1], "julia") && c == 4 && check_double(v[2])
				&& check_double(v[3])) || (!ft_strcmp(v[1], "mandelbrot")
				&& c == 2) || (!ft_strcmp(v[1], "burning_ship") && c == 2)))
	{
		fractol.mlx = mlx_init();
		if (!fractol.mlx)
			exit(1);
		inisialiser(&fractol, v, c);
		fractol.win = mlx_new_window(fractol.mlx, 600, 600, fractol.nom);
		fractol.image = mlx_new_image(fractol.mlx, 600, 600);
		fractol.addr = mlx_get_data_addr(fractol.image, &fractol.bits_per_pixel,
				&fractol.line_length, &fractol.endian);
		draw(fractol);
		mlx_hook(fractol.win, 17, 1L << 0, close_window, &fractol);
		mlx_mouse_hook(fractol.win, key_mousse, &fractol);
		mlx_key_hook(fractol.win, key_hook, &fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		put_error();
		exit(1);
	}
}
