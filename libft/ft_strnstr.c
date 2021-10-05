/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:46 by gjacqual          #+#    #+#             */
/*   Updated: 2021/05/15 16:35:51 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	c;
	char	hayc;
	size_t	nlen;

	hayc = *haystack;
	c = *needle;
	nlen = ft_strlen(needle);
	if (nlen > len)
		return (NULL);
	if (c == '\0')
		return ((char *)haystack);
	while (hayc != '\0' && len-- >= nlen)
	{
		if ((ft_strncmp(haystack, needle, nlen) == 0) && (*haystack == c))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
