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

void	case_split(char ***parse, char **tokens, int aux)
{
	if (equal(tokens[aux], ">"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "<"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "<<"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], ">>"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "|"))
		(*parse) = append_matriz((*parse), "\n");
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

void	shear_error(char **tokens, int aux)
{
	int		max;
	char	*errors[6];
	int		err;
	int		tem;

	initialize_array(errors);
	max = len_all(tokens);
	(void)max;
	err = 0;
	if (equal(tokens[0], errors[0]))
		error_handle_f(2, "syntax error near unexpected token\n");
	while (errors[err] && tokens[aux])
	{
		tem = -1;
		while (equal(tokens[aux], errors[err]) && errors[++tem])
		{
			if (equal(tokens[aux], "|") && tem == 1)
				break ;
			if (equal(tokens[aux + 1], errors[tem]))
				error_handle_f(2, "syntax error near unexpected token\n");
		}
		if (equal(tokens[aux], errors[err]) && !tokens[aux + 1])
			error_handle_f(2, "syntax error near unexpected token\n");
		err++;
	}
}

char	**parse(char **tokens)
{
	int		aux;

	aux = -1;
	if (!tokens)
		return (tokens);
	while (tokens && len_all(tokens) != ++aux)
		shear_error(tokens, aux);
	return (tokens);
}
