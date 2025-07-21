/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:32:50 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/17 09:02:06 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_waitpid(pid_t pid1, pid_t pid2)
{
    int status;
    pid_t wpid;
    int exit_status = 0;

    while ((wpid = wait(&status)) > 0) 
    {
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            if (wpid == pid2) 
                exit_status = code;
            else if (wpid == pid1 && exit_status == 0) 
                exit_status = code;
            else if (WIFSIGNALED(status)) 
                exit_status = 128 + WTERMSIG(status);
        }
    }
    return exit_status;
}

int create_pid(char **argv, char **envp)
{
    int fd[2];
	pid_t pid1, pid2;

    if (pipe(fd) == -1)
        exit(0);
    pid1 = fork();
    if (pid1 == -1)
        exit(1);
    if (pid1 == 0)
        cmd_one(argv[1], argv[2], fd, envp);
    pid2 = fork();
    if (pid2 == -1)
        exit(1);
    if (pid2 == 0)
        cmd_two(argv[4], argv[3], fd, envp);
    close(fd[0]);
    close(fd[1]);
	return (ft_waitpid(pid1, pid2));
}
int	main(int argc, char **argv, char **envp)
{
    if (argc != 5)
    {
        perror("ARGUMENTS ERROR");
        return (1);
    }
    return (create_pid(argv, envp));
}
