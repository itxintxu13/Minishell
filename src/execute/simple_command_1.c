/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:45:56 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:09:05 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "simple_command.h"

void	build_cmd_path(char *cmd, char dir[PATH_MAX], char **paths)
{
	int	i;

	i = -1;
	while (**paths && **paths != ':')
	{
		if (++i >= PATH_MAX - 2 - (int) ft_strlen(cmd))
			error_handle_f(0, "path too long\n");
		dir[i] = *(*paths)++;
	}
	dir[++i] = '/';
	dir[++i] = '\0';
	ft_strlcat(dir, cmd, PATH_MAX);
}

void	check_path_var(char *cmd, char dir[PATH_MAX])
{
	char	*paths;
	char	*tmp;

	dir[0] = '\0';
	if (!ft_strlen(cmd))
		return ;
	paths = ft_getenv("PATH");
	tmp = paths;
	while (paths && *paths)
	{
		build_cmd_path(cmd, dir, &paths);
		if (!access(dir, F_OK))
		{
			free(tmp);
			return ;
		}
		if (*paths == ':')
			paths++;
	}
	free(tmp);
	dir[0] = '\0';
}

void	compute_fds(int fds[REDIR_MAX], char mode)
{
	int	i;

	if (mode == INITIALIZE)
	{
		i = -1;
		while (++i < REDIR_MAX)
			fds[i] = -2;
	}
	else
	{
		i = 0;
		while (fds[i] != -2 && i < REDIR_MAX)
			close(fds[i++]);
	}
}

int	is_builtin(char **tokens)
{
	if (equal("echo", *tokens))
		return (1);
	else if (equal("cd", *tokens))
		return (1);
	else if (equal("pwd", *tokens))
		return (1);
	else if (equal("export", *tokens))
		return (1);
	else if (equal("unset", *tokens))
		return (1);
	else if (equal("env", *tokens))
		return (1);
	else if (equal("exit", *tokens))
		return (1);
	return (0);
}
