/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:40:14 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:21:55 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"
#include <stdlib.h>

void	ft_echo_tokens(char **tokens)
{
	int		len;
	int		flag;
	int		aux;
	char	*text;

	len = len_all(tokens);
	text = NULL;
	flag = 0;
	aux = 0;
	while (++aux != len && equal("-n", tokens[aux]))
		flag = 1;
	aux--;
	while ((++aux) != len)
	{
		text = append(text, ft_strlen(tokens[aux]), tokens[aux]);
		if (aux + 1 != len && ft_strlen(tokens[aux]))
			text = append(text, ft_strlen(" "), " ");
	}
	ft_echo(text, flag);
	free(text);
	exit(EXIT_SUCCESS);
}

void	ft_cd_tokens(char **tokens, int has_pipe)
{
	int		len;
	char	*path;

	len = len_all(tokens);
	path = NULL;
	if (len > 2)
		error_handle_f(1, "cd: too many arguments\n");
	if (len == 1)
	{
		path = ft_getenv("HOME");
		if (!path)
			error_handle_f(1, "cd: HOME not set\n");
		if (!has_pipe)
			ft_cd(path);
		free(path);
	}
	else if (!has_pipe)
		ft_cd(tokens[1]);
	exit(EXIT_SUCCESS);
}

void	ft_pwd_tokens(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	exit(EXIT_SUCCESS);
}

void	ft_export_tokens(char **tokens, int has_pipe)
{
	int		len;
	int		aux;
	char	**str;

	aux = 0;
	len = len_all(tokens);
	if (len == 1)
		ft_export_void();
	while (++aux != len)
	{
		str = ft_split_custom(tokens[aux], '=');
		if (include(str[0], "?") || !valid_name_export(str[0]))
			error_handle_f(1, " not a valid identifier\n");
		if (has_pipe || !include(tokens[aux], "="))
			continue ;
		if (len_all(str) == 2)
			ft_export(str[0], str[1]);
		else
			ft_export(str[0], "");
	}
	exit(EXIT_SUCCESS);
}

void	ft_unset_tokens(char **tokens, int has_pipe)
{
	int	len;
	int	aux;

	aux = 0;
	len = len_all(tokens);
	if (len == 1)
		exit(EXIT_SUCCESS);
	while (++aux != len)
	{
		if (has_pipe)
			continue ;
		if (!include(tokens[aux], "?"))
			ft_unset(tokens[aux]);
	}
	exit(EXIT_SUCCESS);
}
