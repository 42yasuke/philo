/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:39:40 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 09:56:35 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_philo(void *phil)
{
	t_philo				*philo;
	struct timeval		start;
	struct timeval		end;
	unsigned long long	elapsed_ms;

	philo = (t_philo*)phil;
	gettimeofday(&start, NULL);
	while (ft_all_alive(philo) && !ft_all_eat(philo))
	{
		if (ft_eat(philo) && ft_your_t(philo))
		{
			philo->is_thinking = false;
			gettimeofday(&end, NULL);
			elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
			ft_print_eat(philo, elapsed_ms);
			if (end.tv_usec * 1000 - philo->time_last_meal < philo->time_to_die)
			{
				if (end.tv_usec * 1000 - philo->time_last_meal + philo->time_to_eat < philo->time_to_die)
				{
					usleep(philo->time_to_eat * 1000);
					philo->time_last_meal = end.tv_usec * 1000 + philo->time_to_eat;
				}
				else
				{
					pthread_mutex_lock(philo->mutex); //on ne sait jamais
					philo->is_dead = true;
					pthread_mutex_unlock(philo->mutex);
					if (philo->time_to_die > philo->time_to_eat)
						usleep((philo->time_to_die - philo->time_to_eat) * 1000);
					gettimeofday(&end, NULL);
					elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
					ft_print_death(philo, elapsed_ms);
					break ;
				}
			}
			else
			{
				pthread_mutex_lock(philo->mutex); //on ne sait jamais
				philo->is_dead = true;
				pthread_mutex_unlock(philo->mutex);
				elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
				ft_print_death(philo, elapsed_ms);
				break ;
			}
			if (ft_all_alive(philo))
			{
				gettimeofday(&end, NULL);
				elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
				ft_sleep(philo, elapsed_ms);
				if (end.tv_usec * 1000 - philo->time_last_meal + philo->time_to_sleep < philo->time_to_eat)
					usleep(philo->time_to_sleep * 1000);
				else
				{
					pthread_mutex_lock(philo->mutex); //on ne sait jamais
					philo->is_dead = true;
					pthread_mutex_unlock(philo->mutex);
					if (philo->time_to_die - philo->time_to_sleep)
						usleep((philo->time_to_die - philo->time_to_sleep) * 1000);
					gettimeofday(&end, NULL);
					elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
					ft_print_death(philo, elapsed_ms);
					break ;
				}
			}
		}
		else
		{
			gettimeofday(&end, NULL);
			elapsed_ms = (end.tv_usec - start.tv_usec) / 1000;
			ft_think(philo, elapsed_ms);
		}
	}
	return (phil);
}

static int	ft_thread_create(t_philo *lst)
{
	pthread_t	*thrd;
	t_philo	*tmp;

	tmp = lst;
	while (tmp)
	{
		thrd = malloc(sizeof(*thrd));
		if (!thrd)
			return (ft_free_lst_philo(lst), ft_error(MALLOC_FAILED), EXIT_FAILURE);
		if (pthread_create(thrd, NULL, &ft_philo, (void*)tmp))
			return (free(thrd), ft_free_lst_philo(lst), ft_error(THREAD_CREATE), EXIT_FAILURE);
		tmp->philo_thread = thrd;
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_thread_join(t_philo	*lst)
{
	t_philo	*tmp;
	pthread_t	thrd;

	tmp = lst;
	while (tmp)
	{
		thrd = *(tmp->philo_thread);
		if (pthread_join(thrd, NULL))
			return (ft_free_lst_philo(lst), ft_error(THREAD_JOIN), EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

void	ft_philo_manager(int ac, char **av)
{
	t_philo	*lst;

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
