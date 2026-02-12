/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:12:40 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/29 14:12:40 by itlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

// funcions
void	ft_exit(int status);
void	last_exit(void);
int		ft_env(void);
int		ft_echo(char *text, int flag_n);
int		ft_export(char *name, char *value);
int		ft_export_num(char *name, int num);
void	ft_export_void(void);
int		valid_name_export(char *str);
int		ft_unset(char *value);
int		ft_cd(char *path);
char	*ft_pwd(void);
char	*ft_getcwd(void);
void	valid_env(void);

// env
char	*ft_getenv(char *name);
char	**ft_getallenv(void);
int		load_env(char **env);

// simple_commans
int		is_builtin(char **tokens);

// traductor.v
void	ft_echo_tokens(char **tokens);
void	ft_cd_tokens(char **tokens, int has_pipe);
void	ft_export_tokens(char **tokens, int has_pipe);
void	ft_unset_tokens(char **tokens, int has_pipe);
void	ft_pwd_tokens(void);
void	ft_env_tokens(void);
void	ft_exit_tokens(char **tokens, int has_pipe);

#endif
