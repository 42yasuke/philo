/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:51:31 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 10:42:10 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philo(t_philo *philo, pthread_mutex_t *m, int *f, int i)
{
	philo->is_dead = false;
	philo->num_meal = 0;
	philo->num_of_time_epm_eat = -1;
	philo->num_philo = 0;
	philo->philo_id = -1;
	philo->time_to_die = 0;
	philo->time_to_sleep = 0;
	philo->time_to_eat = 0;
	philo->philo_thread = NULL;
	philo->forks = f;
	philo->mutex = m;
	philo->next = NULL;
	philo->time_last_meal = 0;
	philo->is_thinking = false;
	if (!i)
		philo->prec = NULL;
}

static int	ft_init_lst(char **av, pthread_mutex_t **m, int **f)
{
	*f = malloc(sizeof(**f) * ft_atoi(av[1]));
	if (!*f)
		return (ft_error(MALLOC_FAILED), EXIT_FAILURE);
	memset(*f, 0, sizeof(**f) * ft_atoi(av[1]));
	*m = malloc(sizeof(**m));
	if (!*m)
		return (free(*f), ft_error(MALLOC_FAILED), EXIT_FAILURE);
	if (pthread_mutex_init(*m, NULL))
		return (free(*f), free(*m), ft_error(MUTEX_INIT), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	ft_suite(t_philo *phil, int i, char **av)
{
	phil->philo_id = i;
	phil->num_philo = ft_atoi(av[1]);
	phil->time_to_die = ft_atoi(av[2]);
	phil->time_to_eat = ft_atoi(av[3]);
	phil->time_to_sleep = ft_atoi(av[4]);
}

int	ft_init_all(int ac, char **av, t_philo *lst)
{
	int				*forks;
	pthread_mutex_t	*mutex;
	int				i;
	t_philo			*tmp;

	i = 0;
	if (ft_init_lst(av, &mutex, &forks))
		return (free(lst), EXIT_FAILURE);
	tmp = lst;
	while (i < ft_atoi(av[1]))
	{
		if (ac == 6)
			tmp->num_of_time_epm_eat = ft_atoi(av[5]);
		(ft_init_philo(tmp, mutex, forks, i), ft_suite(tmp, i, av));
		if (i + 1 < ft_atoi(av[1]))
		{
			tmp->next = malloc(sizeof(*tmp));
			if (!tmp->next)
				return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), 1);
			tmp->next->prec = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	return (EXIT_SUCCESS);
}
