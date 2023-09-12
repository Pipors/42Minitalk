/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:53:22 by aatbir            #+#    #+#             */
/*   Updated: 2023/09/12 16:32:09 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int				id;
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	j = -1;
	if (ac != 3)
		return (ft_printf("Invalid usage of arguments"));
	id = ft_atoi(av[1]);
	while (av[2][++j])
	{
		i = 8;
		c = av[2][j];
		while (--i > -1)
		{
			if ((c >> i) & 1)
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			usleep(100);
		}
	}
	return (0);
}
