/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:49:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:40:38 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	//size_t

void	reverse_copy_mem(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n - i > 0)
	{
		d[n - i - 1] = s[n - i - 1];
		i++;
	}
}

void	copy_mem(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
	{
		*d = *s;
		s++;
		d++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = dest;
	s = src;
	if (dest < src)
	{
		copy_mem(d, s, n);
		return (dest);
	}
	else if (src < dest)
	{
		reverse_copy_mem(d, s, n);
		return (dest);
	}
	else
		return (dest);
}
/*
#include <string.h>
#include <stdio.h>
#include "libft.h"
int	main(void)
{
	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest1;
	char	src2[] = "lorem ipsum dolor sit amet";
	char	*dest2;	
	char	*r;
	char	*fr;

	dest1 = src1 + 1;
	dest2 = src2 + 1;
	r = memmove(dest1, "consectetur", 5);
	fr = ft_memmove(dest2, "consectetur", 5);

	printf("r:\t%s\nfr:\t%s\n", r, fr);
	return (0);
}*/
