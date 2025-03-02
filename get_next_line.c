/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:41 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/02 17:38:57 by yevkahar         ###   ########.fr       */
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

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
// 	FILE *file;

// 	if (argc < 2) {
// 		printf("Usage: %s <filename>\n", argv[0]);
// 		return 1;
// 	}

// 	file = fopen(argv[1], "r");
// 	if (file == NULL) {
// 		printf("Error opening file: %s\n", argv[1]);
// 		return 1;
// 	}

// 	printf("File opened successfully\n");

// 	fclose(file);
// 	return 0;
// }