/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:50:45 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:19:23 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	cont_words(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str && str[aux])
	{
		while (str[aux] == C)
			aux++;
		if (str[aux] != C && str[aux])
			cant++;
		while (str[aux] != C && str[aux])
			aux++;
	}
	return (cant);
}

int	cont_letter(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str[aux] == C)
		aux++;
	while (str[aux] != C && str[aux])
	{
		cant++;
		aux++;
	}
	return (cant);
}

char	**ft_split(char *str, char C)
{
	char	**result;
	int		cant;
	int		aux;
	int		aux1;
	int		letter;

	cant = cont_words(str, C);
	aux = 0;
	letter = 0;
	result = malloc((1 + cant) * sizeof(char *));
	while (cant != aux)
	{
		letter = cont_letter(str, C);
		result[aux] = malloc(letter * sizeof(char) + 1);
		aux1 = 0;
		while (*str == C)
			str++;
		while (letter != aux1)
			result[aux][aux1++] = *(str++);
		result[aux][aux1] = '\0';
		aux++;
	}
	result[aux] = NULL;
	return (result);
}

void	free_all(char **matriz)
{
	int	aux;

	aux = 0;
	while (matriz && matriz[aux])
	{
		free(matriz[aux]);
		aux++;
	}
	if (matriz)
		free(matriz);
	matriz = NULL;
}

void	print_matriz_vec(char **matriz, char *vec)
{
	int	aux;

	if (vec)
		printf("\n%s\n", vec);
	aux = -1;
	while (matriz && matriz[(++aux)])
		printf("[mat:%d] -> %s\n", aux, matriz[aux]);
}
