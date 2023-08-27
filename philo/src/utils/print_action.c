/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:27:11 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/27 23:27:12 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *msg , t_philo *philo)
{
	if (is_end())
		return ;
	pthread_mutex_lock(&philo->table->channel);
	if (!is_end())
		printf("%5d %d %s\n", get_time_from_start(), philo->id, msg);
	pthread_mutex_unlock(&philo->table->channel);
}
