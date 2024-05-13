/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itscircleoflife.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:30 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:51:25 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	life_circle(t_philo *philo, char *event)
{
	pthread_mutex_lock(&philo->tabdinner->mstop);
	if (philo->tabdinner->stop)
	{
		pthread_mutex_unlock(&philo->tabdinner->mstop);
		return (STOP);
	}
	pthread_mutex_unlock(&philo->tabdinner->mstop);
	if (!ft_strcmp(event, EATING))
	{
		print_events(philo, EATING);
		pthread_mutex_lock(&philo->last_meal_flag);
		philo->last_meal = get_ms_time();
		pthread_mutex_unlock(&philo->last_meal_flag);
		philo->nbr_meals++;
		if (philo->nbr_meals == philo->tabdinner->nbr_meals)
			check_limit_meals(philo->tabdinner);
	}
	else
		print_events(philo, event);
	return (CONTINUE);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		so_wait(philo->tabdinner->time_eating / 2, philo->tabdinner);
	while (philo->stop == FALSE)
	{
		take_fork_pair_or_even(philo);
		philo->stop = life_circle(philo, EATING);
		so_wait(philo->tabdinner->time_eating, philo->tabdinner);
		philo->stop = life_circle(philo, SLEEPING);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		so_wait(philo->tabdinner->time_sleeping, philo->tabdinner);
		philo->stop = life_circle(philo, THINKING);
	}
	if (philo->r_fork == philo->l_fork)
		pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

int	check_limit_meals(t_dinnertable *tabdinner)
{
	int	i;

	i = 0;
	while (i < tabdinner->nbr_philo)
	{
		if (tabdinner->philo[i].nbr_meals < tabdinner->nbr_meals)
			return (FALSE);
		i++;
	}
	pthread_mutex_lock(&tabdinner->mstop);
	tabdinner->stop = TRUE;
	pthread_mutex_unlock(&tabdinner->mstop);
	return (TRUE);
}

void	verify_death(t_dinnertable *tabdinner)
{
	int		i;
	time_t	time;

	while (1)
	{
		i = -1;
		time = get_ms_time();
		while (++i < tabdinner->nbr_philo)
		{
			pthread_mutex_lock(&tabdinner->philo[i].last_meal_flag);
			if (time - tabdinner->philo[i].last_meal >= \
				tabdinner->time_to_starv)
			{
				pthread_mutex_lock(&tabdinner->mstop);
				print_events(&tabdinner->philo[i], "died");
				tabdinner->stop = TRUE;
				pthread_mutex_unlock(&tabdinner->mstop);
				pthread_mutex_unlock(&tabdinner->philo[i].last_meal_flag);
				break ;
			}
			pthread_mutex_unlock(&tabdinner->philo[i].last_meal_flag);
		}
		if (!verify_death_contines(tabdinner))
			return ;
	}
}

int	philos_threads_born(t_dinnertable *tabdinner)
{
	int	i;

	i = 0;
	tabdinner->init = get_ms_time();
	while (i < tabdinner->nbr_philo)
	{
		pthread_mutex_lock(&tabdinner->philo[i].last_meal_flag);
		tabdinner->philo[i].last_meal = tabdinner->init;
		pthread_mutex_unlock(&tabdinner->philo[i].last_meal_flag);
		if (pthread_create(&tabdinner->philo[i].thread, NULL, \
		&routine, &tabdinner->philo[i]))
		{
			ft_putstr_fd("Pthread_create error\n", 2);
			pthread_mutex_lock(&tabdinner->mstop);
			tabdinner->stop = TRUE;
			pthread_mutex_unlock(&tabdinner->mstop);
			return (0);
		}
		i++;
	}
	verify_death(tabdinner);
	return (1);
}
