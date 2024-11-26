/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:14 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/26 12:28:22 by halnuma          ###   ########.fr       */
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

char	*get_lines(int fd, char *rest)
{
	char		*res;
	int			readed;
	int			i;
	char		*buffer;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	i = 0;
	res = "";
	if (rest)
	{
		free(buffer);
		buffer = rest;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				rest = ft_substr(buffer, (i + 1), BUFFER_SIZE);
				if (!rest)
				{
					free(buffer);
					return (NULL);
				}
				res = ft_strjoin(res, buffer);
				if (!res)
				{
					free(buffer);
					return (NULL);
				}
				return (res);
			}
			i++;
		}
		res = ft_strjoin(res, buffer);
		if (!res)
		{
			free(buffer);
			return (NULL);
		}
	}
	while (readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			free(buffer);
			if (*res)
				return (res);
			return (NULL);
		}
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				if (buffer[i + 1])
				{
					rest = ft_substr(buffer, (i + 1), BUFFER_SIZE);
					if (!rest)
					{
						free(buffer);
						return (NULL);
					}
					buffer[i + 1] = '\0';
					res = ft_strjoin(res, buffer);
					if (!res)
					{
						free(buffer);
						return (NULL);
					}
				}
				free(buffer);
				return (res);
			}
			if (readed < BUFFER_SIZE)
			{
				// rest = ft_substr(buffer, (i + 1), BUFFER_SIZE);
				// if (!rest)
				// {
				// 	free(buffer);
				// 	return (NULL);
				// }
				// printf("yo");
				// printf("%s", buffer);
				// buffer[readed] = '\0';
				if (readed)
				{
					res = ft_strjoin(res, buffer);
					if (!res)
					{
						free(buffer);
						return (NULL);
					}
				}
				free(buffer);
				return (res);
			}
			i++;
		}
		if (readed == BUFFER_SIZE)
		{
			res = ft_strjoin(res, buffer);
			if (!res)
			{
				free(buffer);
				return (NULL);
			}
			//free(buffer);
		}
	}
	free(buffer);
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

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	return (res);
}

size_t	get_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	if (start >= ft_strlen(s))
		size = 1;
	else if ((ft_strlen(s) - start) > len)
		size = len + 1;
	else
		size = ft_strlen(s) - start + 1;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	size;

	size = get_size(s, start, len);
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		res[0] = '\0';
		return (res);
	}
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
