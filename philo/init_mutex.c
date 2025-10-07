/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:13:56 by elandi            #+#    #+#             */
/*   Updated: 2025/10/06 21:55:36 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->forks)
	{
		free(data);
		exit(1);
	}
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free(data->forks);
			free(data);
			exit(1);
		}
		i++;
	}
}
void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
}

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}


void create_threads(t_data *data)
{
	int i;

	data->philos = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (!data->philos)
	{
		free(data->forks);
		free(data);
		exit(1);
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philos[i], NULL, philosopher_routine, data) != 0)
		{
			write(2, "Thread creation failed\n", 23);
			exit(1);
		}
		i++;
	}
}
