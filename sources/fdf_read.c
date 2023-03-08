/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:42 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/02 18:44:11 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"

int     ft_char_count(char *s, char c)
{
    int i;
    int out;

    i = 0;
    out = 0;
    while (s && s[i] == c)
        i++;    
    while (s && s[i])
    {
        if (s[i] == c && s[i + 1] != c)    
            out++;
        i++;
    }
    return (out);
}

void    ft_create_line(t_map *map, char **str_array, int h)
{
    int     i;
    int     n_el;
    char    **str_toconvert;
    char    *b;

    b = "0123456789ABCEDF";
    n_el = 0;
    i = 0;
    map->point_array[h] = (t_point*) ft_calloc(map->width, sizeof(t_point));
    while (str_array && str_array[i])
    {
        if (ft_strchr(str_array[i], ','))
        {
            str_toconvert = ft_split(str_array[i], ',');
            map->point_array[h][i].z = ft_atoi(str_toconvert[0]);
            map->point_array[h][i].clr = ft_atoib(str_toconvert[1] + 2, b, 16);
        }
        else
            map->point_array[h][i].z = ft_atoi(str_array[i]);        
        n_el++;
        i++;
    }
}

void    ft_create_array(t_map *map,t_list *list)
{
    char    **str_array;
    t_list  *next_lst;
    int     h;
    
    h = 0;
    map->point_array = ft_calloc(map->height, sizeof(t_point*));

	next_lst = list;
	while (next_lst != NULL)
	{
		str_array = ft_split(next_lst -> content, ' ');    
        ft_create_line(map, str_array, h);    
        h++;
		next_lst = next_lst->next;
	}  
}

void    ft_read_file(int fd, t_map *map)
{
    char    *line;
    t_list  *list;
    
    list = NULL;
    line = get_next_line(fd);
    map->width = ft_char_count(line, ' ') + 1;
    ft_lstadd_back(&list, ft_lstnew(line));
    while (line)
    {
        map->height++;
        //line = ft_free(&line);
        line = get_next_line(fd);
        ft_lstadd_back(&list, ft_lstnew(line));
        //height++
    }
    line = ft_free(&line);
    ft_create_array(map, list);
}
//free single items
