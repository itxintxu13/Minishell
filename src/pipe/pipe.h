/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:38:13 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:02:54 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../../include/ft_limits.h"
# include "../../include/utils.h"
# include "../../include/shell_functions.h"
# include "../../include/signal_minishel.h"
# include "../../include/commands.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	pipe_io(int in, int out);
void	close_pipe(int p_fd[PIPE_MAX][2], int cant);
void	init_pipe(int p_fd[PIPE_MAX][2], int cant);
int		count_pipe(char **tokens);

#endif