/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:51:31 by jose              #+#    #+#             */
/*   Updated: 2023/05/01 17:26:06 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_init_philo(t_lst_philo *lst, t_philo *philo, pthread_mutex_t *mutex, int *forks)
{
	philo->is_dead = false;
	philo->num_meal = 0;
	philo->num_of_time_epm_eat = -1;
	philo->num_philo = 0;
	philo->philo_id = -1;
	philo->time_to_die = 0;
	philo->philo_thread = NULL;
	philo->forks = forks;
	philo->mutex = mutex;
	lst->next = NULL;
}

static int	ft_init_lst(char **av, t_lst_philo *lst, pthread_mutex_t **mutex, int **forks)
{
	lst->philo = NULL;
	lst->next = NULL;
	*forks = malloc(sizeof(**forks) * ft_atoi(av[1]));
	if (!*forks)
		return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), EXIT_FAILURE);
	memset(*forks, 0, sizeof(**forks) * ft_atoi(av[1]));
	*mutex = malloc(sizeof(**mutex));
	if (!*mutex)
		return (free(*forks), ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), EXIT_FAILURE);
	if (pthread_mutex_init(*mutex, NULL))
		return (free(*forks), ft_free_lst_philo(lst), ft_error(MUTEX_INIT), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_init_all(int ac, char **av, t_lst_philo *lst)
{
	int				*forks;
	pthread_mutex_t	*mutex;
	int				i;
	t_lst_philo		*tmp;

	i = 0;
	if (ft_init_lst(av, lst, &mutex, &forks))
		return (EXIT_FAILURE);
	while (i < ft_atoi(av[1]))
	{
		if (ac == 4)
			tmp->philo->num_of_time_epm_eat = ft_atoi(av[3]);
		ft_init_philo(tmp, tmp->philo, mutex, forks);
		if (i + 1 < ft_atoi(av[1]))
		{
			tmp->next = malloc(sizeof(*tmp));
			if (!tmp->next)
				return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	return (EXIT_SUCCESS);
}
