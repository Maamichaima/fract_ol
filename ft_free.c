/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:39 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/29 13:54:06 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->win);
}
