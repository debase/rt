/*
** pp_image.c for pp in /home/sinet_l//igraph
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Nov 12 11:23:01 2012 luc sinet
** Last update Thu Mar 14 23:12:59 2013 luc sinet
*/

#include "mlx.h"
#include "pp_image.h"

int	my_pixel_put_to_image(int x, int y, t_par *par, unsigned int color)
{
  unsigned int	x_pos;
  unsigned int	color_val;

  x_pos = y * par->sizeline / 4 + x;
  color_val = mlx_get_color_value(par->mlx_ptr, color);
  if ((x >= 0 && y >= 0) && (x <= WINX && y <= WINY) && x_pos >= 0)
    ((int*)par->data)[x_pos] = color_val;
  return (0);
}
