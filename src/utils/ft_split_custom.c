/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:02:48 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:31:39 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	cont_words_custom(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str && str[aux])
	{
		while (str[aux] == C)
			aux++;
		if (str[aux] && str[aux] != C)
			cant++;
		while (str[aux] && str[aux] != C)
			aux++;
	}
	if (cant > 2)
		return (2);
	return (cant);
}

int	cont_letter_custom(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str[aux] == C)
		aux++;
	while (str[aux] && str[aux] != C)
	{
		cant++;
		aux++;
	}
	return (cant);
}

char	**ft_split_custom(char *str, char C)
{
	char	**result;
	int		cant;
	int		aux;
	int		aux1;
	int		letter;

	cant = cont_words_custom(str, C);
	aux = 0;
	letter = 0;
	result = malloc((1 + cant) * sizeof(char *));
	letter = cont_letter_custom(str, C);
	while (cant != aux)
	{
		if (aux != 0)
		{
			str++;
			letter = ft_strlen(str);
		}
		result[aux] = malloc(letter * sizeof(char) + 1);
		aux1 = 0;
		while (letter != aux1)
			result[aux][aux1++] = *(str++);
		result[aux][aux1] = '\0';
		aux++;
	}
	result[aux] = NULL;
	return (result);
}
