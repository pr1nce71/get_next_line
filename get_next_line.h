/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:31:13 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/07 13:28:19 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

// utils
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);

// Mandatory 
char	*ft_reader(int fd, char *str);
char	*ft_printer(char *str);
char	*ft_editor(char *str);
char	*get_next_line(int fd);

#endif