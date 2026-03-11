/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:15:55 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:59:09 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>
#include "../../include/signal_minishel.h"

void	handler_ctrl_c(int sing)
{
	(void)(sing);
	if (write(1, "\n", 1) == -1)
		return ;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signal_main(void)
{
	signal(SIGINT, handler_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_father(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signal_son(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
