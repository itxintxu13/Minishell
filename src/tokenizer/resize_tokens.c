/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:49:56 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/29 15:00:09 by itlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer.h"
#include "../../include/utils.h"

char	**resize_tokens(char **list, char *new_token)
{
	char	**tmp;
	size_t	size;
	size_t	i;

	if (!new_token)
		return (NULL);
	size = 0;
	while (list && list[size])
		size++;
	tmp = malloc((size + 2) * sizeof(char *));
	if (!tmp)
	{
		free_all(list);
		free(new_token);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		tmp[i] = list[i];
	free(list);
	tmp[i++] = new_token;
	tmp[i] = 0;
	return (tmp);
}
