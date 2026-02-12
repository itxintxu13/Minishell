/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:36:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:39:48 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_COMMAND_H
# define SIMPLE_COMMAND_H

# include "../../include/utils.h"
# include "../../include/commands.h"
# include "../../include/ft_limits.h"
# include "../../include/shell_functions.h"
# include "../../include/signal_minishel.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define INITIALIZE 0
# define CLOSE 1

void	execute_builtin(char **tokens, int has_pipe);
void	execute_binary(char **tokens);
void	execute_simple_command(char **tokens, int has_pipe);
void	build_cmd_path(char *cmd, char dir[PATH_MAX], char **paths);
void	check_path_var(char *cmd, char dir[PATH_MAX]);
void	compute_fds(int fds[REDIR_MAX], char mode);

#endif
