#include "philo.h"
#include <stdio.h>

void	update_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_lunch);
	philo->last_eaten = get_time();
	pthread_mutex_unlock(&philo->last_lunch);
}
