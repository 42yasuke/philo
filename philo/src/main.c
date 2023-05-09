/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:11:00 by jose              #+#    #+#             */
/*   Updated: 2023/05/10 01:34:54 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		ft_error(BAD_NUM_PARAMETERS);
	else if (!parsing_manager(ac, av))
		ft_error(BAD_PARAMETERS);
	else
		ft_philo_manager(ac, av);
	return (EXIT_SUCCESS);
}
