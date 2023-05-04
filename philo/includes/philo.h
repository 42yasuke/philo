/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:09:12 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 10:18:57 by jose             ###   ########.fr       */
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
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_time_epm_eat;
	pthread_mutex_t	*mutex;
	int				num_meal;
	int				philo_id;
	int				*forks;
	int				is_dead;
	pthread_t		*philo_thread;
	struct s_philo	*next;
	struct s_philo	*prec;
	int				time_last_meal;
	int				is_thinking;
}	t_philo;

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
size_t	ft_strlen(char *str);
int		ft_only_digit(char *str);
int		ft_atoi(const char *nptr);
int		parsing_manager(int ac, char **av);

/*	ft_itoa.c	*/
char	*ft_itoa(unsigned long long n);

/*	free.c	*/
void	ft_free_lst_philo(t_philo *lst);

/*	philo.c	*/
void	ft_philo_manager(int ac, char **av);

/*	philo_utils.c	*/
int		ft_init_all(int ac, char **av, t_philo *lst);

/*	philo_utils2.c	*/
int		ft_all_alive(t_philo *philo);
int		ft_all_eat(t_philo *philo);
t_philo	*ft_first_philo(t_philo *philo);

/*	eat.c	*/
int		ft_eat(t_philo *philo);
void	ft_print_eat(t_philo *philo, unsigned long long elapsed_ms);

/*	eat_utils.c	*/
int		ft_your_t(t_philo *philo);

/*	dead.c	*/
void	ft_print_death(t_philo *philo, unsigned long long elapsed_ms);

/*	think.c	*/
void	ft_think(t_philo *philo, unsigned long long elapsed_ms);

/*	sleep.c	*/
void	ft_sleep(t_philo *philo, unsigned long long elapsed_ms);

#endif
