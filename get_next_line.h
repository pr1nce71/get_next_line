/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:31:13 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/11 16:23:17 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif 

// helpers
size_t		my_strlen(const char *s);
const char	*my_strchr(const char *s, int i);
char		*my_strcpy(char *dest, const char *src);
char		*my_strjoin(char *s1, const char *s2);
char		*my_strdup_gnl(const char *s);

// mandatory 
char		*read_line(int fd, char *str);
char		*print_line(char *str);
char		*edit_line(char *str);
char		*get_next_line(int fd);

#endif