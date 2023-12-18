/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:27 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/18 15:55:35 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_exit(t_data *dta, char *str)
{
	dta->map_str = dta->map_str;
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}