/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:59:31 by jose              #+#    #+#             */
/*   Updated: 2023/05/10 01:28:50 by jose             ###   ########.fr       */
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

static void	ft_print_eat(t_philo *philo)
{
	char	*str;
	char	*str2;
	int		i;
	t_ull	elapsed_ms;

	i = 0;
	elapsed_ms = timestamp_in_ms();
	pthread_mutex_lock(philo->conf->m);
	while (i < 3)
	{
		str = ft_itoa(elapsed_ms);
		write (STDERR_FILENO, str, ft_strlen(str));
		write (STDERR_FILENO, "ms ", 3);
		str2 = ft_itoa(philo->id + 1);
		write (STDERR_FILENO, str2, ft_strlen(str2));
		if (i < 2)
			write (STDERR_FILENO, " has taken a fork\n", 19);
		else
			write (STDERR_FILENO, " is eating\n", 12);
		i++;
		(free(str), free(str2));
	}
	pthread_mutex_unlock(philo->conf->m);
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
			pthread_mutex_lock(&forks[0]);
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

void	ft_eat(t_philo *philo)
{
	if (philo->conf->philo_num == 1)
		usleep(philo->conf->t_die * 1000);
	else
	{
		ft_get_forks(philo);
		ft_print_eat(philo);
		usleep(philo->conf->t_eat * 1000);
		pthread_mutex_lock(philo->conf->m);
		philo->eat_num++;
		philo->t_last_meal += timestamp_in_ms();
		pthread_mutex_unlock(philo->conf->m);
		ft_drop_forks(philo);
	}
}
