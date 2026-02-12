/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:47:29 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:32:29 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <asm-generic/errno-base.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"
#include "tokenizer.h"

void	parse_quotes(char *input)
{
	char	flg;
	size_t	i;

	if (!input)
		error_handle(EIO, 0);
	flg = 0;
	i = -1;
	while (input && input[++i])
		compute_flg_mask(input[i], &flg);
	if (flg)
	{
		free(input);
		error_handle(EIO, 0);
	}
}

char	**compute_saves(char **tokens, char flg, char **bgn, char *end)
{
	char	oprt[3];
	char	*tmp;

	if ((flg & FT_META) == 0)
		tokens = resize_tokens(tokens, save_word(bgn, end, tokens));
	else
	{
		while (*bgn != end)
		{
			if (save_operator(bgn, end, oprt))
			{
				tmp = ft_strdup(oprt);
				if (!tmp)
					free_all(tokens);
				tokens = resize_tokens(tokens, tmp);
			}
		}
	}
	return (tokens);
}

char	**tokenize(char *end)
{
	char	**tokens;
	char	*tmp;

	parse_quotes(end);
	end = clear_input(end);
	tmp = end;
	tokens = tokenize_core(end);
	if (!tokens)
	{
		free(tmp);
		error_handle(0, 0);
	}
	free(tmp);
	return (tokens);
}
