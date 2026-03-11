/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:25:53 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:47:46 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

void	verify_env_cwd(int status, char **env_save);
int		search_pipe(char *str);
char	**prepare_tokens(char *str);
void	child_execute_tokens(char **tokens, int has_pipe);
void	parent_finalize(char **tokens,
			int status,
			int has_pipe,
			char **env_save);
int		prepare_and_get_tokens(char *str,
			char ***out_tokens,
			char **env_save);
#endif
