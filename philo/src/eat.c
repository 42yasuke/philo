/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:59:31 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 10:14:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	philo->forks[philo->philo_id] = 0;
	if (!philo->philo_id)
		philo->forks[philo->num_philo - 1] = 0;
	else
		philo->forks[philo->philo_id - 1] = 0;
	philo->num_meal = philo->num_meal + 0;
	pthread_mutex_unlock(philo->mutex);
}

void	ft_print_eat(t_philo *philo, unsigned long long elapsed_ms)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	while (i < 3)
	{
		str = ft_itoa(elapsed_ms);
		write (STDOUT_FILENO, str, ft_strlen(str));
		write (STDOUT_FILENO, "ms ", 3);
		str2 = ft_itoa(philo->philo_id + 1);
		write (STDOUT_FILENO, str2, ft_strlen(str2));
		if (i < 2)
			write (STDOUT_FILENO, " has taken a fork\n", 19);
		else
			write (STDOUT_FILENO, " is eating\n", 12);
		i++;
		(free(str), free(str2));
	}
}

static void	ft_getting_them(t_philo *philo)
{
	philo->forks[philo->philo_id] = 1;
	if (!philo->philo_id)
		philo->forks[philo->num_philo - 1] = 1;
	else
		philo->forks[philo->philo_id - 1] = 1;
	philo->num_meal = philo->num_meal + 1;
}

static int	ft_get_forks(t_philo *philo)
{
	int	*forks;

	forks = philo->forks;
	if (!philo->philo_id)
	{
		if (philo->num_philo == 1)
			return (false);
		else if (!forks[philo->philo_id] && !forks[philo->num_philo - 1])
			return (ft_getting_them(philo), true);
	}
	else if (!forks[philo->philo_id] && !forks[philo->philo_id - 1])
		return (ft_getting_them(philo), true);
	return (false);
}

int	ft_eat(t_philo *philo)
{
	int	can_eat;

	pthread_mutex_lock(philo->mutex);
	can_eat = ft_get_forks(philo);
	pthread_mutex_unlock(philo->mutex);
	return (can_eat);
}