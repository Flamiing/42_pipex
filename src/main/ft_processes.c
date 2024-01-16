/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:01:02 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:32:29 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>

static int	ft_first_child(t_files files, char **cmd, char **args, char **env)
{
	int		pid;
	char	**params;

	params = ft_split(args[2], 32);
	if (!params)
		ft_free_and_exit(EXIT_FAILURE, 0, params, NORMAL);
	pid = fork();
	if (pid < 0)
		ft_free_and_exit(EXIT_FAILURE, 0, params, NORMAL);
	if (pid == 0)
	{
		dup2(files.pipefd[1], STDOUT_FILENO);
		dup2(files.infile, STDIN_FILENO);
		close(files.pipefd[0]);
		close(files.infile);
		if (execve(cmd[0], params, env) == -1)
		{
			free(cmd[1]);
			ft_free_array(params);
			ft_command_not_found(cmd, env, 0);
		}
	}
	ft_free_array(params);
	return (pid);
}

static int	ft_second_child(t_files files, char **cmd, char **args, char **env)
{
	int		pid;
	char	**params;

	params = ft_split(args[3], 32);
	if (!params)
		ft_free_and_exit(EXIT_FAILURE, 0, params, NORMAL);
	pid = fork();
	if (pid < 0)
		ft_free_and_exit(errno, 0, params, W_PERROR);
	if (pid == 0)
	{
		dup2(files.pipefd[0], STDIN_FILENO);
		dup2(files.outfile, STDOUT_FILENO);
		close(files.pipefd[1]);
		close(files.outfile);
		if (execve(cmd[1], params, env) == -1)
		{
			free(cmd[0]);
			ft_free_array(params);
			ft_command_not_found(cmd, env, 1);
		}
	}
	ft_free_array(params);
	return (pid);
}

static void	ft_handle_waits(int pid1, int pid2)
{
	int	wstatus;
	int	status_code;

	waitpid(pid1, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		if (status_code != 0)
			exit(status_code);
	}
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		if (status_code != 0)
			exit(status_code);
	}
}

void	ft_processes(char **cmd, char **args, char **env)
{
	t_files	files;
	int		pid[2];

	files.infile = open(args[1], O_RDONLY);
	if (files.infile == -1)
		ft_file_not_found(args[1], 0);
	files.outfile = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files.outfile == -1 || access(args[4], W_OK) != 0)
		ft_file_not_found(args[4], OUTFILE);
	if (pipe(files.pipefd) == -1)
		ft_free_and_exit(errno, cmd, 0, W_PERROR);
	if (files.infile != -1)
		pid[0] = ft_first_child(files, cmd, args, env);
	pid[1] = ft_second_child(files, cmd, args, env);
	close(files.pipefd[0]);
	close(files.pipefd[1]);
	ft_handle_waits(pid[0], pid[1]);
	if (files.outfile == -1)
		exit(errno);
}
