/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:59:31 by jose              #+#    #+#             */
/*   Updated: 2023/08/25 15:24:38 by jose             ###   ########.fr       */
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
	t_ull	elapsed_ms;

	pthread_mutex_lock(philo->conf->m);
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	elapsed_ms = timestamp_in_ms();
	printf("%lld %d has taken a fork\n", elapsed_ms, philo->id + 1);
	printf("%lld %d has taken a fork\n", elapsed_ms, philo->id + 1);
	printf("%lld %d is eating\n", elapsed_ms, philo->id + 1);
	return (pthread_mutex_unlock(philo->conf->m), false);
}

static void	ft_get_forks2(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = philo->conf->forks;
	pthread_mutex_lock(&forks[philo->id]);
	usleep(500);
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
		(usleep(1000), pthread_mutex_lock(&forks[philo->id]));
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_lock(&forks[0]);
		else
			pthread_mutex_lock(&forks[philo->id + 1]);
	}
}

int	ft_eat(t_philo *philo)
{
	if (philo->conf->philo_num == 1)
	{
		printf("0 1 has taken a fork\n");
		return (usleep(philo->conf->t_die * 1000), true);
	}
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
