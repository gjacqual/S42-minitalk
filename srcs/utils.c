/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:37:37 by gjacqual          #+#    #+#             */
/*   Updated: 2021/10/14 16:05:27 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;
	int	i;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == ' ' )
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{	
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			n = -n;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + 48;
		ft_putchar_fd(c, fd);
	}
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
