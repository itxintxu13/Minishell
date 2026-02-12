/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:19:47 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:58:47 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "../../include/utils.h"
#include <stddef.h>
#include <errno.h>

void	shrink_wspace(char *input, char *buff, int *i, size_t *j)
{
	if (*input == '\n' && *i < 99)
	{
		buff[(*i++)] = input[(*j)++];
		while (ft_strchr(" \t\n", input[*j]))
			(*j)++;
	}
	else if (*i < 99)
	{
		buff[(*i++)] = ' ';
		(*j)++;
		while (ft_strchr(" \t", input[*j]))
			(*j)++;
	}
}

char	*flush_buff(char *buff, char *dst, char *input)
{
	char	*tmp;

	tmp = ft_strjoin(dst, buff);
	if (!tmp)
	{
		free(input);
		error_handle(0, 0);
	}
	if (dst)
		free(dst);
	while (*buff)
		*buff++ = '\0';
	return (tmp);
}

char	*merge_wspaces(char *input)
{
	return (merge_wspaces_core(input));
}

char	*clear_input(char *input)
{
	char	*tmp;

	tmp = input;
	input = ft_strtrim(tmp, " \n\t");
	if (!input)
	{
		free(tmp);
		error_handle(errno, NULL);
	}
	free(tmp);
	tmp = input;
	input = merge_wspaces(tmp);
	free(tmp);
	return (input);
}
