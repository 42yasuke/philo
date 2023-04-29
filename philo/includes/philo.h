/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:09:12 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 03:23:10 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

/*	macro's error	*/
# define BAD_NUM_PARAMETERS 0
# define BAD_PARAMETERS 1

/*	error.c	*/
void	ft_error(int err, char *msg_err);

/*	utils.c	*/
int		ft_strlen(char *str);
int		ft_only_digit(char *str);
int		ft_atoi(const char *nptr);
int		parsing_manager(int ac, char **av);

#endif
