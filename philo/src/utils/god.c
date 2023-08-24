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
#include <pthread.h>
#include <stdio.h>

static void	set_dead(void);

t_bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_lunch);
	if ((get_time() - philo->last_eaten) > (int)getter_rules()[LIFETIME])
	{
		return (TRUE);
		
	}
	pthread_mutex_unlock(&philo->last_lunch);
	return (FALSE);
}

static void	set_dead(void)
{
	pthread_mutex_lock(&getter_table()->end);
	getter_table()->is_the_end = 1;
	pthread_mutex_unlock(&getter_table()->end);
}

t_bool	is_end(void)
{
	t_bool	end;

	pthread_mutex_lock(&getter_table()->end);
	end = getter_table()->is_the_end;
	pthread_mutex_unlock(&getter_table()->end);
	return (end);
}

void	god(void)
{
	t_philo	*philo;
	size_t	count;
	t_bool	end;

	end = FALSE;
	count = 0;
	philo = getter_table()->philo;
	while (!end)
	{
		while (count < getter_rules()[PHILO_QT])
		{
			if (is_dead(&philo[count]))
			{
				end = TRUE;
				set_dead();
			}	
			count++;
		}
		count = 0;
	}
}
