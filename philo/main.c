/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elandi <elandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:06:37 by estellek          #+#    #+#             */
/*   Updated: 2025/10/08 08:41:02 by elandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_values(int argc, char **argv)
{
	t_data	*data;

	check_arguments(argc, argv);
	data = malloc(sizeof(t_data));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || (argc == 6
			&& data->number_of_times_each_philosopher_must_eat <= 0))
	{
		free(data);
		exit(1);
	}
	init_forks(data);
	//fonction a faire pour creer les threads
	join_threads(data);
	destroy_all(data);
	free(data->forks);
	free(data);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		init_values(argc, argv);
	else
		write(2, "Bad arguments\n", 15);
	return (0);
}
