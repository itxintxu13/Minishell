/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:09:57 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:50:00 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../include/utils.h"
#include "../../include/ft_limits.h"
#include "redirections.h"

#define TRUNCATE 0
#define APPEND 1
#define BUFFER_SIZE 1000

char	**redir_input(char **tokens, int *i, int *fd)
{
	*fd = open(tokens[*i + 1], O_RDONLY);
	if (*fd == -1)
	{
		if (write(STDERR_FILENO, " ", 1) == -1)
			exit(EXIT_FAILURE);
		if (write(STDERR_FILENO, strerror(errno),
				ft_strlen(strerror(errno))) == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDIN_FILENO);
	return (remove_redir_tokens(tokens, i));
}

char	**redir_output(char **tokens, int *i, int *fd, char mode)
{
	int		flags;
	mode_t	permitions;

	flags = O_WRONLY | O_CREAT | O_APPEND;
	if (mode == TRUNCATE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	permitions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	*fd = open(tokens[*i + 1], flags, permitions);
	if (*fd == -1)
	{
		if (write(STDERR_FILENO, " ", 1) == -1)
			exit(EXIT_FAILURE);
		if (write(STDERR_FILENO, strerror(errno),
				ft_strlen(strerror(errno))) == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	return (remove_redir_tokens(tokens, i));
}

char	*load_buffer(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	char	*input;
	int		ret;

	input = 0;
	ret = 1;
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE - 1);
		if (ret == -1)
			error_handle(0, 0);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		tmp = ft_strjoin(input, buf);
		free(input);
		input = tmp;
	}
	return (input);
}

char	**redir_heredoc(char **tokens, int *i)
{
	char	name[65];
	int		fd;
	char	*buf;
	int		pipe_hd[2];

	ft_memmove(name, "./", 3);
	ft_strlcat(name, tokens[*i + 1], 65);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_handle(0, 0);
	buf = load_buffer(fd);
	close(fd);
	unlink(name);
	if (pipe(pipe_hd) == -1)
		error_handle(0, 0);
	if (buf && write(pipe_hd[1], buf, ft_strlen(buf)) == -1)
	{
		free(buf);
		error_handle(0, 0);
	}
	close(pipe_hd[1]);
	free(buf);
	dup2(pipe_hd[0], STDIN_FILENO);
	close(pipe_hd[0]);
	return (remove_redir_tokens(tokens, i));
}

char	**redirection(char **tokens, int fds[REDIR_MAX])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tokens && tokens[++i])
	{
		if (j >= REDIR_MAX)
			error_handle(0, "Exceeded redirections limit\n");
		if (equal(tokens[i], "<"))
			tokens = redir_input(tokens, &i, &fds[++j]);
		else if (equal(tokens[i], ">"))
			tokens = redir_output(tokens, &i, &fds[++j], TRUNCATE);
		else if (equal(tokens[i], ">>"))
			tokens = redir_output(tokens, &i, &fds[++j], APPEND);
		else if (equal(tokens[i], "<<"))
			tokens = redir_heredoc(tokens, &i);
	}
	return (tokens);
}
