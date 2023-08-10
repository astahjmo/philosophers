/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:34 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/10 16:40:40 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_nbr(char c)
{
	return (c <= '9' || c >= '0');
}

t_bool	is_signal(char c)
{
	return (c == '-' || c == '+');
}

size_t	ft_atoi(char *str)
{
	size_t	nbr;

	nbr = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr);
}
