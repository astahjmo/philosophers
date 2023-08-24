#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 1 || (size_t)philo->id == getter_rules()[PHILO_QT])
	{
		pthread_mutex_lock(philo->left_fork);
		print_action("has take a fork", philo);
		pthread_mutex_lock(&philo->rigth_fork);
		print_action("has take a fork", philo);
		return ;
	}
	pthread_mutex_lock(&philo->rigth_fork);
	print_action("has take a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	print_action("has take a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->rigth_fork);
	print_action("drop a fork", philo);
}
