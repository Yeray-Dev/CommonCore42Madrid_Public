/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:34:25 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/17 09:16:11 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Library

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

//FUNCTIONS
int		ft_waitpid(pid_t pid1, pid_t pid2);
int		create_pid(char **argv, char **envp);
int		main(int argc, char **argv, char **envp);
void	ft_free_split(char **arr); //. utils
char	**find_path(char **envp); //. utils
char	*find_relative_path(char *cmd, char **envp); //. utils
void	mod_cmd(s_cmd_conf *cmd, char **envp); //. utils
void	execute_cmd(char *cmd, char **envp); //. utils
void	cmd_one(char *file, char *cmd, int *fd, char **envp); //. utils
void	cmd_two(char *file, char *cmd, int *fd, char **envp); //. utils

// Strucks

typedef struct t_cmd_conf
{	
	char	**path_array;
	char	**cmd_array;
	char	*cmd_mod;
	char	*cmd_path = NULL;
}s_cmd_conf;

#endif