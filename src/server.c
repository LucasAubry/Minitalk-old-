/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:50 by Laubry            #+#    #+#             */
/*   Updated: 2024/04/01 14:07:45 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_8_and_print(int bit, int i, int len, int boul)
{
	static char *tab;
	static int x = 0;

	if (bit == 8 && boul == 1)
	{	
		tab = malloc(sizeof(char) * len + 1);
		tab[x++] = i;	
		bit = 0;
		i = 0;
	}
	if (x == len)
	{
		x = 0;
		while (tab[x])
		{
			ft_printf("%d", tab[x]);
			x++;
		}
	}
}

void	ft_checkeur(int signal)
{
	static int	bit = 0;
	static int	i  = 0 ;
	static int boul = 0;
	static int	len = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 31)
	{
		bit = 0;
		boul = 1;
		len = i;
	}
	bit_8_and_print(bit, i, len, boul);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("pas d'arguments autorises");
		return (0);
	}
	pid = getpid();
	ft_printf("%d, pid :", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_checkeur);
		signal(SIGUSR2, ft_checkeur);
		//pause ();
	}
	return (0);
}

/*

0110100 |= 01111111
0110100 &= 01111111

0111



if (1 | 0)
if (0)




*/
