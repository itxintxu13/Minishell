/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29  by assistant           #+#    #+#             */
/*   Updated: 2026/01/29  by assistant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "execute/simple_command.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char	**prepare_tokens(char *str)
{
	char	**tokens;

	tokens = tokenize(str);
	tokens = parse(tokens);
	tokens = expand(tokens);
	return (tokens);
}

void	child_execute_tokens(char **tokens, int has_pipe)
{
	if (has_pipe)
		compute_pipeline(tokens);
	else
		execute_simple_command(tokens, NOT_PIPE);
	free_all(tokens);
	exit(0);
}

void	parent_finalize(char **tokens,
			int status,
			int has_pipe,
			char **env_save)
{
	free_all(tokens);
	verify_env_cwd(status || has_pipe, env_save);
	ft_export_num("?", WEXITSTATUS(status));
}

int	parent_try_builtin(char **tokens, int has_pipe, char **env_save)
{
	if (!has_pipe && is_builtin(tokens))
	{
		execute_builtin(tokens, NOT_PIPE);
		free_all(tokens);
		return (1);
	}
	(void)env_save;
	return (0);
}

int	prepare_and_get_tokens(char *str, char ***out_tokens, char **env_save)
{
	int	has_pipe;

	has_pipe = search_pipe(str);
	verify_env_cwd(has_pipe, env_save);
	*out_tokens = prepare_tokens(str);
	return (has_pipe);
}
