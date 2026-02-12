/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:54:17 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:56:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"
#include <stddef.h>

#define BUFFER_SIZE 100

char	*flush_name(char *dst, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(dst, buff);
	if (!tmp)
		return (NULL);
	if (dst)
		free(dst);
	while (*buff)
		*buff++ = '\0';
	return (tmp);
}

char	*fetch_var_name(char *token, size_t *i)
{
	size_t	j;
	char	buff[BUFFER_SIZE];
	char	*expanded_token;
	int		flg;

	expanded_token = 0;
	flg = (ft_isalnum(token[*i]) || ft_strchr("_?", token[*i]));
	while (token[*i] && flg)
	{
		j = 0;
		while (j < BUFFER_SIZE - 1 && token[*i] && flg)
		{
			buff[j++] = token[(*i)++];
			flg = (ft_isalnum(token[*i]) || ft_strchr("_?", token[*i]));
			if (buff[j - 1] == '?')
				break ;
		}
		buff[j] = '\0';
		expanded_token = flush_name(expanded_token, buff);
		if (!expanded_token)
			return (NULL);
		if (*expanded_token == '?')
			break ;
	}
	return (expanded_token);
}

char	*save_prefix(char *token, size_t k)
{
	char	buff[BUFFER_SIZE];
	size_t	i;
	size_t	j;
	char	*result;

	result = ft_strdup("");
	i = -1;
	while (++i < k)
	{
		j = 0;
		while (j < BUFFER_SIZE - 1 && i < k)
			buff[j++] = token[i++];
		buff[j] = '\0';
		result = flush_name(result, buff);
		if (!result)
			return (NULL);
	}
	return (result);
}

char	*swap_expansion(char *prefix, char *token, size_t *i)
{
	char	*result;
	char	*tmp;

	result = fetch_var_name(token, i);
	if (result)
	{
		tmp = ft_getenv(result);
		free(result);
		if (!tmp)
			tmp = ft_strdup("");
		result = ft_strjoin(prefix, tmp);
		free(tmp);
	}
	else
		result = ft_strjoin(prefix, "$");
	free(prefix);
	return (result);
}
