#include "philo.h"

void	init_philo(t_dinnertable	*tabdinner)
{
	int	i;

	i = 0;
	while (i < tabdinner->nbr_philo)
	{
		tabdinner->philo[i].stop = FALSE;
		tabdinner->philo[i].nbr_meals = 0;
		tabdinner->philo[i].id = i + 1;
		tabdinner->philo[i].tabdinner = tabdinner;
		tabdinner->philo[i].r_fork = &tabdinner->fork[i];
		if (i == tabdinner->nbr_philo - 1)
			tabdinner->philo[i].l_fork = &tabdinner->fork[0];
		else
			tabdinner->philo[i].l_fork = &tabdinner->fork[i + 1];
		i++;
	}
}

int	set_table_for_dinner(t_dinnertable *tabdinner, char **argv)
{
	tabdinner->stop = 0;
	tabdinner->nbr_meals = 0;
	tabdinner->nbr_philo = ft_atoi(argv[1]);
	tabdinner->time_to_starv = ft_atoi(argv[2]);
	tabdinner->time_eating = ft_atoi(argv[3]);
	tabdinner->time_sleeping = ft_atoi(argv[4]);
	if (argv[5])
		tabdinner->nbr_meals = ft_atoi(argv[5]);
	tabdinner->philo = ft_calloc(tabdinner->nbr_philo, sizeof(t_philo));
	tabdinner->fork = ft_calloc(tabdinner->nbr_philo, sizeof(pthread_mutex_t));
	if (!tabdinner->philo || !tabdinner->fork)
	{
		ft_putstr_fd("Malloc error on table set...\n", 2);
		free(tabdinner->philo);
		free(tabdinner->fork);
		free(tabdinner);
		return (0);
	}
	return (1);
}

int	init_mutex(t_dinnertable *tabdinner)
{
	int	i;

	i = 0;
	while (i < (int)tabdinner->nbr_philo)
	{
		if (pthread_mutex_init(&tabdinner->fork[i], NULL))
			break ;
		i++;
	}
	if (i-- != (int)tabdinner->nbr_philo || \
	pthread_mutex_init(&tabdinner->msg, NULL) || \
	pthread_mutex_init(&tabdinner->mstop, NULL))
	{
		while (i >= 0)
			pthread_mutex_destroy(&tabdinner->fork[i--]);
		ft_putstr_fd("Pthread error on Mutex init...\n", 2);
		free(tabdinner->philo);
		free(tabdinner->fork);
		free(tabdinner);
		return (0);
	}
	return (1);
}

void	free_struct(t_dinnertable *tabdinner)
{
	int	i;

	i = 0;
	while (i < tabdinner->nbr_philo)
	{
		if (pthread_join(tabdinner->philo[i].thread, NULL))
			ft_putstr_fd("Pthread_join error...\n", 2);
		i++;
	}
	free(tabdinner->philo);
	i = 0;
	while (i < tabdinner->nbr_philo)
	{
		if (pthread_mutex_destroy(&tabdinner->fork[i]))
			ft_putstr_fd("Pthread_mutex_destroy error...\n", 2);
		i++;
	}
	free(tabdinner->fork);
	if (pthread_mutex_destroy(&tabdinner->msg))
		ft_putstr_fd("Pthread_join error...\n", 2);
	if (pthread_mutex_destroy(&tabdinner->mstop))
		ft_putstr_fd("Pthread_join error...\n", 2);
	free(tabdinner);
}
