/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:46 by gjacqual          #+#    #+#             */
/*   Updated: 2021/10/09 23:28:37 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

int	ft_decoder_step(int pid, int count, int symbol)
{
	if ((symbol >> count) & 1)
	{
		if (kill(pid, SIGUSR1) != 0)
		{
			ft_putstr_fd("Signal error!\n", 1);
			return (0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) != 0)
		{
			ft_putstr_fd("Signal error!\n", 1);
			return (0);
		}
	}	
	return (1);
}

int	ft_bit_decoder(int symbol, int pid)
{	
	int	count;

	count = 0;
	while (count < 8)
	{
		if (ft_decoder_step(pid, count, symbol) == 0)
			return (0);
		count++;
		usleep(200);
	}
	return (1);
}

int	bit_sender(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		if (ft_bit_decoder(message[i], pid) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_server_signal_handler(int sig_nb, siginfo_t *sig_info, void *context)
{
	(void)sig_info;
	(void)context;
	if (sig_nb == SIGUSR1)
	{
		ft_putstr_fd("1 Byte received!\n", 1);
	}
	if (sig_nb == SIGUSR2)
	{	
		ft_putstr_fd("Signal status: in progress!\n", 1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	serv_act;
	siginfo_t			siginfo;
	int					pid;

	if (argc != 3)
		ft_putstr_fd("Please enter the PID and a message after ./client\n", 1);
	else
	{
		pid = ft_atoi(argv[1]);
		serv_act.sa_flags = SA_SIGINFO;
		serv_act.sa_sigaction = &ft_server_signal_handler;
		sigemptyset(&serv_act.sa_mask);
		sigaddset(&serv_act.sa_mask, SIGUSR1);
		sigaddset(&serv_act.sa_mask, SIGUSR2);
		sigaction(SIGUSR1, &serv_act, 0);
		sigaction(SIGUSR2, &serv_act, 0);
		siginfo.si_pid = pid;
		if (bit_sender(argv[2], pid))
		{
			ft_putstr_fd("Message has been sent successfully\n", 1);
			exit(0);
		}
		else
		{
			ft_putstr_fd("Error: Message has not been sent\n", 1);
			exit(0);
		}
	}
	while (1)
		pause();
	return (0);
}
