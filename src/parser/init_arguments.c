/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/10 18:24:44 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_arguments(int argc, char *argv[])
{
	size_t	*rules;
	int		ix;

	rules = getter_rules();
	ix = 1;
	while (ix < argc)
	{
		if (!check_isdigit(argv[ix - 1]))
			return (set_error_exit(WRONG_PARMS));
		if (!check_negative(argv[ix - 1]))
			return (set_error_exit(NEGATIVE_VAL));
		rules[ix - 1] = ft_atoi(argv[ix]);
		ix++;
	}
	return (TRUE);
}
