/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:58:09 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:22:51 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

static size_t	ft_len(char *str, char limit)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != limit)
		count++;
	return (count);
}

static char	*ft_path_not_found(char *cmd)
{
	char	*copy;

	copy = (char *)ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, cmd, ft_strlen(cmd) + 1);
	return (copy);
}

static char	*ft_cmd_only(char *cmd)
{
	size_t	index;
	size_t	size;
	char	*cmd_only;

	if (!cmd)
		return (NULL);
	index = 0;
	size = ft_len(cmd, 32) + 1;
	cmd_only = (char *)malloc(size);
	if (!cmd_only)
		return (NULL);
	ft_strlcpy(cmd_only, cmd, size);
	return (cmd_only);
}

static char	*ft_getcmd_path(char **path_arr, char *cmd)
{
	size_t	count;
	char	*path;
	char	*cmd_path;
	char	*cmd_only;

	count = 0;
	cmd_path = NULL;
	if (ft_begin_with_space(cmd))
		return (ft_get_with_space(cmd_path, cmd));
	while (path_arr[count])
	{
		path = ft_strjoin(path_arr[count], "/");
		cmd_only = ft_cmd_only(cmd);
		cmd_path = ft_strjoin(path, cmd_only);
		if (access(cmd_path, F_OK & X_OK) == 0)
		{
			free(path);
			free(cmd_only);
			return (cmd_path);
		}
		ft_free_strings(path, cmd_only, cmd_path);
		count++;
	}
	return (ft_path_not_found(cmd));
}

char	*ft_getpath(char **env, char *cmd)
{
	size_t	count;
	char	**path_arr;
	char	*cmd_path;

	if (!env || !cmd)
		return (NULL);
	count = 0;
	while (env[count] && ft_strnstr(env[count], "PATH=", 5) == 0)
		count++;
	if (count == ft_arrlen(env))
		return (ft_path_not_found(cmd));
	path_arr = ft_split(env[count] + 5, 58);
	if (!path_arr)
		exit(EXIT_FAILURE);
	cmd_path = ft_getcmd_path(path_arr, cmd);
	ft_free_array(path_arr);
	return (cmd_path);
}
