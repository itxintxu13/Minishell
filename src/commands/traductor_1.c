/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:26:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:23:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

void	ft_process_export(char **tokens, int aux, int has_pipe)
{
	char	**str;

	str = ft_split_custom(tokens[aux], '=');
	if (include(str[0], "?") || !valid_name_export(str[0]))
	{
		free_all(str);
		error_handle_f(1, " not a valid identifier\n");
	}
	if (has_pipe || !include(tokens[aux], "="))
	{
		free_all(str);
		return ;
	}
	if (len_all(str) == 2)
		ft_export(str[0], str[1]);
	else
		ft_export(str[0], "");
	free_all(str);
}

void	ft_env_tokens(void)
{
	ft_env();
	error_handle_f(0, 0);
}

int	verify(char *str)
{
	if (str && (*str == '-' || *str == '+'))
		str++;
	while (str && *str)
	{
		if (*str < '0' || *str > '9')
			return (2);
		str++;
	}
	return (0);
}

void	ft_exit_tokens(char **tokens, int has_pipe)
{
	int	len;

	len = len_all(tokens);
	if (len == 1)
	{
		if (has_pipe)
			exit(0);
		ft_exit(0);
	}
	if (verify(tokens[1]) != 0)
	{
		if (write(2, "exit: numeric argument required\n", 33) == -1)
			return ;
		if (has_pipe)
			exit(2);
		ft_exit(2);
		return ;
	}
	if (len > 2)
		error_handle_f(1, "exit: too many arguments\n");
	if (has_pipe)
		exit(ft_atoi(tokens[1]) % 256);
	ft_exit(ft_atoi(tokens[1]));
}
