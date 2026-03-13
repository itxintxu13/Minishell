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

static void	validate_export_name(char **str, char *token)
{
	int	nlen;

	nlen = 0;
	if (str[0])
		nlen = ft_strlen(str[0]);
	if (nlen > 0 && str[0][nlen - 1] == '=')
		str[0][nlen - 1] = '\0';
	if (!str[0] || !valid_name_export(str[0]))
	{
		free_all(str);
		if (write(2, "minishell: export: `", 20) == -1
			|| write(2, token, ft_strlen(token)) == -1
			|| write(2, "': not a valid identifier\n", 26) == -1)
			exit(1);
		exit(1);
	}
}

void	ft_process_export(char **tokens, int aux, int has_pipe)
{
	char	**str;
	char	*existing;

	str = ft_split_custom(tokens[aux], '=');
	validate_export_name(str, tokens[aux]);
	if (has_pipe)
	{
		free_all(str);
		return ;
	}
	if (!include(tokens[aux], "="))
	{
		existing = ft_getenv(str[0]);
		if (!existing)
			ft_export(str[0], "");
		else
			free(existing);
		free_all(str);
		return ;
	}
	if (len_all(str) == 2)
		ft_export(str[0], str[1]);
	else
		ft_export(str[0], "");
	free_all(str);
}

int	verify(char *str)
{
	if (!str || !*str)
		return (2);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (2);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (2);
		str++;
	}
	return (0);
}

static int	exit_errors(char **tokens, int len)
{
	if (verify(tokens[1]) != 0)
	{
		if (write(2, "minishell: exit: ", 17) == -1
			|| write(2, tokens[1], ft_strlen(tokens[1])) == -1
			|| write(2, ": numeric argument required\n", 28) == -1)
			return (1);
		exit(2);
	}
	if (len > 2)
	{
		if (write(2, "minishell: exit: too many arguments\n", 36) == -1)
			return (1);
		error_handle_f(1, "");
	}
	return (0);
}

void	ft_exit_tokens(char **tokens, int has_pipe)
{
	int	len;

	len = len_all(tokens);
	if (len == 1)
	{
		if (write(2, "exit\n", 5) == -1)
			return ;
		if (has_pipe)
			exit(0);
		ft_exit(0);
	}
	if (exit_errors(tokens, len))
		return ;
	if (write(2, "exit\n", 5) == -1)
		return ;
	if (has_pipe)
		exit(ft_atoi(tokens[1]) % 256);
	ft_exit(ft_atoi(tokens[1]));
}
