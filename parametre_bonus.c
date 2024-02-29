/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametre_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:45:58 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:05:39 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_atoi(char *str)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb);
}

int	countnbr(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

double	ft_atof(char *str)
{
	int		j;
	double	part1;
	int		s;
	double	part2;

	j = 0;
	s = 1;
	part1 = ft_atoi(str);
	if (str[j] == '-')
		s = -1;
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	part2 = ft_atoi(str);
	j = ft_strlen(str);
	while (j-- > 0)
		part2 /= 10;
	return ((part1 + part2) * s);
}

int	check_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '.')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
