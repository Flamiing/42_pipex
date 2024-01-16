/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:00:10 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:44:19 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

void	how_to_use(void)
{
	write(2, "Usage:  ./pipex infile <comand1> <comand2> outfile\n", 52);
	exit(EXIT_FAILURE);
}

void	ft_exit_program(int error, char *str, char **arr, int mode)
{
	if (str)
		free(str);
	if (arr)
		ft_free_array(arr);
	if (mode == NORMAL)
		write(2, "Error\n", 6);
	else if (mode == W_PERROR)
		perror("Error");
	exit(error);
}

static void	ft_cmd_not_found_with_path(char *cmd, int id, size_t len)
{
	write(2, "pipex: ", 7);
	write(2, cmd, len);
	write(2, ": command not found\n", 20);
	if (id == 0)
		ft_exit_program(0, cmd, 0, NO_MSG);
	if (id == 1)
		ft_exit_program(127, cmd, 0, NO_MSG);
}

void	ft_command_not_found(char **cmd, char **env, int id)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	if (id == 1 && ft_begin_with_space(cmd[id]))
		exit(errno);
	while (cmd[id][len] && cmd[id][len] == 32 && ft_begin_with_space(cmd[id]))
		len++;
	while (cmd[id][len] && cmd[id][len] != 32)
		len++;
	while (env[count] && ft_strnstr(env[count], "PATH=", 5) == 0)
		count++;
	if (count == ft_arrlen(env))
	{
		write(2, "pipex: ", 7);
		write(2, cmd[id], len);
		write(2, ": ", 2);
		perror("");
		ft_exit_program(errno, cmd[id], 0, NO_MSG);
	}
	else
		ft_cmd_not_found_with_path(cmd[id], id, len);
}

void	ft_free_and_exit(int error, char **arr1, char **arr2, int mode)
{
	if (arr1[0])
		free(arr1[0]);
	if (arr1[1])
		free(arr1[1]);
	ft_free_array(arr2);
	if (mode)
		ft_exit_program(error, 0, 0, mode);
}
