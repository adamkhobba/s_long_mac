/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:49:49 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/19 09:38:29 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init(t_map *map)
{
	map->roaderror = 0;
	map->wallerror = 0;
	map->patherror = 0;
	map->itemserror = 0;
	map->recerror = 0;
}

int	ft_perror(char *path, t_map *map)
{
	ft_init(map);
	if (!check_map(path, map))
	{
		ft_putstr("Error\n");
		if (map->patherror)
			ft_putstr("invalid path\n");
		if (map->recerror)
			ft_putstr("the map should a rectangle forme\n");
		if (map->itemserror)
			ft_putstr("invalid items in map\n");
		if (map->wallerror)
			ft_putstr("The map should be surrounded by walls\n");
		if (map->roaderror)
			ft_putstr("Player can't access to exit or a collectif\n");
		exit(1);
	}
	return (1);
}

void	ft_invalid_image(t_data *data)
{
	if (data->player == NULL)
	{
		ft_putstr("Error\n");
		ft_putstr("invalid image\n");
		ft_close(data);
	}
}

void	ft_invalid_image_p(t_data *data)
{
	if (data->img_ptr == NULL)
	{
		ft_putstr("Error\n");
		ft_putstr("invalid image\n");
		ft_close(data);
	}
}
