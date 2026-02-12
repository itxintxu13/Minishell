/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:51:19 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:05:32 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_FUNCTIONS_H
# define SHELL_FUNCTIONS_H

# include "./ft_limits.h"

# define HAS_PIPE 1
# define NOT_PIPE 0

char	**tokenize(char *input);
char	**expand(char **input);
char	**redirection(char **tokens, int fds[REDIR_MAX]);
void	execute_simple_command(char **tokens, int has_pipe);
void	compute_pipeline(char **tokens);
char	**parse(char **tokens);

#endif
