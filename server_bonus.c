/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:23:01 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/16 14:29:38 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigrec(int sig)
{
	static unsigned char	rec;
	static int				index;

	if (sig == SIGUSR2)
		rec |= 0;
	else if (sig == SIGUSR1)
		rec |= 1;
	index++;
	if (index == 8)
	{
		if (rec == '\0')
			write(1, "\n", 1);
		else
			ft_putchar_fd(rec, 1);
		rec = 0;
		index = 0;
	}
	else
		rec <<= 1;
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sigrec);
	signal(SIGUSR2, sigrec);
	while (1)
		pause();
}
