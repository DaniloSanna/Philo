/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:07:05 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:07:07 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Invalid number of arguments!\n", 2);
		ft_putstr_fd("Include: nbr_philo time_to_starve time_eating \
		time_sleeping (nbr_of_meals - opitional).\n", 2);
		return (0);
	}
	while (argv[i])
	{
		if (!ft_str_isdigit(argv[i]))
		{
			ft_putstr_fd("Invalid type of arguments!\
			 Arguments must be numbers.\n", 2);
			return (0);
		}
		if (!chek_str_int_positive(argv[i]))
		{
			ft_putstr_fd("Invalid arguments! \
			Arguments must be numbers integers and positive.\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
