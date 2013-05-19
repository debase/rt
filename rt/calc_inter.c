/*
** calc_inter.c for inter in /home/sinet_l//rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 20 16:55:47 2013 luc sinet
** Last update Sun May 19 22:42:23 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "change_color.h"
#include "light.h"
#include "supersampling.h"

void		calc_inter(t_rt *rpt, double *kmin)
{
  double	k;
  int		i;

  i = 0;
  *kmin = -1;
  while (rpt->obj[i].type >= 0 && rpt->obj[i].type < 11)
    {
      k = move_cam(rpt, rpt->vpt, rpt->cpt, rpt->obj[i]);
      if (k > ZERO && (k < *kmin || *kmin == -1))
	{
	  *kmin = k;
	  rpt->obj_num = i;
	}
      ++i;
    }
}

unsigned int	get_pixel_color(t_rt *rpt, int *pos)
{
  double	k;
  double	distance;
  t_lco		lpt;
  unsigned int	color;
  unsigned char	save_color[3];

  color = 0x000000;
  calc_inter(rpt, &k);
  if (rpt->obj[rpt->obj_num].perlin != -1)
    save_color_obj(rpt->obj[rpt->obj_num].color, save_color);
  distance = 200 * FOG_DIST;
  if (k != -1 && rpt->light[0].on == 1)
    {
      if (rpt->obj[rpt->obj_num].perlin != -1)
	color = perlin(pos, rpt->obj[rpt->obj_num].color,
		       rpt->obj[rpt->obj_num].perlin);
      get_color_texture(&rpt->obj[rpt->obj_num], &lpt, k, rpt);
      color = get_light(rpt, k, &rpt->obj[rpt->obj_num], &lpt);
      color = reflection(rpt, &lpt, color, k);
      color = transparency(rpt, &lpt, color, k);
      distance = rpt->obj[rpt->obj_num].dist;
    }
  color = apply_fog(color, rpt->opt->fog, distance);
  if (rpt->obj[rpt->obj_num].perlin != -1)
    reinit_color(rpt->obj[rpt->obj_num].color, save_color);
  return (color);
}

void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt)
{
  t_samp	spt;
  unsigned int	color;
  int		pos[2];

  pos[1] = 0;
  assign_function(rpt);
  if ((spt.pixel = malloc(sizeof(int) * rpt->opt->aa)) == NULL)
    return ;
  rpt->obj_num = 0;
  while (pos[1] < WINY)
    {
      pos[0] = 0;
      while (pos[0] < WINX)
	{
	  new_coor(vpt, cpt, pos[0], pos[1]);
	  color = get_pixel_color(rpt, pos);
	  my_pixel_put_to_image(pos[0], pos[1], ppt, color);
	  fill_img_param(pos, color, rpt, ppt);
	  ++pos[0];
	}
      print_i(ppt);
      ++pos[1];
    }
  /* exit(0); */
  detect_edge(rpt, ppt);
  /* apply_supersampling(rpt, ppt, &spt); */
}
