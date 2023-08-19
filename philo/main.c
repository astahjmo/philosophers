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
#include <stdio.h>

size_t	*getter_rules(void)
{
	static size_t	rules[MAX_ARGS];

	return (rules);
}

int	main(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
		return (print_fd(WRONG_PARMS, 1));
	if (!init_arguments(argc, argv))
		return (print_fd(*get_error_msg(), STDERR_FILENO));
}
