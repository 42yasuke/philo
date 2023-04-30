/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:51:31 by jose              #+#    #+#             */
/*   Updated: 2023/04/30 03:00:49 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_lst(t_lst_philo **lst)
{
	(*lst)->philo = NULL;
	(*lst)->next = NULL;
}

static void ft_init_philo(t_philo **philo)
{
	(*philo)->forks = NULL;
	(*philo)->is_dead = false;
	(*philo)->num_meal = 0;
	(*philo)->num_of_time_epm_eat = -1;
	(*philo)->num_philo = 0;
	(*philo)->philo_id = -1;
	(*philo)->time_to_die = 0;
}

static void	ft_suite(t_lst_philo **tmp, t_philo **philo, pthread_mutex_t *mutex, int *forks)
{
	ft_init_philo(philo);
	(*philo)->mutex = *mutex;
	(*philo)->forks = forks;
	(*tmp)->next = NULL;
}

static void	ft_suite2(char **av, t_lst_philo **lst, pthread_mutex_t *mutex, int **forks)
{
	*forks = malloc(sizeof(**forks) * ft_atoi(av[1]));
	if (!*forks)
		return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED));
	memset(*forks, 0, sizeof(**forks) * ft_atoi(av[1]));
	if (pthread_mutex_init(mutex, NULL))
		return (free(*forks), ft_free_lst_philo(lst), ft_error(MUTEX_INIT));
}

void	ft_init_all(int ac, char **av, t_lst_philo **lst)
{
	int				*forks;
	pthread_mutex_t	mutex;
	int				i;
	t_lst_philo		*tmp;

	i = 0;
	ft_init_lst(lst);
	ft_suite2(av, lst, &mutex, &forks);
	while (i < ft_atoi(av[1]))
	{
		if (ac == 4)
			tmp->philo->num_of_time_epm_eat = ft_atoi(av[3]);
		ft_suite(&tmp, &tmp->philo, &mutex, forks);
		if (i + 1 < ft_atoi(av[1]))
		{
			tmp->next = malloc(sizeof(*tmp));
			if (!tmp->next)
				return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED));
		}
		tmp = tmp->next;
		i++;
	}
}
