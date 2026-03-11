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
		if (aux + 1 != len)
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
	{
		if (equal(tokens[1], "-"))
		{
			path = ft_getenv("OLDPWD");
			if (!path)
				error_handle_f(1, "cd: OLDPWD not set\n");
			ft_cd(path);
			free(path);
		}
		else
			ft_cd(tokens[1]);
	}
	exit(EXIT_SUCCESS);
}

void	ft_pwd_tokens(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		error_handle_f(1, "pwd: error retrieving current directory\n");
		return ;
	}
	printf("%s\n", pwd);
	free(pwd);
	exit(EXIT_SUCCESS);
}

void	ft_export_tokens(char **tokens, int has_pipe)
{
	int	len;
	int	aux;

	aux = 0;
	len = len_all(tokens);
	if (len == 1)
		ft_export_void();
	while (++aux != len)
		ft_process_export(tokens, aux, has_pipe);
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
