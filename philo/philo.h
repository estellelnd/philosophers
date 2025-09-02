/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:03:51 by estellek          #+#    #+#             */
/*   Updated: 2025/09/02 16:46:14 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* typedef struct s_fork
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
 */

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
	t_fork			*left_fork;
	t_fork			*right_fork;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	int				someone_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_fork			*forks;
	t_philo			*philos;
}					t_data;

int					ft_atoi(char *str);

// u_int64_t	get_time(void);
// int			ft_usleep(useconds_t time);

#endif
