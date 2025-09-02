/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:19:07 by estellek          #+#    #+#             */
/*   Updated: 2025/09/02 16:44:55 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_atoi(argv[1]) == 0)
	{
		printf("You need at least 1 philosopher\n");
		exit(1);
	}
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
			exit(1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				exit(1);
			j++;
		}
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > INT_MAX)
		{
			printf("Bad range\n");
			exit(1);
		}
		i++;
	}
}
