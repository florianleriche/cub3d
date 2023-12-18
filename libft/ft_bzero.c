/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:31:15 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/05 18:19:55 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = s;
	while (n != 0)
	{
		ptr[i] = '\0';
		i++;
		n--;
	}
}
