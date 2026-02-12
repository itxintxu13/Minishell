/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:01:18 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:37:39 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"

char	**remove_redir_tokens(char **oldt, int *i)
{
	int		j;
	int		k;
	char	**tokens;

	tokens = malloc((len_all(oldt) - 1) * sizeof(char *));
	if (!tokens)
		error_handle(0, 0);
	j = -1;
	k = 0;
	while (oldt[++j])
	{
		if (j == *i)
			j++;
		else
			tokens[k++] = ft_strdup(oldt[j]);
	}
	tokens[k] = oldt[j];
	free_all(oldt);
	(*i)--;
	return (tokens);
}
