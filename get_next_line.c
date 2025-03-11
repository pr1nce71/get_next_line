/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:41 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/10 16:23:11 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
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

static void	copy_line(char *line, char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	*len = i;
}

char	*print_line(char *str)
{
	int		len;
	char	*line;

	if (!str || !*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy_line(line, str, &len);
	return (line);
}
// commentator
// cuts from str first line to \n and makes copy

char	*edit_line(char *str)
{
	size_t	len;
	char	*new_str;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (!str[len] || !str[len + 1])
		return (free(str), NULL);
	len++;
	new_str = malloc(my_strlen(str + len) + 1);
	if (!new_str)
		return (free(str), NULL);
	my_strcpy(new_str, str + len);
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
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	s = print_line(str);
	if (!s)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = edit_line(str);
	return (s);
}
// first gets the line to return, then check if we got the line
// updates static str with editor and printer
// returns ready line

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	char	input;
// 	// Test invalid fd (-1)
// 	printf("Testing invalid fd (-1):\n");
// 	line = get_next_line(-1);
// 	if (!line)
// 		printf("Correct: NULL returned for fd = -1\n\n");
// 	// Normal file reading
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
// }