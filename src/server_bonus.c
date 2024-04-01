/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:35 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/25 16:45:50 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_checkeur(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		// kill()
	}
}
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("pas d'argument autoriser");
		return (0);
	}
	pid = getpid();
	// peut etre un msg
	while (argc == 1)
	{
		signal(SIGUSR1, ft_checkeur);
		signal(SIGUSR2, ft_checkeur);
		//pause ();
	}
	return (0);
}