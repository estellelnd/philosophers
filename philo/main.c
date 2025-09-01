/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:06:37 by estellek          #+#    #+#             */
/*   Updated: 2025/08/12 16:27:12 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_arguments(int argc, char **argv)
{
	//check valid integers
	//maximum value with macros to avoid overflow
	//only numbers
	//numbers of meals 
}

void	init_values(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		init_values(argc, argv);
	}
	else
		write(2, "Bad arguments\n", 16);
	return (0);
}
