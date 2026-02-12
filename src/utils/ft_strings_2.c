/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:49:51 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:58:40 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/utils.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;

	i = 0;
	while (src[i] && (i + 1) < dsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dsize != 0)
		dst[i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	while (c != *s && *s)
		s++;
	if (c == 0 || c == *s)
		return ((char *)s);
	else
		return (0);
}

static char	*trim_bgn(const char *s1, const char *set)
{
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	return ((char *)s1);
}

size_t	find_end(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (!ft_strchr(set, s1[i - 1]))
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*p;
	size_t	i;

	s1 = trim_bgn(s1, set);
	i = find_end(s1, set) + 1;
	p = malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, i);
	return (p);
}
