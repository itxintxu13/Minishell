/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:23 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:01:22 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/minishell.h"
#include "../include/signal_minishel.h"
#include "execute/simple_command.h"

static void	wait_parent(pid_t pid, int *status)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, status, 0);
	if (WIFSIGNALED(*status) && WTERMSIG(*status) == SIGINT)
		write_newline();
	signal_main();
}

void	execute_console(char *str, char **env_save)
{
	pid_t	pid;
	int		status;
	char	**tokens;
	int		has_pipe;

	has_pipe = prepare_and_get_tokens(str, &tokens, env_save);
	if (!tokens || !*tokens)
	{
		if (tokens)
			free_all(tokens);
		else
			ft_export_num("?", 2);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		signal_son();
		child_execute_tokens(tokens, has_pipe);
	}
	else
		wait_parent(pid, &status);
	parent_finalize(tokens, status, has_pipe, env_save);
}

static int	handle_stdin_signal(char *str, char **env_save)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		ft_export_num("?", 1);
	}
	if (!str)
	{
		free_all(env_save);
		if (write(2, "exit\n", 5) == -1)
			return (0);
		return (0);
	}
	return (1);
}

void	initialize_shell(int *argc, char ***argv, char **env)
{
	(void) *argc;
	(void) *argv;
	signal_main();
	load_env(env);
	valid_env();
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**env_save;

	initialize_shell(&argc, &argv, env);
	while (in_loop())
	{
		env_save = ft_getallenv();
		ft_prompt();
		str = readline(" ");
		if (!handle_stdin_signal(str, env_save))
			break ;
		if (ft_strlen(str))
			add_history(str);
		g_signal = 0;
		execute_console(str, env_save);
		free_all(env_save);
	}
	last_exit();
	return (0);
}
