/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:22:47 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 15:26:14 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

int	load_env(char **env)
{
	int	aux;
	int	fd;

	fd = open(name_env(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	aux = 0;
	while (env && env[aux])
	{
		if (write(fd, env[aux], len(env[aux])) == -1)
		{
			close(fd);
			return (0);
		}
		if (write(fd, "\n", 1) == -1)
		{
			close(fd);
			return (0);
		}
		aux++;
	}
	close(fd);
	return (1);
}

char	**ft_getallenv(void)
{
	int		fd;
	char	**vars;

	fd = open(name_env(), O_RDONLY);
	if (fd == -1)
		return (NULL);
	vars = read_file(fd, '\n');
	return (vars);
}

int	ft_env(void)
{
	char	**vars;
	char	*exclude;
	int		aux;
	char	*tem;

	vars = ft_getallenv();
	tem = ft_getenv("?");
	exclude = append(ft_strdup("?="), ft_strlen(tem), tem);
	free(tem);
	aux = 0;
	while (vars && vars[aux])
	{
		if (!equal(exclude, vars[aux]) && vars[aux][0] != '?')
			printf("%s\n", vars[aux]);
		aux++;
	}
	free(exclude);
	free_all(vars);
	return (1);
}

int	determine_size(char *var, char *name, int size1)
{
	int	size2;

	size2 = ft_strlen(name);
	while (var[size1] != '=')
		size1++;
	if (size1 > size2)
		return (size1);
	return (size2);
}

char	*ft_getenv(char *name)
{
	char	**vars;
	char	*result;
	int		size;
	int		aux;
	int		index;

	result = NULL;
	index = -1;
	vars = ft_getallenv();
	while (vars && vars[++index])
	{
		aux = 0;
		while (vars[index][aux] && vars[index][aux] != '=')
			aux++;
		size = determine_size(vars[index], name, aux);
		if (equaln(vars[index], name, size))
		{
			result = copy_vec(vars[index] + aux + 1);
			break ;
		}
	}
	free_all(vars);
	return (result);
}
