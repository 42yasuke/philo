/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:39:40 by jose              #+#    #+#             */
/*   Updated: 2023/08/25 16:08:12 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_philo(void *phil)
{
	while (true)
	{
		if (ft_eat((t_philo *)phil))
			break ;
		if (ft_sleep((t_philo *)phil))
			break ;
		if (ft_think((t_philo *)phil))
			break ;
	}
	return (phil);
}

static int	ft_thread_create(t_config *conf)
{
	pthread_t	*thrd;
	int			i;

	i = -1;
	while (++i < conf->philo_num)
	{
		thrd = &conf->thrds[i];
		if (pthread_create(thrd, NULL, &ft_philo, (void *)(&conf->philo[i])))
			return (ft_free_all(conf), ft_error(THREAD_CREATE), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_thread_join(t_config	*conf)
{
	int			i;

	i = 0;
	while (i < conf->philo_num)
	{
		if (pthread_join(conf->thrds[i], NULL))
			return (ft_free_all(conf), ft_error(THREAD_JOIN), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_philo_manager(int ac, char **av)
{
	t_config	*conf;
	int			stop;

	stop = true;
	conf = malloc(sizeof(*conf));
	if (!conf)
		return (ft_error(MALLOC_FAILED));
	if (ft_init_all(ac, av, conf))
		return ;
	if (ft_thread_create(conf))
		return ;
	while (stop)
	{
		pthread_mutex_lock(conf->m);
		stop = (ft_all_alive(conf) && !ft_all_eat(conf));
		pthread_mutex_unlock(conf->m);
	}
	if (ft_thread_join(conf))
		return ;
	return (ft_free_all(conf));
}
