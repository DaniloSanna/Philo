#include "philo.h"

void	so_wait(time_t microsec, t_dinnertable *tabdinner)
{
	time_t	init;

	init = get_ms_time();
	while (get_ms_time() - init < microsec)
	{
		pthread_mutex_lock(&tabdinner->msg);
		if (tabdinner->stop == TRUE)
		{
			pthread_mutex_unlock(&tabdinner->msg);
			break ;
		}
		pthread_mutex_unlock(&tabdinner->msg);
		if (tabdinner->nbr_philo < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
