/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:53:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/26 14:10:36 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isdigit(int c)
{
	return ('0' <= c && '9' >= c);
}

bool	ft_isemtystr(char *str)
{
	return (*str == '\0');
}

int	ft_atoi(char *str)
{
	int (i), (r);
	long (nbr);
	(1) && (i = 0), (r = 1), (nbr = 0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		if ((nbr > 2147483647))
			return (-1);
		i++;
	}
	return (nbr * r);
}
