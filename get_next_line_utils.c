/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:45:23 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/12 15:19:17 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (*(s++) != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;
	char	*beg;

	len = ft_strlen(s1);
	if ((cpy = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	beg = cpy;
	while (len-- > 0)
	{
		*(cpy++) = *(s1++);
	}
	*cpy = '\0';
	return (beg);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*beg;
	size_t	len1;
	size_t	len2;
	char	*p_s1;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((new_str = malloc(sizeof(char) * (len1 + len2) + 1)) == NULL)
		return (NULL);
	beg = new_str;
	p_s1 = (char *)s1;
	while (*s1)
		*new_str++ = *s1++;
	free(p_s1);
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (beg);
}

char		*ft_strchr(const char *s, int c)
{
	char *ps;

	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == (char)c)
			return (ps);
		ps++;
	}
	if (c == '\0')
		return (ps);
	return (0);
}
