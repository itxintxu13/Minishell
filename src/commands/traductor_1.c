/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:26:11 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:23:08 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

void	ft_env_tokens(void)
{
	ft_env();
	error_handle_f(0, 0);
}

int	verify(char *str)
{
	while (str && *str)
	{
		if ((*str < '0' || *str > '9') && (*str != '+'))
		{
			if (*str == '-')
				return (1);
			return (2);
		}
		str++;
	}
	return (0);
}

void	ft_exit_tokens(char **tokens, int has_pipe)
{
	int	len;

	len = len_all(tokens);
	if (len == 1)
		ft_exit(0);
	if (verify(tokens[1]) == 1)
		error_handle_f(156, "");
	if (verify(tokens[1]) == 2)
	{
		if (write(2, "exit: numeric argument required\n", 33) == -1)
			return ;
		if (!has_pipe)
			ft_exit(2);
	}
	if (len > 2)
		error_handle_f(1, "exit: too many arguments\n");
	if (!has_pipe)
		ft_exit(ft_atoi(tokens[1]));
}
