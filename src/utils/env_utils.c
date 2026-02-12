/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:40:23 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:43:54 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include <dirent.h>
#include <stddef.h>

#define NAME 0
#define PATH 1

static char	*create_name(int count, char mode)
{
	char	*result;
	char	*n;

	n = ft_itoa(count);
	if (mode == NAME)
	{
		result = ft_strjoin(".env_minishell", n);
		free(n);
		return (result);
	}
	else
	{
		result = ft_strjoin("/tmp/.env_minishell", n);
		free(n);
		return (result);
	}
}

static char	check_duplicate(char *name)
{
	DIR				*path;
	struct dirent	*ent;

	path = opendir("/tmp");
	ent = readdir(path);
	while (ent)
	{
		if (equal(ent->d_name, name))
		{
			closedir(path);
			return (1);
		}
		ent = readdir(path);
	}
	closedir(path);
	return (0);
}

char	*name_env(void)
{
	static int		count = -1;
	static char		*result;

	if (count == -1)
	{
		count++;
		result = create_name(count, NAME);
		while (check_duplicate(result))
		{
			free(result);
			count++;
			result = create_name(count, NAME);
		}
		free(result);
		result = create_name(count, PATH);
	}
	return (result);
}
