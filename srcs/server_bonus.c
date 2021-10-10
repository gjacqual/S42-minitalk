/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 01:56:52 by gjacqual          #+#    #+#             */
/*   Updated: 2021/10/10 18:09:53 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	ft_signal_handler(int sig_nb, siginfo_t *sig_info, void *context)
{
	static int					count = 0;
	static unsigned char		symbol = 0x00;
	static pid_t				cli_pid = 0;

	(void)context;
	if (cli_pid == 0)
		cli_pid = sig_info->si_pid;
	if (sig_nb == SIGUSR1)
		symbol |= (1 << count);
	if (++count == 8)
	{
		count = 0;
		if (symbol == 0x00)
		{
			ft_putchar_fd('\n', 1);
			cli_pid = 0;
			return ;
		}
		ft_putchar_fd(symbol, 1);
		symbol = 0x00;
		kill(cli_pid, SIGUSR1);
	}
	else
		if (kill(cli_pid, SIGUSR2) != 0)
			ft_putstr_fd("Signal error!\n", 1);
}

void	ft_putpid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: <<", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(">>\n", 1);
}

int	main(void)
{
	struct sigaction	action;
	int					sig_check1;
	int					sig_check2;

	ft_putpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_signal_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sig_check1 = sigaction(SIGUSR1, &action, 0);
	if (sig_check1 != 0)
		ft_putstr_fd("Signal error!\n", 1);
	sig_check2 = sigaction(SIGUSR2, &action, 0);
	if (sig_check2 != 0)
		ft_putstr_fd("Signal error!\n", 1);
	ft_putstr_fd("The server has started successfully\n", 1);
	while (1)
		pause();
	return (0);
}
