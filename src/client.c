/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/25 13:52:38 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

// compare le binaire
// 11110000
// 00010000