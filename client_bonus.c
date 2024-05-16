/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:22:55 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/16 14:29:47 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_error(void)
{
	ft_putstr_fd("Invalid arguments , please enter the pid then the message\n",
		1);
	exit(1);
}

void	send(int pid, char c)
{
	int				i;
	unsigned char	tmp;
	int				error;

	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error == -1)
		{
			ft_putstr_fd("Error while sending signal\n", 1);
			exit(1);
		}
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	if (ac != 3)
		print_error();
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
	{
		ft_putstr_fd("Invalid PID", 1);
		exit(1);
	}
	message = av[2];
	while (message[i] != '\0')
	{
		send(pid, message[i]);
		i++;
	}
	send(pid, '\0');
}
