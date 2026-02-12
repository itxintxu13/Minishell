/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:58:26 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:37:52 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	init_pipe(int p_fd[PIPE_MAX][2], int cant)
{
	int	aux;

	aux = -1;
	while (++aux != cant)
	{
		if (pipe(p_fd[aux]) == -1)
			error_handle(0, 0);
	}
}

void	close_pipe(int p_fd[PIPE_MAX][2], int cant)
{
	int	aux;

	aux = -1;
	while (++aux != cant)
	{
		close(p_fd[aux][0]);
		close(p_fd[aux][1]);
	}
}

void	pipe_io(int in, int out)
{
	if (in)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}

int	count_pipe(char **tokens)
{
	int	cant;
	int	i;

	i = -1;
	cant = -1;
	while (tokens && tokens[++i])
		cant += equal("|", tokens[i]);
	cant++;
	if (cant >= PIPE_MAX)
		error_handle_f(0, "Exceeded pipe maximum limit\n");
	return (cant);
}
