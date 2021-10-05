/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:58:14 by gjacqual          #+#    #+#             */
/*   Updated: 2021/05/11 22:29:42 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*resptr;
	size_t	fullsize;

	fullsize = (size * count);
	resptr = malloc(fullsize);
	if (!resptr)
		return (NULL);
	ft_bzero(resptr, fullsize);
	return (resptr);
}
