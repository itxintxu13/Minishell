/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:34:37 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:21:19 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../include/utils.h"
#include "./tokenizer.h"

int	count_word_size(char *tmp, char *end)
{
	size_t	i;
	char	flg;

	i = 0;
	flg = 0;
	while (tmp != end)
	{
		compute_flg_mask(*tmp, &flg);
		if ((flg & 3) != 0 || !ft_strchr(" \t\n|<>", *tmp))
			i++;
		tmp++;
	}
	return (i);
}

char	*save_word(char **bgn, char *end, char **tokens)
{
	char	*token;
	size_t	i;
	char	flg;

	i = count_word_size(*bgn, end);
	token = malloc((i + 1) * sizeof(char));
	if (!token)
	{
		free_all(tokens);
		return (NULL);
	}
	i = 0;
	flg = 0;
	while (*bgn != end)
	{
		compute_flg_mask(**bgn, &flg);
		if ((flg & 3) != 0 || !ft_strchr(" \t\n|<>", **bgn))
			token[i++] = **bgn;
		(*bgn)++;
	}
	token[i] = '\0';
	return (token);
}

void	parse_redirect(char **bgn, char *oprt, int *i, char c)
{
	oprt[(*i)++] = c;
	if (*(*bgn + 1) == c)
	{
		oprt[(*i)++] = c;
		(*bgn)++;
	}
}

void	compute_operators(char **bgn, char *oprt, int *i)
{
	if (**bgn == '|')
		oprt[(*i)++] = '|';
	else if (**bgn == '\n')
		oprt[(*i)++] = '\n';
	else if (**bgn == '<')
		parse_redirect(bgn, oprt, i, '<');
	else if (**bgn == '>')
		parse_redirect(bgn, oprt, i, '>');
	(*bgn)++;
}

int	save_operator(char **bgn, char *end, char *oprt)
{
	int		i;

	i = 0;
	while (*bgn != end)
	{
		if (ft_strchr("|<>\n", **bgn))
		{
			compute_operators(bgn, oprt, &i);
			break ;
		}
		(*bgn)++;
	}
	oprt[i] = '\0';
	return (i);
}
