/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:56:53 by estellek          #+#    #+#             */
/*   Updated: 2025/10/06 21:57:33 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->data->simulation_end)
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
