/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:30:01 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/27 17:49:44 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char *res;

	if (BUFFER_SIZE <= 0 || fd < 0 || !fd)
		return (NULL);
	res = get_lines(fd);
	if (!res)
		return (NULL);
	//printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	// res = get_lines(fd);
	// printf("%s", res);
	return (res);
}

// int	main(int ac, char**av)
// {
// 	int fd;

// 	(void)ac;
// 	(void)av;
// 	fd = open(av[1], O_RDONLY);
// 	//fd = 0;
// 	if (fd < 0)
// 	{
// 		write(2, "File error\n", 11);
// 		return (0);
// 	}
// 	get_next_line(fd);
// }
