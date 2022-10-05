
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
		philo[i].state = 0;
		philo[i].std_sleep = 0;
		philo[i].fork.left = i;
		philo[i].fork.right = (i + 1) % env->args.nbr;
	}
	return (philo);
}

int	lock_left(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->env->forks[philo->fork.left]) != 0)
		return (0);
	pthread_mutex_lock(&philo->env->print);
	printf("%s%ld %d has taken a left fork\e[0m\n", "\e[0;36m", \
		gettime() - philo->env->start, philo->id);
	pthread_mutex_unlock(&philo->env->print);
	return (1);
}

int	lock_right(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->env->forks[philo->fork.right]) != 0)
		return (0);
	pthread_mutex_lock(&philo->env->print);
	printf("%s%ld %d has taken a right fork\e[0m\n", "\e[0;36m", \
		gettime() - philo->env->start, philo->id);
	pthread_mutex_unlock(&philo->env->print);
	return (1);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print);
	printf("%s%ld %d is thinking\e[0m\n", "\e[1;33m", \
			gettime() - philo->env->start, philo->id);
	pthread_mutex_unlock(&philo->env->print);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->time);
	philo->std_eat = gettime();
	pthread_mutex_unlock(&philo->env->time);
	pthread_mutex_lock(&philo->env->print);
	printf("%s%ld %d is eating\e[0m\n", "\e[1;32m", \
			philo->std_eat - philo->env->start, philo->id);
	pthread_mutex_unlock(&philo->env->print);
	usleep(philo->env->args.tt_eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->env->forks[philo->fork.right]);
	pthread_mutex_unlock(&philo->env->forks[philo->fork.left]);
	pthread_mutex_lock(&philo->env->print);
	printf("%s%ld %d is sleeping\e[0m\n", "\e[1;35m", \
			gettime() - philo->env->start, philo->id);
	pthread_mutex_unlock(&philo->env->print);
	usleep(philo->env->args.tt_sleep);
	ft_thinking(philo);
}

int	exec_task(t_philo *philo)
{
	int	right;
	int	left;

	right = 0;
	left = 0;
	if (philo->env->args.nbr < 2)
		return (0);
	left = lock_left(philo);
	right = lock_right(philo);
	if (right && left)
		ft_eating(philo);
	else if (!right && left)
		pthread_mutex_unlock(&philo->env->forks[philo->fork.left]);
	else if (right && !left)
		pthread_mutex_unlock(&philo->env->forks[philo->fork.right]);
}

void	*checker(void *content)
{
	t_philo	*philo;
	t_env	*env;
	int		i;

	i = -1;
	philo = (t_philo *)content;
	env = philo[0].env;
	// if (env->args.nbr_meal > 0)
	// 	while (ph)
	// else
	// 	while (philo[i].state != died)
}

void	*routine(void *content)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)content;
	if (philo->id % 2 == 0)
		usleep(philo->env->args.tt_eat / 2);
	if (philo->env->args.nbr_meal > 0)
		while (philo->state != died && philo->eat_cnt != philo->env->args.nbr_meal)
			exec_task(philo);
	else
		while (philo->state != died)
			exec_task(philo);
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