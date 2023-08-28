/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:35:00 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 19:23:07 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define WRONG_PARMS "Incorrect parameters. Please use the following format:\n\
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] \
[times_philo_must_eat] <- optional\n"
# define NEGATIVE_VAL "You can't use a negative value!\n"
# define WRONG_QT_PHILO "You need to pass a value between 0 - 200\
 as philo quantity\n"
#endif
