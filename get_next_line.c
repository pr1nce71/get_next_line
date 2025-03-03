/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:41 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/03 17:59:58 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reads(int fd, char *str)
{
	int		len;
	char	*buff;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
			return (free(buff), free(str), NULL);
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	free(buff);
	return (str);
}
// camera
// reads from file descriptor and adds data to str

char	*ft_print(char *str)
{
	int		len;
	char	*buff;

	len = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	buff = malloc(sizeof(char) * (len + 2));
	if (!buff)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		buff[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		buff[len] = '\n';
		len++;
	}
	buff[len] = '\0';
	return (buff);
}
// commentator
// cuts from str first line to \n and makes copy

char	*ft_next_line(char *str)
{
	int		len;
	char	*buff;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (!str[len])
		return (free(str), NULL);
	buff = malloc(sizeof(char) * (ft_strlen(str) - len + 1));
	if (!buff)
		return (free(str), NULL);
	len++;
	ft_strcpy(buff, &str[len]);
	free(str);
	return (buff);
}
// editor
// it cuts str removing the first line be4 \n
// returns cutted str
// if after 1st string there is no data, it's free & returns NULL

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_reads(fd, str);
	if (!str)
		return (NULL);
	s = ft_print(str);
	str = ft_next_line(str);
	return (s);
}
// updates static str with ft_reads
// returns ready line

// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("1.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    char *line1 = NULL;
    char *line2 = NULL;

    printf("Reading from file1.txt and file2.txt simultaneously:\n\n");

    while (1)
    {
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
        }

        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
        }

        if (!line1 && !line2)
            break;
    }

    close(fd1);
    close(fd2);
    return (0);
}

