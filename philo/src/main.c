/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:11:00 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 03:30:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	(void)av;
	if(ac != 3 || ac != 4)
		ft_error(BAD_NUM_PARAMETERS, "Error: too few args\n");
	else if (!parsing_manager(ac, av))
		ft_error(BAD_PARAMETERS, "Error: bad parameters\n");
	else
		write(STDOUT_FILENO, "tout est bon\n", 14);
	return (EXIT_SUCCESS);
}
