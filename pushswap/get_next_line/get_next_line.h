/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:44:58 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/11 17:03:54 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlens(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdups(const char *s1);
char	*ft_substrs(char const *s, unsigned int start, size_t len);
char	*ft_strjoins(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		check_end(char *str);
char	*extract_line(char **buff);
char	*read_to_buff(char *buffer, int fd, int *endof);
char **get_gnl_buffer(void);

#endif
