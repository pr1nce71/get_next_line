/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:31:23 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/10 13:08:43 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strdup_gnl(const char *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = my_strlen(s);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*my_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_strjoin(char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*result;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len1 = my_strlen(s1);
	len2 = my_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (free(s1), NULL);
	my_strcpy(result, s1);
	my_strcpy(result + len1, s2);
	free(s1);
	return (result);
}

const char	*my_strchr(const char *s, int i)
{
	if (!s)
		return (0);
	if (i == '\0')
		return (&s[my_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)i)
			return (s);
		s++;
	}
	return (0);
}
