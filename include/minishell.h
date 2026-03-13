/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:09:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:19:56 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include "shell_functions.h"
# include "commands.h"
# include "signal_minishel.h"
# include "main_utils.h"

# define RED     "\001\033[31m\002"
# define GREEN   "\001\033[32m\002"
# define YELLOW  "\001\033[33m\002"
# define BLUE    "\001\033[34m\002"
# define RESET   "\001\033[0m\002"
# define BOLD    "\001\033[1m\002"

char	*ft_prompt(void);
void	ft_putstr(char *s);

#endif
