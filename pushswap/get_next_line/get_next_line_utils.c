/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:45:16 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/18 14:38:58 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlens(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdups(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlens(s1);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	copy = ft_strcpy(copy, s1);
	return (copy);
}

char	*ft_substrs(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sl;

	sl = ft_strlens(s);
	if (!s)
		return (NULL);
	if (len >= sl - start)
		len = sl - start;
	if (start > sl)
		return (ft_strdups(""));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoins(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlens(s1) + ft_strlens(s2);
	joined = (char *)malloc((len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}
