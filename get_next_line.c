/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:01 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/26 12:25:22 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static t_buffer	*buffer;
// 	char			*res;

// 	buffer = malloc(sizeof(t_buffer));
// 	buffer->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
// 	if (!buffer->str)
// 		return (NULL);
// 	read(fd, buffer);
// 	buffer->str[BUFFER_SIZE - 1] = '\0';
// 	buffer->head = 0;
// 	buffer->start = 0;
// 	res = get_lines(buffer);
// 	buffer->start = buffer->head;
// 	// printf("%s\n", res);
// 	// res = get_lines(buffer);
// 	// buffer->start = buffer->head;
// 	// printf("%s\n", res);
// 	// res = get_line(buffer);
// 	// buffer->start = buffer->head;
// 	// printf("%s\n", res);
// 	return (res);
// }

// char	*read_line(int fd)
// {

// 	size = 0;
// 	reads = read(fd, head, 1);
// 	while (head[0] != '\n' && reads != -1)
// 	{
// 		printf("%d\n", reads);
// 		read(fd, head, 1);
// 		size++;
// 	}
// 	printf("%zu\n", size);
// 	buffer = malloc(sizeof(char) * size);
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	char	*buffer;
// 	size_t	i;

// 	buffer = get_line_size(fd);
// 	buffer = get_line_size(fd);
// 	//buffer = get_line_size(fd);
// 	close(fd);
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static t_buffer	*buffer;
// 	size_t	i;

// 	buffer->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
// 	read(fd, buffer->str, BUFFER_SIZE);
// 	//buffer->str[BUFFER_SIZE - 1] = '\0';

// 	printf("%s\n", buffer->str);
// 	return (buffer->str);
// }

char	*get_next_line(int fd)
{
	//static t_gnl	*gnl;
	static char	*rest;
	char *res;

	//gnl = malloc(sizeof(t_gnl));
	//gnl->str = get_lines(fd, gnl);
	// if (!gnl->str)
	// 	return (NULL);
	// printf("%s\n", gnl->str);
	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	res = get_lines(fd, rest);
	if (!res)
		return (NULL);
	free(rest);
	// printf("%s", res);
	// res = get_lines(fd, rest);
	// free(rest);
	// printf("%s", res);
	// res = get_lines(fd, rest);
	// free(rest);
	// printf("%s", res);
	return (res);
}

// int	main(int ac, char**av)
// {
// 	int fd;

// 	(void)ac;
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(2, "File error\n", 11);
// 		return (0);
// 	}
// 	get_next_line(fd);
// }
