/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_minishel.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:15:41 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:26:40 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_MINISHEL_H
# define SIGNAL_MINISHEL_H

# include <signal.h>

extern volatile sig_atomic_t	g_signal;

void	signal_main(void);
void	signal_father(void);
void	signal_son(void);
void	write_newline(void);

#endif
