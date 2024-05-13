/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:34 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:50:28 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	so_wait(time_t microsec, t_dinnertable *tabdinner)
{
	time_t	init;

	init = get_ms_time();
	while (get_ms_time() - init < microsec)
	{
		pthread_mutex_lock(&tabdinner->mstop);
		if (tabdinner->stop == TRUE)
		{
			pthread_mutex_unlock(&tabdinner->mstop);
			break ;
		}
		pthread_mutex_unlock(&tabdinner->mstop);
		if (tabdinner->nbr_philo < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
