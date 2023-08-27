/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/27 23:27:01 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static void	set_dead(void);

t_bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_lunch);
	if ((get_time() - philo->last_eaten) > (int)getter_rules()[LIFETIME] &&
			philo->times_to_eat > 0)
	{
		print_action("is dead", philo);
		set_dead();
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

static void	wait(t_philo *philo)
{
	size_t	count;

	count = -1;
	while (++count < getter_rules()[PHILO_QT])
		pthread_join(philo[count].thread_id, NULL);
	pthread_mutex_destroy(&getter_table()->channel);
	pthread_mutex_destroy(&getter_table()->end);
	count = -1;
	while (++count < getter_rules()[PHILO_QT])
		pthread_mutex_destroy(&philo[count].rigth_fork);
}

void	god(void)
{
	t_philo	*philo;
	size_t	count;

	count = 0;
	philo = getter_table()->philo;
	while (!is_end() && getter_rules()[PHILO_QT] > 1)
	{
		count = 0;
		while (count < getter_rules()[PHILO_QT])
		{
			count++;
		}
		count = 0;
		usleep(50);
	}
	wait(philo);
}
