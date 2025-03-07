/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:41 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/07 15:40:44 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_reader(int fd, char *str)
{
	int		len;
	char	*line;

	if (!str)
		str = my_strdup_gnl("");
	if (!str)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (free(str), NULL);
	len = 1;
	while (!my_strchr(str, '\n') && len != 0)
	{
		len = read(fd, line, BUFFER_SIZE);
		if (len == -1)
			return (free(line), free(str), NULL);
		line[len] = '\0';
		str = my_strjoin(str, line);
		if (!str)
			return (free(line), NULL);
	}
	free(line);
	return (str);
}
// camera
// reads from file descriptor and adds data to str

char	*my_printer(char *str)
{
	int		len;
	char	*line;

	if (!str || !*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}
// commentator
// cuts from str first line to \n and makes copy

char	*my_editor(char *str)
{
	size_t	len;
	char	*new_str;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (!str[len])
		return (free(str), NULL);
	new_str = malloc(my_strlen(str) - len);
	if (!new_str)
		return (free(str), NULL);
	len++;
	my_strcpy(new_str, &str[len]);
	free(str);
	return (new_str);
}
// it cuts str removing the first line be4 \n
// returns cutted str
// if after 1st string there is no data, it's free & returns NULL

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = my_reader(fd, str);
	if (!str)
		return (NULL);
	s = my_printer(str);
	str = my_editor(str);
	return (s);
}
// updates static str with ft_reads
// returns ready line

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int     fd;
// 	char    *line;
// 	char    input;
	
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
	
// 	printf("Press Enter to read next line (q + Enter to quit):\n");
// 	while (1)
// 	{
// 		input = getchar();
// 		if (input == 'q')
// 			break;
// 		if (input == '\n')
// 		{
// 			line = get_next_line(fd);
// 			if (line)
// 			{
// 				printf("Line: %s", line);
// 				free(line);
// 			}
// 			else
// 			{
// 				printf("End of file reached\n");
// 				break;
// 			}
// 		}
// 	}
	
// 	close(fd);
// 	return (0);
// }