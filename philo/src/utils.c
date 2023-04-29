/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:32:50 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 03:22:13 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_only_digit(char *str)
{
	int	i;

	i = 0;
	if (!ft_strlen(str))
		return (false);
	while (str[i])
	{
		if ('0'> str[i] || str[i] < '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	parsing_manager(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!ft_only_digit(av[i]))
			return (false);
		if (ft_strlen(av[i]) > 4)
			return (false);
		if (!i && ft_atoi(av[i]) < 1)
			return (false);
		if (ft_atoi(av[i]) > 1000)
			return (false);
		i++;
	}
	return (true);
}