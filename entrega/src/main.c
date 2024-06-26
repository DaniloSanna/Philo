/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:58 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:21:50 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_ms_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_events(t_philo *philo, char *event)
{
	time_t	time;

	pthread_mutex_lock(&philo->tabdinner->msg);
	time = get_ms_time() - philo->tabdinner->init;
	printf("%ld %d %s\n", time, philo->id, event);
	pthread_mutex_unlock(&philo->tabdinner->msg);
}

void	only_one(char **argv)
{
	int	life_time;

	life_time = ft_atoi(argv[2]);
	printf("0 1 %s \n", TAKEN_FORK);
	usleep(life_time * 1000);
	printf("%d 1 died\n", life_time);
}

int	main(int argc, char **argv)
{
	t_dinnertable	*tabdinner;

	if (!check_args(argc, argv))
		return (-1);
	if (ft_atoi(argv[1]) == 1)
		return (only_one(argv), -3);
	tabdinner = (t_dinnertable *) ft_calloc(1, sizeof(t_dinnertable));
	if (!set_table_for_dinner(tabdinner, argv))
		return (-1);
	if (!init_mutex(tabdinner))
		return (-4);
	init_philo(tabdinner);
	if (!philos_threads_born(tabdinner))
	{
		free_struct(tabdinner);
		return (-1);
	}
	free_struct(tabdinner);
	return (0);
}
