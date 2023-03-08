/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:30 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/08 15:10:12 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"

void	vedolagentescema(t_map map)
{
	int i=0, j=0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("%d,%d ",map.point_array[i][j].z,map.point_array[i][j].clr);
			j++;
		}
		printf("\n\n");
		i++;
	}
	
}

int	main(int argc, char const *argv[])
{
	t_map	map;

	if (argc == 2 && argv)
	{
		map = (t_map){0, 0, 1, NULL};
		map.zoom = 1;
		//ft_read_file(open("../maps/42.fdf", O_RDONLY), &map);
		ft_read_file(open(argv[1], O_RDONLY), &map);
		vedolagentescema(map);
		printf("\n\ncreiamo immagine\n");
		ft_create_image(&map);
	}
	read(0, NULL, 0);
	return (0);
}
