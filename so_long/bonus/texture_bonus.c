/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:54:40 by wochae            #+#    #+#             */
/*   Updated: 2022/07/26 16:54:42 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	texture_change(t_info *info)
{
	static int	idx;

	if (idx++ >= 12)
	{
		if (info->map.t < 3)
			info->map.t++;
		else
			info->map.t = 0;
		idx = 0;
	}
}

void	change_enemy_dir(t_map *map)
{
	if (map->dir == 1)
	{
		map->dir = -1;
		map->b = 1;
	}
	else
	{
		map->dir = 1;
		map->b = 0;
	}
}
