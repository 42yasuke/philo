/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:24:27 by jose              #+#    #+#             */
/*   Updated: 2023/08/25 13:30:51 by jose             ###   ########.fr       */
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
# include <stdio.h>
# include <stdio.h>

typedef unsigned long long int	t_ull;

typedef struct s_philo
{
	struct s_config		*conf;
	t_ull				t_last_meal;
	int					id;
	int					eat_num;
}	t_philo;

typedef struct s_config
{
	pthread_mutex_t	*forks;
	pthread_t		*thrds;
	t_philo			*philo;
	pthread_mutex_t	*m;
	int				philo_num;
	int				times_to_eat;
	t_ull			t_eat;
	t_ull			t_sleep;
	t_ull			t_die;
	int				stop_thread;
}	t_config;

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
t_ull	ft_atoull(const char *nptr);
int		parsing_manager(int ac, char **av);

/*	utils2.c	*/
t_ull	timestamp_in_ms(void);
t_ull	gettimeofday_ms(void);

/*	ft_itoa.c	*/
char	*ft_itoa(t_ull n);

/*	free.c	*/
void	ft_free_all(t_config *lst);

/*	philo.c	*/
void	ft_philo_manager(int ac, char **av);

/*	philo_utils.c	*/
int		ft_init_all(int ac, char **av, t_config *conf);

/*	philo_utils2.c	*/
int		ft_all_alive(t_config *conf);
int		ft_all_eat(t_config *conf);

/*	eat.c	*/
int		ft_eat(t_philo *philo);

/*	dead.c	*/
void	ft_print_death(t_philo *philo);

/*	think.c	*/
int		ft_think(t_philo *philo);

/*	sleep.c	*/
int		ft_sleep(t_philo *philo);

#endif