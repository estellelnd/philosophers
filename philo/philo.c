/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elandi <elandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:56:53 by estellek          #+#    #+#             */
/*   Updated: 2025/10/08 08:40:20 by elandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_action(philo, "has taken a fork");
}
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->death_mutex);
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	if (philo->data->must_eat && philo->meals_eaten >= philo->data->must_eat)
		philo->data->end = 1;
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_action(philo, "is thinking");
}

void	died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->someone_died = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
	print_action(philo, "died");
	philo->data->end = 1;
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->data->end == 0)
	{
		grab_forks(philo);
		eating(philo);
		put_down_forks(philo);
		sleeping(philo);
		died(philo);
	}
	return (NULL);
}
