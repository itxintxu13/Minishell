/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:08:29 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:37:09 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	ft_syntax_error(void)
{
	if (write(2, "minishell: syntax error near unexpected token\n",
			46) == -1)
		return (2);
	return (2);
}

void	initialize_array(char	*arr[6])
{
	arr[0] = "|";
	arr[1] = ">>";
	arr[2] = "<<";
	arr[3] = "<";
	arr[4] = ">";
	arr[5] = NULL;
}

int	shear_error(char **tokens, int aux)
{
	int		err;
	char	*errors[6];
	int		tem;

	initialize_array(errors);
	err = 0;
	if (equal(tokens[0], errors[0]))
		return (ft_syntax_error());
	while (errors[err] && tokens[aux])
	{
		tem = -1;
		while (equal(tokens[aux], errors[err]) && errors[++tem])
		{
			if (equal(tokens[aux], "|") && tem == 1)
				break ;
			if (equal(tokens[aux + 1], errors[tem]))
				return (ft_syntax_error());
		}
		if (equal(tokens[aux], errors[err]) && !tokens[aux + 1])
			return (ft_syntax_error());
		err++;
	}
	return (0);
}

char	**parse(char **tokens)
{
	int		aux;

	aux = -1;
	if (!tokens)
		return (tokens);
	while (tokens && len_all(tokens) != ++aux)
	{
		if (shear_error(tokens, aux))
		{
			free_all(tokens);
			return (NULL);
		}
	}
	return (tokens);
}
