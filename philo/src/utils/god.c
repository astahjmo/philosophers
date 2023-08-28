/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 19:02:27 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_dead(void);

t_bool	is_dead(t_philo *philo)
{
	int	time;

	time = philo->last_eaten;
	if (time == -1 && getter_rules()[PHILO_QT] != 1)
		return (FALSE);
	if (get_time() - time > (time_t)getter_rules()[LIFETIME])
	{
		print_action("died", philo);
		set_dead();
		return (TRUE);
	}
	return (FALSE);
}

static void	set_dead(void)
{
	getter_table()->is_the_end = TRUE;
}

t_bool	is_end(void)
{
	return (getter_table()->is_the_end);
}

static void	wait(t_philo *philo)
{
	size_t	count;

	count = -1;
	while (++count < getter_rules()[PHILO_QT])
		pthread_join(philo[count].thread_id, NULL);
	pthread_mutex_destroy(&getter_table()->channel);
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
		if (has_lunch() == getter_rules()[PHILO_QT])
			break ;
		while (count < getter_rules()[PHILO_QT])
		{
			is_dead(&philo[count]);
			count++;
		}
		count = 0;
		usleep(500);
	}
	wait(philo);
}
