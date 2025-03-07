/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:34:17 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/07 15:40:21 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int     fd;
	char    *line;
	char    input;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	
	printf("Press Enter to read next line (q + Enter to quit):\n");
	while (1)
	{
		input = getchar();
		if (input == 'q')
			break;
		if (input == '\n')
		{
			line = get_next_line(fd);
			if (line)
			{
				printf("Line: %s", line);
				free(line);
			}
			else
			{
				printf("End of file reached\n");
				break;
			}
		}
	}
	
	close(fd);
	return (0);
}