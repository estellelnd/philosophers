/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:06:37 by estellek          #+#    #+#             */
/*   Updated: 2025/09/02 16:39:00 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_values(int argc, char **argv)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	data->count_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		init_values(argc, argv);
	else
		write(2, "Bad arguments\n", 16);
	return (0);
}
