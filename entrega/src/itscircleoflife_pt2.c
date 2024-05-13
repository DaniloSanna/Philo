/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itscircleoflife_pt2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:10 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:06:25 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verify_death_contines(t_dinnertable *tabdinner)
{
	usleep(100);
	pthread_mutex_lock(&tabdinner->mstop);
	if (tabdinner->stop == TRUE)
	{
		pthread_mutex_unlock(&tabdinner->mstop);
		return (0);
	}
	pthread_mutex_unlock(&tabdinner->mstop);
	return (1);
}

void	take_fork_pair_or_even(t_philo	*philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		philo->stop = life_circle(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->l_fork);
		philo->stop = life_circle(philo, TAKEN_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		philo->stop = life_circle(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->r_fork);
		philo->stop = life_circle(philo, TAKEN_FORK);
	}
}
