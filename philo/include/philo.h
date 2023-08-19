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
# include "unistd.h"
# include <stddef.h>
# include <stdint.h>
# define MAX_ARGS 5
# define FALSE 0
# define TRUE 1

typedef unsigned int	t_bool;
typedef short int		t_sint;

typedef struct _s_philo
{
	t_sint	id;
	t_sint	left_fork;
	t_sint	right_fork;
	t_sint	last_eaten;
	t_sint	times_to_eat;
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

#endif
