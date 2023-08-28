/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:16:56 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 17:40:16 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

t_bool	is_negative(char c)
{
	return (c == '-');
}

t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	check_negative(char *str)
{
	while (*str)
	{
		if (is_negative(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	check_isdigit(char *str)
{
	while (*str)
	{
		if (!is_digit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

size_t	has_lunch(void)
{
	int	lunch;

	lunch = getter_table()->finishes;
	return (lunch);
}
