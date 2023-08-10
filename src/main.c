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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	*getter_rules(void)
{
	static size_t	rules[MAX_ARGS];

	return (rules);
}

int	main(int argc, char *argv[])
{
	size_t		*rules;
	short int	ix;

	rules = getter_rules();
	ix = 0;
	if (argc > 6 || argc < 5)
		return (print_fd(WRONG_PARMS, 1));
	while (++ix < (argc - 1))
	{
		if (!check_isdigit(argv[ix]))
			return (print_fd(WRONG_PARMS, 2));
		if (!check_negative(argv[ix]))
			return (print_fd(NEGATIVE_VAL, 2));
		rules[ix] = ft_atoi(argv[ix]);
		if (ix == argc && argc == 6)
			rules[argc - 1] = ft_atoi(argv[argc - 1]);
		else if (ix < 6 && ix == 5)
			rules[argc - 1] = 0;
	}
	printf("%lu\n", rules[ix]);
}
