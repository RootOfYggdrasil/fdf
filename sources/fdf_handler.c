/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:56 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/01 19:02:46 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"

void	ft_error(char *s)
{
    if (errno == 0)
		ft_putendl_fd(s, STDERR_FILENO);
	else
		perror(s);
	exit(1);
}