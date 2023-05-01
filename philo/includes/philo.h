/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:09:12 by jose              #+#    #+#             */
/*   Updated: 2023/05/01 17:25:19 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				num_philo;
	int				time_to_die;
	int				num_of_time_epm_eat;
	pthread_mutex_t	*mutex;
	int				num_meal;
	int				philo_id;
	int				*forks;
	int				is_dead;
	pthread_t		*philo_thread;
}	t_philo;

typedef struct s_lst_philo
{
	struct s_philo		*philo;
	struct s_lst_philo	*next;
}	t_lst_philo;

/*	error's macro	*/
# define BAD_NUM_PARAMETERS 0
# define BAD_PARAMETERS 1
# define MALLOC_FAILED 2
# define MUTEX_INIT 3
# define THREAD_CREATE 4
# define THREAD_JOIN 5

/*	error.c	*/
void	ft_error(int err);

/*	utils.c	*/
int		ft_strlen(char *str);
int		ft_only_digit(char *str);
int		ft_atoi(const char *nptr);
int		parsing_manager(int ac, char **av);

/*	free.c	*/
void	ft_free_lst_philo(t_lst_philo *lst);

/*	philo.c	*/
void	ft_philo_manager(int ac, char **av);

/*	philo_utils.c	*/
int		ft_init_all(int ac, char **av, t_lst_philo *lst);

#endif
