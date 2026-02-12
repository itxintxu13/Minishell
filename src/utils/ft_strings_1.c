/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:31:48 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:18:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/utils.h"

static unsigned int	count_size(unsigned int i, unsigned int j, const char *src)
{
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dsize)
		i++;
	if (i == dsize)
		return (count_size(i, j, src));
	while (src[j] && (i + 1) < dsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (count_size(i, j, src));
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i + 1 < n && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	c;
	size_t	i;
	size_t	j;
	char	*p;

	c = ft_strlen(s1);
	c = c + ft_strlen(s2);
	p = malloc((c + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	j = -1;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j])
		p[i++] = s2[j];
	p[i] = '\0';
	return (p);
}
