/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:20:31 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 16:00:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		ft_putstre(RED"Error\e[0m:\nInvalid argument\n");
	if (option == 3)
		ft_putstre(RED"Error\e[0m:\nyou need at least one philosopher\n");
}

bool	check_syntax_error(int arc, char **arv)
{
	int	i;

	i = 1;
	while (i < arc)
	{
		if (check_isdigit(arv[i]) || ft_isemtystr(arv[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[0] == '+' || str[0] == '-'))
			i++;
		if (!ft_isdigit(str[i]))
			return (syntax_error(2), true);
		i++;
	}
	if (i == false)
		return (syntax_error(2), true);
	return (false);
}
