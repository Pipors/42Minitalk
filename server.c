/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:09:31 by aatbir            #+#    #+#             */
/*   Updated: 2023/09/12 15:55:33 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				pid;
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		i = 0;
		c = 0;
	}
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR1)
			c = (c << 1) + 1;
		else 
			c = (c << 1);
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	args;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Invalid usage");
		return (0);
	}
	args.sa_flags = SA_SIGINFO;
	args.sa_sigaction = signal_handler;
	pid = getpid();
	ft_printf("The pid is : %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &args, NULL);
		sigaction(SIGUSR2, &args, NULL);
		pause();
	}
}
