/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:28 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/27 13:58:09 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_gnl
{
	char	*str;
	int		head;
	int		start;
}	t_gnl;

char	*get_lines(int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	get_size(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

#endif