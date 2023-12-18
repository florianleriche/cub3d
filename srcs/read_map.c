/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:47 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/14 14:12:18 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	read_map(char *map, t_data *dta)
{
	int		fd;
	char	*buffer;
	ssize_t	nread;

	nread = 1;
	buffer = malloc(sizeof(char) * 1024);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	nread = read(fd, buffer, 1024);
	if (nread < -1)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	dta->map_str = buffer;
	dta->map = ft_split(buffer, '\n');
	// printf("%s\n", dta->map_str);
	// printf("%s", dta->map[1]);
	// printf("%s", dta->map[1]);
	// printf("%s", dta->map[2]);
	// printf("%s", dta->map[3]);
	close(fd);
	free(buffer);
}