/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:33:12 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/19 12:27:11 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
char	**find_path(char **envp)
{
	int		i;
	char	*path_str;
	char	**path_array;

	i = 0;
	while (envp[i])
	{
		if ((!ft_strncmp(envp[i], "PATH=", 5)))
			path_str = envp[i] + 5;
		i++;
	}
	if (!path_str)
		perror("PATH don't copy");
	path_array = ft_split(path_str, ':');
	if (!path_array)
		perror("Split isn't complete allright");
	return (path_array);
}
char	*find_relative_path(char *cmd, char **envp)
{
	int		i;
	s_cmd_conf cmd;
	
	i = 0;
	mod_cmd(&cmd, **envp);
	while (path_array[i])
	{
		char *temp = ft_strjoin(path_array[i], cmd.cmd_mod);
		if (access(temp, X_OK) == 0)
		{
			cmd.cmd_path = temp;
			break;
		}
		free(temp);
		i++;
	}
	if (path_array[i] == NULL)
		perror("This CMD is not correct");
	ft_free_split(cmd.path_array);
	ft_free_split(cmd.cmd_array);
	free(cmd.cmd_mod);
	return (cmd.cmd_path);
}
void	mod_cmd(s_cmd_conf *cmd, char **envp)
{
	cmd->path_array = find_path(envp);
		if (!cmd->path_array)
			return (NULL);
	cmd->cmd_array = ft_split(cmd, ' ');
	if (!cmd->cmd_array)
	{
		ft_free_split(cmd->path_array);
		return (NULL);
	}
	cmd->cmd_mod = ft_strjoin("/", cmd_array[0]);
	if (!cmd->cmd_mod)
	{
		ft_free_split(cmd->path_array);
		ft_free_split(cmd->cmd_array);
		return (NULL);
	}
	
}
void	execute_cmd(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**array_cmd;
	if (!cmd || !*cmd)
	{
        perror("pipex: command not found");
        exit(0);
    }
	cmd_path = find_relative_path(cmd, envp);
	if (!cmd_path)
	{
		perror("Command not found");
		exit(127);
	}
	array_cmd = ft_split(cmd, ' ');
	if (!array_cmd)
	{
		perror("Error with split");
		free(cmd_path);
		exit(127);
	}
	execve(cmd_path, array_cmd, envp);
	perror("execve failed");
	ft_free_split(array_cmd);
	free(cmd_path);
	exit(1);
}

void	cmd_one(char *file, char *cmd, int *fd, char **envp)
{
	int	first_file;

	first_file = open(file, O_RDONLY);
	if (first_file < 0)
	{
    perror("pipex: Infile");
		perror("pipex: Infile");
        close(fd[0]);
        close(fd[1]);
        exit(1);
	}
	close(fd[0]);
	dup2(first_file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(first_file);
	close(fd[1]);
	execute_cmd(cmd, envp);
}

void	cmd_two(char *file, char *cmd, int *fd, char **envp)
{
	int	second_file;

	second_file = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_file < 0)
	{
		perror("pipex: Outfile");
        close(fd[0]);
        close(fd[1]);
        exit(1);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(second_file, STDOUT_FILENO);
	close(second_file);
	close(fd[0]);
	execute_cmd(cmd, envp);
}
