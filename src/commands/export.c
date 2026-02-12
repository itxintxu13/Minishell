/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itlopez- <itlopez-@student.42urduliz.co>  +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:15:41 by itlopez-          #+#    #+#             */
/*   Updated: 2026/01/19 16:01:42 by itlopez-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/commands.h"

int	valid_name_export(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	if (str[x] >= '0' && str[x] <= '9')
		return (0);
	while (str[x])
	{
		if (str[x] >= 'a' && str[x] <= 'z')
			x++;
		else if (str[x] >= 'A' && str[x] <= 'Z')
			x++;
		else if (str[x] >= '0' && str[x] <= '9')
			x++;
		else if (str[x] == '_' || str[x] == '?' || str[x] == '=')
			x++;
		else
			return (0);
	}
	return (1);
}

int	ft_export(char *name, char *value)
{
	char	**envs;
	char	*result;

	if (!value || !valid_name_export(name))
		error_handle_f(1, " not a valid identifier\n");
	if (!include(name, "="))
		result = ft_strjoin(name, "=");
	else
		result = ft_strdup(name);
	ft_unset(name);
	result = append(result, len(value), value);
	envs = ft_getallenv();
	envs = append_matriz(envs, result);
	load_env(envs);
	free_all(envs);
	free(result);
	return (0);
}

int	ft_export_num(char *name, int num)
{
	char	*value;

	value = ft_itoa(num);
	ft_export(name, value);
	free(value);
	return (0);
}

void	ft_export_void(void)
{
	char	**env;
	int		aux;

	env = ft_getallenv();
	aux = 0;
	while (env[aux])
	{
		printf("declare -x %s\n", env[aux]);
		aux++;
	}
	free_all(env);
}
