/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djustino <djustino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:39 by djustino          #+#    #+#             */
/*   Updated: 2024/05/12 21:06:43 by djustino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

# define STOP		1
# define CONTINUE	0
# define FALSE		0
# define TRUE		1
# define INT_MAX	2147483647
# define EATING		"is eating"
# define THINKING	"is thinking"
# define SLEEPING	"is sleeping"
# define TAKEN_FORK	"has taken a fork"

typedef struct s_dinnertable	t_dinnertable;

typedef struct s_philosopher
{
	int				id;
	int				nbr_meals;
	int				stop;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_meal_flag;
	time_t			last_meal;
	t_dinnertable	*tabdinner;
}	t_philo;

typedef struct s_dinnertable
{
	time_t			init;
	int				nbr_philo;
	time_t			time_to_starv;
	time_t			time_eating;
	time_t			time_sleeping;
	int				nbr_meals;
	int				stop;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	pthread_mutex_t	mstop;
	t_philo			*philo;
}	t_dinnertable;

// check_args.c
int		check_args(int argc, char **argv);

// inits.c
void	init_philo(t_dinnertable	*tabdinner);
int		set_table_for_dinner(t_dinnertable *tabdinner, char **argv);
int		init_mutex(t_dinnertable *tabdinner);
void	free_struct(t_dinnertable *tabdinner);
int		init_mutex(t_dinnertable *tabdinner);
int		init_mutex_lastmeal(t_dinnertable *tabdinner);

// itscircleoflife.c
int		life_circle(t_philo *philo, char *event);
void	*routine(void *arg);
int		check_limit_meals(t_dinnertable *tabdinner);
void	verify_death(t_dinnertable *tabdinner);
int		philos_threads_born(t_dinnertable *tabdinner);
void	take_fork_pair_or_even(t_philo	*philo);
int		verify_death_contines(t_dinnertable *tabdinner);

// main.c
time_t	get_ms_time(void);
void	print_events(t_philo *philo, char *event);

//	so_wait.c
void	so_wait(time_t microsec, t_dinnertable *tabdinner);

// utils.c
void	ft_putstr_fd(char *s, int fd);
int		ft_str_isdigit(char *str);
int		chek_str_int_positive(const char *nptr);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

// utils2.c
int		ft_strcmp(char *s1, char *s2);

#endif
