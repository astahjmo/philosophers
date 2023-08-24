/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:38:07 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/10 18:13:56 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "./error.h"
# include <stddef.h>
# include <pthread.h>
# include <stdint.h>
# include <unistd.h>
# include <malloc.h>
# include <sys/time.h>
# define MAX_ARGS 5
# define FALSE 0
# define TRUE 1
# define PHILO_QT 0
# define LIFETIME 1
# define LUNCHTIME 2
# define SLEEP_TIME 3
# define TIMES_TO_EAT 4
# define MAX_PHILO 200

# include <sys/time.h>

typedef unsigned int	t_bool;
typedef short int		t_sint;
typedef struct _s_table	t_table;
typedef struct _s_philo	t_philo;

typedef struct _s_table
{
	pthread_mutex_t	channel;
	pthread_mutex_t	end;
	t_bool			is_the_end;
	int				start;
	t_philo			*philo;

}	t_table;

typedef struct _s_philo
{
	t_sint			id;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	rigth_fork;
	int				last_eaten;
	t_sint			times_to_eat;
	int				start;
	pthread_mutex_t	last_lunch;
	size_t			lifetime;
	size_t			lunch_time;
	size_t			sleep_time;
	t_table			*table;
}	t_philo;

typedef enum e_states
{
	EATING,
	THINKING,
	SLEEPING,
	DIED,
}	t_states;

typedef struct _s_rules
{
	size_t		*n_philo;
	size_t		die_count;
	size_t		eat_count;
	size_t		sleep_count;
}				t_rules;

int				ft_strlen(char *str);
int				print_fd(char *str, int fd);
size_t			ft_atoi(char *str);
t_bool			check_isdigit(char *str);
t_bool			check_negative(char *str);
t_bool			is_valid(char *str);
char			**get_error_msg(void);
t_bool			set_error_exit(char *msg);
size_t			*getter_rules(void);
t_bool			init_arguments(int argc, char *argv[]);
int				get_time(void);
t_table			*getter_table(void);
void			initial(void);
char			*ft_itoa(int n);
void			try_to_eat(t_philo *philo);
int				get_time_from_start(void);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			destroy_philo(void);
t_bool			is_end(void);
void			eating(t_philo *philo);
void			print_action(char *msg, t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
void			update_time(t_philo *philo);
void			god(void);
#endif
