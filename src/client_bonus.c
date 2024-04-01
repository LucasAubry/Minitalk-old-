/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:18 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/25 16:21:39 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_sur(int pid, char x)
{
	if (signal == SIGUSR1)
		ft_printf("signal 1 recu");
	else
		ft_printf("signal 2 recu");
}

void	send_bit(int pid, char x)
{
	int bit;

	bit = 0;
	while(bit < 8)
	{
		if ((x & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		// usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (1);
		while(argv[2][i])
		{
			send_bit(pid, argv[2][i]);
			i++;
		}
		// '/n'
	}
	else
	{
		ft_printf("il y a trop d'arguments");
		return (1);
	}
	return (0);
}