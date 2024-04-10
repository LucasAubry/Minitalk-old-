/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:50 by Laubry            #+#    #+#             */
/*   Updated: 2024/04/10 09:36:59 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	stock_and_print(char *tab, int *i, int *bit, int *intab)
{
	static int	x = 0;

	if (*bit == 7 && intab[1] == 1)
	{
		tab[x++] = *i;
		*i = 0;
		*bit = -1;
	}
	if (x == intab[2])
	{
		tab[++x] = '\0';
		ft_putendl_fd(tab, 1);
		*i = 0;
		*bit = -1;
		x = 0;
		return (1);
	}
	return (0);
}

void	ft_checkeur(int signal)
{
	static int	intab[3] = {0, 0, -1};
	static int	bit = 0;
	static int	i = 0;
	static char	*tab;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	if (bit == 31 && intab[1] == 0)
	{
		bit = 0;
		intab[1] = 1;
		if (i < 0)
			return ;
		tab = malloc(sizeof(int) * (i + 1));
		intab[2] = i;
		i = 0;
		return ;
	}
	if (stock_and_print(tab, &i, &bit, intab) == 1)
	{
		intab[1] = 0;
		intab[2] = -1;
		free(tab);
	}
	bit++;
}

void	recup(int signal, siginfo_t *info, void *nothing)
{
	ft_checkeur(signal);
	kill(info->si_pid, SIGUSR1);
	(void) nothing;
}

int	main(int argc, char **argv)
{
	static const struct sigaction	act = (struct sigaction)
	{.sa_sigaction = recup, .sa_flags = SA_SIGINFO};
	(void)argv;

	if (argc != 1)
	{
		ft_printf("pas d'arguments autorises");
		return (0);
	}
	ft_printf("pid : %d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause ();
	}
	return (0);
}
