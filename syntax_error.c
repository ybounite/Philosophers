/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:20:31 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/21 14:42:55 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstre(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

void	syntax_error(short option)
{
	if (option == 1)
	{
		ft_putstre("\e[1;31mSyntax error\n\e[0m");
		ft_putstre("Usage:\t./philo {ARGUMENTS}...\n");
		ft_putstre("\e[1;32mARGUMENTS:\n\e[0m");
		ft_putstre("\tARG1:\t\tnumber_of_philosophers\n");
		ft_putstre("\tARG2:\t\ttime_to_die\n");
		ft_putstre("\tARG3:\t\ttime_to_eat\n");
		ft_putstre("\tARG4:\t\ttime_to_sleep\n");
		ft_putstre("\tOPTIONAL:\tnumber_of_times_each_philosopher_must_eat\n");
	}
	if (option == 2)
		ft_putstre("Error: Invalid argument\n");
	if (option == 3)
		ft_putstre("Error: you need at least one philosopher\n");
}
