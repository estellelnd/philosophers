/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:03:51 by estellek          #+#    #+#             */
/*   Updated: 2025/09/02 00:33:24 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */

// thread = philosophe
// mutex = fourchette
// steps : manger, dormir, penser
// manger avec 2 fourchettes only
// 10 millisecondes = 10 000 microsecondes pour afficher la mort

/*
	arg1 = number_of_philosophers (nombre de philosophes et nombre de fourchettes)
	arg2 = time_to_die (s’il a pas mangé depuis time_to_die millisecondes il meurt)
	arg3 = time_to_eat (temps pour manger avec deux fourchettes en millisecondes)
	arg4 = time_to_sleep (temps pour dormir en milliseconde)
	arg5 = number_of_times_each_philosopher_must_eat (nombre de fois que chaque philosophe doit manger,
			arg optionnel)
 */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				counter_meals;
	int				counter_philos;
	bool			dead;
	bool			full;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_philo;

int					ft_atoi(char *str);

#endif
