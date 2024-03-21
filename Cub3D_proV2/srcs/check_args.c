/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:45:16 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/12 16:45:16 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_check_mapfile(t_data *dta, char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_DIRECTORY);
	if (fd == -1)
	{
		close(fd);
		return ;
	}
	ft_exit(dta, "Map must be a file, and not a directory\n");
}

void	check_args(int argc, char **argv, t_data *dta)
{
	char	*cub;

	if (argc != 2)
		ft_exit(dta, "Expected 2 arguments for argc\n");
	ft_check_mapfile(dta, argv[1]);
	cub = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strcmp(cub, ".cub") != 0)
		ft_exit(dta, "Map must be .cub\n");
	return (free(cub));
}
