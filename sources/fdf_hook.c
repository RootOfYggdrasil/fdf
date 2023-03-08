
#include "../includes/fdf.h"

int key_hook(int key_code, t_data *meta)
{
  if (meta)
    putchar('o');
  if (key_code == KEY_W)
		putchar('w');
  if (key_code == KEY_ESCAPE)
		exit(0);
  if (key_code == KEY_0)
		putchar('\n');
  if (key_code == KEY_1)
  {
    putchar('0' + (int)(float)(2.6));
  }
  
  return 0;
}