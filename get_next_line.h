/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:31:13 by yevkahar          #+#    #+#             */
/*   Updated: 2025/01/30 16:23:35 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>//for malloc and free functions
# include <unistd.h>//for file I/O (read, write, open, close,)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

// PRINCIPALES 
char	*get_next_line(int fd);

// UTILS
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);

#endif