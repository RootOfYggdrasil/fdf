#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
//# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "key_linux.h"

typedef struct s_point
{
	int	z;
	int	clr;
}				t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int zoom;
	t_point **point_array;
}				t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	void	*mlx_win;
	void	*mlx;
	t_map	*map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_read_file(int fd, t_map *map);

void	ft_error(char *s);

void	ft_create_image(t_map *map);

int		key_hook(int key_code, t_data *meta);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void    ft_bresenham(float x, float y, float x1, float y1, t_data *data);
void    test_draw(t_data *s_data);
#endif