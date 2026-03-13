/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:21:56 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:24:12 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	**z_maloc_matriz(int size)
{
	char	**vec;
	int		aux;

	vec = malloc(sizeof(char *) * (size + 1));
	if (!vec)
		return (NULL);
	aux = 0;
	while (aux != size)
	{
		vec[aux] = NULL;
		aux++;
	}
	vec[aux] = NULL;
	return (vec);
}

char	**append_matriz(char **matriz, char *new_line)
{
	int		aux;
	char	**result;

	if (!matriz)
		matriz = z_maloc_matriz(0);
	result = z_maloc_matriz(len_all(matriz) + 1);
	aux = 0;
	while (matriz && matriz[aux])
	{
		result[aux] = copy_vec(matriz[aux]);
		aux++;
	}
	result[aux] = copy_vec(new_line);
	result[aux + 1] = NULL;
	if (matriz)
		free_all(matriz);
	return (result);
}

char	**delete_vec_matriz(char **matriz, int index_delete)
{
	int		aux;
	int		aux1;
	char	**result;

	if (!matriz)
		matriz = z_maloc_matriz(1);
	result = z_maloc_matriz(len_all(matriz));
	aux1 = 0;
	aux = 0;
	while (matriz && matriz[aux1])
	{
		if (index_delete == aux1)
			aux1++;
		if (!matriz[aux1])
			break ;
		result[aux] = copy_vec(matriz[aux1]);
		aux++;
		aux1++;
	}
	result[aux] = NULL;
	free_all(matriz);
	return (result);
}

char	**read_file(int fd, char c)
{
	char	*text;
	int		bt_read;
	char	*buf;
	char	**text_split;

	buf = z_maloc(SIZE_BUF);
	text = append(NULL, 1, buf);
	bt_read = read(fd, buf, SIZE_BUF);
	while (bt_read > 0)
	{
		text = append(text, bt_read, buf);
		bt_read = read(fd, buf, SIZE_BUF);
	}
	close(fd);
	free (buf);
	text_split = ft_split(text, c);
	free(text);
	return (text_split);
}

int	count_caracter_matriz(char **mp, char c)
{
	int	ay;
	int	ax;
	int	result;

	ay = 0;
	ax = 0;
	result = 0;
	while (mp && mp[ay])
	{
		while (ax != len(mp[ay]))
		{
			if (mp[ay][ax] == c)
				result++;
			ax++;
		}
		ay++;
		ax = 0;
	}
	return (result);
}
