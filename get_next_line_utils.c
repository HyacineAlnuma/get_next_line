/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:14 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/27 17:51:40 by halnuma          ###   ########.fr       */
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

char	*get_lines(int fd)
{
	char		*res;
	int			readed;
	int			i;
	char		*buffer;
	char		*temp;
	static char *rest;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	i = 0;
	res = NULL;
	//printf("%s", rest);
	if (rest)
	{
		// printf("%s\n", rest);
		//printf("%s", rest);
		ft_strlcpy(buffer, rest, BUFFER_SIZE);
		//printf("%s", buffer);
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				free(rest);
				rest = NULL;
				if (buffer[i + 1])
				{
					//rest = NULL;
					rest = ft_substr(buffer, (i + 1), BUFFER_SIZE);
					if (!rest)
					{
						free(res);
						free(buffer);
						return (NULL);
					}
				}
				buffer[i + 1] = '\0';
				res = ft_strjoin(res, buffer);
				if (!res)
				{
					free(buffer);
					return (NULL);
				}
				free(buffer);
				//printf("%s", rest);
				return (res);
			}
			i++;
		}
		free(rest);
		rest = NULL;
		res = ft_strjoin(res, buffer);
		if (!res)
		{
			free(buffer);
			return (NULL);
		}
	}
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		readed = read(fd, buffer, BUFFER_SIZE);
		//printf("%s\n", buffer);
		if (readed < 0)
		{
			if (res)
				free(res);
			if (rest)
				free(rest);
			free(buffer);
			// if (res)
			// 	return (res);
			return (NULL);
		}
		if (readed == 0)
		{
			free(buffer);
			if (res)
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
					if (rest)
						free(rest);
					rest = ft_substr(buffer, (i + 1), BUFFER_SIZE);
					//printf("%s", rest);
					if (!rest)
					{
						free(res);
						free(buffer);
						return (NULL);
					}
				}
				buffer[i + 1] = '\0';
				temp = res;
				// printf("%s", rest);
				// printf("-----");
				res = ft_strjoin(res, buffer);
				//printf("%s", res);
				// printf("-----");
				if (temp)
					free(temp);
				if (!res)
				{
					free(buffer);
					return (NULL);
				}
				//free(rest);
				free(buffer);
				return (res);
			}
			i++;
		}
		temp = res;
		res = ft_strjoin(res, buffer);
		if (temp)
			free(temp);
		if (!res)
		{
			free(rest);
			return (NULL);
		}
		if (readed < BUFFER_SIZE)
		{
			free(rest);
			free(buffer);
			return (res);
		}
	}
	free(buffer);
	return (res);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*res;
	size_t	i;
	size_t	j;
	size_t s1_size;

	s1_size = 0;
	if (s1)
		s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(sizeof(char), size);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[j])
		{
			res[i] = s1[j];
			i++;
			j++;
		}
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}

size_t	get_size(char *s, unsigned int start, size_t len)
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

char	*ft_substr(char *s, unsigned int start, size_t len)
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
