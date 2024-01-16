/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:08 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/17 16:33:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define NORMAL 0
# define NO_MSG 3
# define W_PERROR 777
# define OUTFILE 1

typedef struct s_files
{
	int	infile;
	int	outfile;
	int	pipefd[2];
}	t_files;

int			ft_begin_with_space(char *str);

size_t		ft_arrlen(char **arr);

char		*ft_getpath(char **env, char *cmd);
char		*ft_get_with_space(char	*dest, char *cmd);
char		**ft_parse_cmd(char **cmd, char **args, char **env);

void		how_to_use(void);
void		ft_free_array(char **arr);
void		ft_file_not_found(char *filename, int id);
void		ft_free_strings(char *str1, char *str2, char *str3);
void		ft_processes(char **cmd, char **args, char **env);
void		ft_command_not_found(char **cmd, char **env, int id);
void		ft_exit_program(int error, char *str, char **arr, int mode);
void		ft_free_and_exit(int error, char **arr1, char **arr2, int mode);

#endif
