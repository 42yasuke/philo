/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:59:31 by jose              #+#    #+#             */
/*   Updated: 2023/08/08 18:02:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	t_config		*conf;

	conf = philo->conf;
	forks = conf->forks;
	if (!(philo->id % 2))
	{
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_unlock(forks);
		else
			pthread_mutex_unlock(forks + philo->id + 1);
		pthread_mutex_unlock(forks + philo->id);
	}
	else
	{
		pthread_mutex_unlock(forks + philo->id);
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_unlock(forks);
		else
			pthread_mutex_unlock(forks + philo->id + 1);
	}
}

static int	ft_print_eat(t_philo *philo)
{
	char	*str;
	char	*str2;
	int		i;
	t_ull	elapsed_ms;

	i = -1;
	pthread_mutex_lock(philo->conf->m);
	elapsed_ms = timestamp_in_ms();
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	while (++i < 3)
	{
		str = ft_itoa(elapsed_ms);
		write (STDOUT_FILENO, str, ft_strlen(str));
		write (STDOUT_FILENO, " ", 1);
		str2 = ft_itoa(philo->id + 1);
		write (STDOUT_FILENO, str2, ft_strlen(str2));
		if (i < 2)
			write (STDOUT_FILENO, " has taken a fork\n", 19);
		else
			write (STDOUT_FILENO, " is eating\n", 12);
		(free(str), free(str2));
	}
	return (pthread_mutex_unlock(philo->conf->m), false);
}

static void	ft_get_forks2(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = philo->conf->forks;
	pthread_mutex_lock(&forks[philo->id]);
	usleep(5);
	pthread_mutex_lock(&forks[0]);
}

static void	ft_get_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	t_config		*conf;

	conf = philo->conf;
	forks = conf->forks;
	if (philo->id % 2 == 0)
	{
		if (philo->id == conf->philo_num - 1)
		{
			if (philo->conf->philo_num % 2)
				return (ft_get_forks2(philo));
			pthread_mutex_lock(&forks[0]);
		}
		else
			pthread_mutex_lock(&forks[philo->id + 1]);
		pthread_mutex_lock(&forks[philo->id]);
	}
	else
	{
		pthread_mutex_lock(&forks[philo->id]);
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_lock(&forks[0]);
		else
			pthread_mutex_lock(&forks[philo->id + 1]);
	}
}

int	ft_eat(t_philo *philo)
{
	if (philo->conf->philo_num == 1)
		usleep(philo->conf->t_die * 1000);
	else
	{
		ft_get_forks(philo);
		if (ft_print_eat(philo))
			return (ft_drop_forks(philo), true);
		usleep(philo->conf->t_eat * 1000);
		pthread_mutex_lock(philo->conf->m);
		philo->t_last_meal = timestamp_in_ms();
		philo->eat_num++;
		pthread_mutex_unlock(philo->conf->m);
		ft_drop_forks(philo);
	}
	return (false);
}
