/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:16:57 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:40:30 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	i++;
	p = malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_replace(char *str, char init, char end)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == init)
			str[i] = end;
		i++;
	}
	return (str);
}

size_t	calc_longer_str(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
		return (l1);
	else
		return (l2);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (write(1, s++, 1) == -1)
			return ;
	}
}
