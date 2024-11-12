/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alasoare <alasoare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:24:10 by alasoare          #+#    #+#             */
/*   Updated: 2024/10/30 09:24:42 by alasoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = (ft_strlen(s1));
	len2 = (ft_strlen(s2));
	ptr = malloc ((len1 + len2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strappend(ptr, s1, s2, len1 + len2 + 1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strappend(copy, s1, NULL, len + 1);
	return (copy);
}

void	ft_strappend(char *dst, const char *src1, const char *src2, size_t size)
{
	while (*src1 && --size)
		*dst++ = *src1++;
	if (src2 && size > 0)
		while (*src2 && --size)
			*dst++ = *src2++;
	*dst = '\0';
}
