/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:39:40 by jose              #+#    #+#             */
/*   Updated: 2023/05/01 17:23:26 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routine(void *t)
{
	return t;
}

static int	ft_thread_create(t_lst_philo	*lst)
{
	pthread_t	*thrd;
	t_lst_philo	*tmp;

	tmp = lst;
	while (tmp)
	{
		thrd = malloc(sizeof(*thrd));
		if (!thrd)
			return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), EXIT_FAILURE);
		if (pthread_create(thrd, NULL, &ft_routine, (void*)tmp->philo))
			return (free(thrd), ft_free_lst_philo(lst), ft_error(THREAD_CREATE), EXIT_FAILURE);
		tmp->philo->philo_thread = thrd;
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_thread_join(t_lst_philo	*lst)
{
	t_lst_philo	*tmp;
	pthread_t	thrd;

	tmp = lst;
	while (tmp)
	{
		thrd = *(tmp->philo->philo_thread);
		if (pthread_join(thrd, NULL))
			return (ft_free_lst_philo(lst), ft_error(THREAD_JOIN), EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

void	ft_philo_manager(int ac, char **av)
{
	t_lst_philo	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (ft_error(MALLOC_FAILED));
	if (ft_init_all(ac, av, lst))
		return ;
	if (ft_thread_create(lst))
		return ;
	if (ft_thread_join(lst))
		return ;
	return (ft_free_lst_philo(lst));
}
