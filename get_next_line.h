/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:28 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/28 14:59:09 by halnuma          ###   ########.fr       */
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

char	*next_line(int fd, char *line, char *buffer, int nl);
char	*get_next_line(int fd);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*join_line(char	*line, char *buffer, int n);
char	*shift_buffer(char *buffer, int i);
char	*process_buffer(char *line, char *buffer);
int		check_if_nl(char *buffer);

#endif