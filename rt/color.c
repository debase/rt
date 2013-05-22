/*
** color.c for color in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Mon May 13 10:15:38 2013 Adrien Della Maggiora
** Last update Wed May 22 11:31:41 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "bmp_loader.h"
#include "change_color.h"

void		texture_color(t_obj *obj, double u, double v)
{
  int		color;

  printf("U = %f, V = %f\n", u, v);
  if (v < ZERO)
    v = (-v);
  if (u < ZERO)
    u = (-u);
  if (v >= obj->texture->height)
    v = v - ((int)((int)v / obj->texture->height) * obj->texture->height);
  if (u >= obj->texture->widht)
    u = u - ((int)((int)u / obj->texture->widht) * obj->texture->widht);
  color = (u + (v * obj->texture->widht));
  printf("U = %f, V = %f, nbColor = %d\n", u, v, color);
  obj->color[0] = obj->texture->texture[color - (color % 3)];
  obj->color[1] = obj->texture->texture[color + 1 - (color % 3)];
  obj->color[2] = obj->texture->texture[color + 2 - (color % 3)];
  printf("Color = %X | nb = %d\n\n", recomp_color(obj->color), color);
}

void		texture_sphere(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	lat[3];
  double	lon[3];
  double	vec[3];
  double	theta;
  double	v;
  double	r;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  unitaire(lpt->nvec);
  lat[0] = 0;
  lat[1] = 1;
  lat[2] = 0;
  lon[0] = 1;
  lon[1] = 0;
  lon[2] = 0;
  r = acos(-scale(lat, lpt->nvec));
  v = r / M_PI;
  theta = (acos(scale(lon, lpt->nvec)) / sin(r)) * (0.5 / M_PI);
  vec_mult(lon, lat, vec);
  vec[0] = -(lat[1] * lon[2] - lat[2] * lon[1]);
  vec[1] = -(lat[2] * lon[0] - lat[0] * lon[2]);
  vec[2] = -(lat[0] * lon[1] - lat[1] * lon[0]);
  printf("%f | %f | %f, %f, %f\n", scale(vec, lpt->nvec), theta, vec[0], vec[1], vec[2]);
  if (scale(vec, lpt->nvec) >= ZERO)
    texture_color(obj, theta, v);
  else 
    texture_color(obj, 1 - theta, v);
}

void	texture_plan(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	vec[3];
  double	dist;
  double	nvec[3];
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  unitaire(lpt->nvec);
  nvec[0] = lpt->nvec[1];
  nvec[1] = lpt->nvec[2];
  nvec[2] = -lpt->nvec[0];
  vec[0] = nvec[1] * lpt->nvec[2] - nvec[2] * lpt->nvec[1];
  vec[1] = nvec[2] * lpt->nvec[0] - nvec[0] * lpt->nvec[2];
  vec[2] = nvec[0] * lpt->nvec[1] - nvec[1] * lpt->nvec[0];
  u = lpt->obj_coor[0];/* scale(lpt->obj_coor, nvec); */
  v = lpt->obj_coor[1];/* scale(lpt->obj_coor, vec); */
  texture_color(obj, u, v);
}

void	get_color_texture(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  if (obj->texture == NULL)
    return ;
  if (obj->type == 1)
    texture_plan(obj, lpt, k, rpt);
  else if (obj->type == 0)
    texture_sphere(obj, lpt, k, rpt);
}
