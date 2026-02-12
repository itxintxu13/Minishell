/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:18:42 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

void	print_str(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return ;
	}
}

void	print_text(char *str)
{
	while (str && *str)
	{
		if (*str == 92)
			str++;
		if (write(1, str, 1) == -1)
			return ;
		str++;
	}
}

int	ft_echo(char *text, int flag_n)
{
	print_text(text);
	if (!flag_n)
		printf("\n");
	return (0);
}
