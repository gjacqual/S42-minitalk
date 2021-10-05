/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:16:46 by gjacqual          #+#    #+#             */
/*   Updated: 2021/05/13 20:18:43 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	strsize;

	strsize = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * strsize);
	if (str)
	{
		str = ft_memcpy(str, s1, strsize);
		return (str);
	}
	return (NULL);
}
