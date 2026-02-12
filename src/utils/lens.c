/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:23:13 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:25:23 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	len(char *str)
{
	int	aux;

	aux = 0;
	while (str && str[aux])
		aux++;
	return (aux);
}

int	len_all(char **str)
{
	int	aux;

	aux = 0;
	while (str && str[aux])
		aux++;
	return (aux);
}

int	equal(char *str, char *str1)
{
	int	aux;

	if (!str || !str1)
		return (str == str1);
	aux = 0;
	while (str[aux] && str1[aux])
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (str[aux] == str1[aux]);
}

int	equaln(char *str, char *str1, int size)
{
	int	aux;

	if (!str || !str1)
		return (str == str1);
	aux = 0;
	while ((str[aux] || str1[aux]) && aux < size)
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (1);
}
