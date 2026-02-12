/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:41:57 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:23:33 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../../include/utils.h"

void	error_handle(int err, char *str)
{
	char	*str_err;

	str_err = strerror(errno);
	if (err != 0)
	{
		if (!str && write(STDERR_FILENO, str_err, ft_strlen(str_err)) == -1)
			exit(EXIT_FAILURE);
		else if (str && write(STDERR_FILENO, str, ft_strlen(str)) == -1)
			exit(EXIT_FAILURE);
		if (write(STDERR_FILENO, "\n", 1) == -1)
			exit(EXIT_FAILURE);
		exit(err);
	}
	if (err == 0 && !str)
	{
		if (write(STDERR_FILENO, str_err, ft_strlen(str_err)) == -1
			|| write(STDERR_FILENO, "\n", 1) == -1)
			exit(EXIT_FAILURE);
		exit(errno);
	}
}

void	error_handle_f(int err, char *str)
{
	char	*str_err;

	str_err = strerror(errno);
	if (err != 0)
	{
		if (!str)
		{
			if (write(STDERR_FILENO, " ", 1) == -1)
				return ;
			if (write(STDERR_FILENO, str_err, ft_strlen(str_err)) == -1)
				return ;
		}
		else
		{
			if (write(STDERR_FILENO, str, ft_strlen(str)) == -1)
				return ;
		}
	}
	exit(err);
}
