/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:51:31 by jose              #+#    #+#             */
/*   Updated: 2023/05/10 01:40:18 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_tp(char **av, pthread_t **th, t_philo **ph, t_config *conf)
{
	int	i;

	i = 0;
	*th = malloc(sizeof(**th) * ft_atoi(av[1]));
	if (!*th)
		return (ft_error(MALLOC_FAILED), EXIT_FAILURE);
	*ph = malloc(sizeof(**ph) * ft_atoi(av[1]));
	if (!*th)
		return (free(*th), ft_error(MALLOC_FAILED), EXIT_FAILURE);
	while (i < ft_atoi(av[1]))
	{
		(*ph)[i].conf = conf;
		(*ph)[i].id = i;
		(*ph)[i].t_last_meal = 0;
		(*ph)[i].eat_num = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	ft_destroy_them(pthread_mutex_t **f, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(*f + j);
		j++;
	}
}

static int	ft_init_mutex(char **av, pthread_mutex_t **m, pthread_mutex_t **f)
{
	int	i;

	i = 0;
	*f = malloc(sizeof(**f) * ft_atoi(av[1]));
	if (!*f)
		return (ft_error(MALLOC_FAILED), EXIT_FAILURE);
	*m = malloc(sizeof(**m));
	if (!*m)
		return (free(*f), ft_error(MALLOC_FAILED), EXIT_FAILURE);
	if (pthread_mutex_init(*m, NULL))
		return (free(*f), free(*m), ft_error(MUTEX_INIT), EXIT_FAILURE);
	while (i < ft_atoi(av[1]))
	{
		if (pthread_mutex_init(&(*f)[i], NULL))
		{
			ft_destroy_them(f, i);
			return (free(*f), free(*m), ft_error(MUTEX_INIT), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_init_all(int ac, char **av, t_config *conf)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex;
	pthread_t		*thrds;
	t_philo			*philo;

	if (ft_init_mutex(av, &mutex, &forks))
		return (free(conf), EXIT_FAILURE);
	if (ft_init_tp(av, &thrds, &philo, conf))
		return (free(conf), free(mutex), free(forks), EXIT_FAILURE);
	conf->forks = forks;
	conf->m = mutex;
	conf->thrds = thrds;
	conf->philo = philo;
	conf->t_die = ft_atoull(av[2]);
	conf->t_eat = ft_atoull(av[3]);
	conf->t_sleep = ft_atoull(av[4]);
	conf->times_to_eat = -1;
	if (ac == 6)
		conf->times_to_eat = ft_atoi(av[5]);
	conf->philo_num = ft_atoi(av[1]);
	conf->stop_thread = false;
	return (EXIT_SUCCESS);
}
