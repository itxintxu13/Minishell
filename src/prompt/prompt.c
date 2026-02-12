/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:49:35 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:24:14 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_prompt(void)
{
	ft_putstr(GREEN);
	ft_putstr("🐚 minishell$ Andrea & Itxine");
	ft_putstr(RESET);
}
