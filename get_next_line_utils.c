/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:14 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/25 15:56:19 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	bytes_nb;

	bytes_nb = nmemb * size;
	if (nmemb * size != 0)
		if (nmemb > SIZE_MAX / size)
			return (NULL);
	res = malloc(bytes_nb);
	if (!res)
		return (NULL);
	ft_bzero(res, bytes_nb);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

char	*get_lines(int fd, char *buffer)
{
	char	*res;
	int		readed;
	int		i;
	int		end_line;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	end_line = 1;
	i = 0;
	res = "";
	while (readed && end_line)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				end_line = 0;
				buffer[i + 1] = '\0';
				res = ft_strjoin(res, buffer);
				return (res);
			}
			i++;
		}
		res = ft_strjoin(res, buffer);
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		res[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
