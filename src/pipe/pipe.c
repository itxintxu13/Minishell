/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:45:03 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:33:18 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	**dup_tokens(char **tokens, int init, int end)
{
	int		aux;
	char	**result;

	aux = -1;
	result = z_maloc_matriz((end - init) + 1);
	aux = -1;
	while ((init + (++aux)) != end)
		if (!equal(tokens[init + aux], "|"))
			result[aux] = ft_strdup(tokens[init + aux]);
	return (result);
}

char	**comand_index(char **tokens, int index)
{
	int		aux;
	int		init;
	int		end;
	int		comand;

	aux = -1;
	comand = 0;
	init = -1;
	end = len_all(tokens);
	while (tokens && tokens[++aux])
	{
		if (comand == index && init == -1)
			init = aux;
		if (comand > index)
		{
			end = aux;
			break ;
		}
		if (equal("|", tokens[aux]))
			comand++;
	}
	return (dup_tokens(tokens, init, end));
}

void	await(int pid[PIPE_MAX], int cant_pipe, char **tokens)
{
	int	aux;
	int	status;
	int	exit_code;

	aux = -1;
	exit_code = 0;
	while (++aux <= cant_pipe)
	{
		waitpid(pid[aux], &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
		else
			exit_code = 1;
	}
	ft_export_num("?", exit_code);
	free_all(tokens);
	error_handle_f(exit_code, "");
}

void	redirect_out(int p_fd[PIPE_MAX][2], int aux, int cant_pipe)
{
	if (aux == 0)
		pipe_io(0, p_fd[aux][1]);
	else if (aux == cant_pipe)
		pipe_io(p_fd[aux - 1][0], 0);
	else
		pipe_io(p_fd[aux - 1][0], p_fd[aux][1]);
}

void	compute_pipeline(char **tokens)
{
	int		cant_pipe;
	int		p_fd[PIPE_MAX][2];
	int		pid[PIPE_MAX];
	char	**s_cmd;
	int		aux;

	cant_pipe = count_pipe(tokens);
	init_pipe(p_fd, cant_pipe);
	aux = -1;
	while (++aux <= cant_pipe)
	{
		s_cmd = comand_index(tokens, aux);
		pid[aux] = fork();
		if (pid[aux] == 0)
		{
			signal_son();
			redirect_out(p_fd, aux, cant_pipe);
			close_pipe(p_fd, cant_pipe);
			execute_simple_command(s_cmd, HAS_PIPE);
		}
		free_all(s_cmd);
	}
	close_pipe(p_fd, cant_pipe);
	await(pid, cant_pipe, tokens);
}
