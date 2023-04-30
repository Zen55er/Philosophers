/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:57:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/04/30 11:32:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_data;
typedef struct s_philo
{
	pthread_t			id;
	int					meals;
	int					spot;
	int					dead;
	unsigned long		last_meal;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	t_philo			**philo;
	pthread_mutex_t	**forks;
	int				n;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				opt_eat;
	unsigned long	start_time;
}				t_data;

/*main.c*/
int				write_usage(void);
int				usage(int ac, char **av, t_data *data);
int				prep_data(t_data *data);
int				start(t_data *data);

/*utils.c*/
int				ft_atoi(char *str);
int				free_data(t_data *data);
unsigned long	get_time(void);

/*simulation.c*/
void			message(unsigned long start_time, int n, int flag);
void			think(t_philo *philo);
void			eat(t_philo *philo, pthread_mutex_t *fork1,
					pthread_mutex_t *fork2);
void			shleep(t_philo *philo);
void			*simulation(void *philo);

#endif