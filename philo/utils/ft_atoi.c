/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estellek <estellek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:09:16 by elandi            #+#    #+#             */
/*   Updated: 2025/08/12 16:21:32 by estellek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	symbol;
	int	res;

	i = 0;
	res = 0;
	symbol = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symbol = symbol * -1;
		i++;
	}
	while (!(str[i] < '0' || str[i] > '9'))
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (res * symbol);
}
