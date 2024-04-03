/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/04/03 17:19:59 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void len_of_bits(char **argv, int pid)
{
	int	i;
	int bit;

	bit = 0;
	i =	ft_strlen(argv[2]);
	ft_printf("len : %d\n", i);
	while (bit < 32)
	{
		if ((i & (0x01 << bit)) != 0) 
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(50);
	}
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
		bit++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	
	pid = 0;
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (1);
		len_of_bits(argv, pid);
		while(argv[2][i])
		{
			//send_bit(pid, argv[2][i]);
			i++;
		}
		// '/n'
	}
	else
	{
		ft_printf("les arguments sont pas bon");
		return (1);
	}
	return (0);
}

// compare le binaire
// 11110000
// 00010000
