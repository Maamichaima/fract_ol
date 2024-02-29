/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:39 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:05:24 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_free(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_image(fractol->mlx, fractol->image);
	free(fractol->mlx);
}
