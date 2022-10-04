
#include "./philo.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
	{
		return (1);
	}
	else if (c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = ((result * 10) + (nptr[i] - '0'));
		i++;
	}
	return (sign * result);
}

long	gettime(void)
{
	struct timeval	timeval;
	long			time;

	gettimeofday(&timeval, NULL);
	time = (long)timeval.tv_sec * 1000 + (long)(timeval.tv_usec / 1000);
	return (time);
}

int	err_handler(int err_code)
{
	if (err_code == 0)
	{
		printf("Argument count less than run threshold requirement OR arguments contain alphabet(s)\n");
		return (0);
	}
	else if (err_code == 1)
	{
		printf("Argument initialization error\n");
		return (0);
	}
	else if (err_code == 2)
	{
		printf("mutex initialization error\n");
		return (0);
	}
	else if (err_code == 3)
		printf("memory allocation error\n");
	// else if (err_code == 4)
	// {
	// 	printf("mutex initialization error\n");
	// 	return (0);
	// }
	return (0);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_args(t_env *env, char **argv)
{
	if (!check_args(argv))
		return (err_handler(0));
	env->args.nbr = ft_atoi(argv[1]);
	env->args.tt_die = ft_atoi(argv[2]) * 1000;
	env->args.tt_eat = ft_atoi(argv[3]) * 1000;
	env->args.tt_sleep = ft_atoi(argv[4]) * 1000;
	env->dead = 0;
	env->start = gettime();
	if (argv[5])
		env->args.nbr_meal = ft_atoi(argv[5]);
	else
		env->args.nbr_meal = -1;
	return (1);
}

int	init_mutex(t_env *env)
{
	int	i;

	i = -1;
	env->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->args.nbr);
	if (!env->forks)
	{
		err_handler(3);
		return (0);
	}
	while (++i < env->args.nbr)
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
			return (0);
	if (pthread_mutex_init(&env->print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&env->death, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&env->time, NULL) != 0)
		return (0);
	return (1);
}

t_philo	*init_philo(t_env *env)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * env->args.nbr);
	if (!philo)
	{
		err_handler (3);
		return (NULL);
	}
	while (++i < env->args.nbr)
	{
		philo[i].env = env;
		philo[i].id = i + 1;
		philo[i].eat_cnt = 0;
		philo[i].std_eat = 0;
		philo[i].std_sleep = 0;
		philo[i].fork.left = i;
		philo[i].fork.right = (i + 1) % env->args.nbr;
	}
	return (philo);
}

void	*checker(void *content)
{
	t_philo	*philo;
	t_env	*env;
	int		i;

	i = -1;
	philo = (t_philo *)content;
	env = philo[0].env;
}

void	*routine(void *content)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)content;
	
}

void	run_philo(t_env *env, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < env->args.nbr)
		if (pthread_create(&philo[i].th, NULL, &routine, &philo[i]) != 0)
			printf("thread creation error!\n");
	if (pthread_create(&env->track, NULL, &checker, philo) != 0)
		printf("thread creation error!\n");
	i = -1;
	while (++i < env->args.nbr)
		if (pthread_join(philo[i].th, NULL) != 0)
			printf("thread join error!\n");
	if (pthread_join(env->track, NULL) != 0)
		printf("thread join error!\n");
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (!init_args(&env, argv))
			return (err_handler(1));
		if (!init_mutex(&env))
			return (err_handler(2));
		philo = init_philo(&env);
		if (!philo)
			return (0);
		run_philo(&env, philo);
	}
	else
		return (err_handler(0));
}