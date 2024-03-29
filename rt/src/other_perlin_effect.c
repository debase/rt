/*
** other_perlin_effect.c for other_perlin_effect in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 18:38:43 2013 luc sinet
** Last update Sun Jun  9 04:00:01 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "perlin.h"
#include "pp_image.h"
#include "pars.h"
#include "change_color.h"

unsigned int	perlin_disco(double *inter, unsigned char *color_obj,
			     UNUSED t_perl *ppt, double frequency)
{
  double	pn_r;
  double	pn_v;
  double	pn_b;

  frequency *= 2.0;
  pn_r = get_perlin(inter[0] * 0.1 * frequency * 7,
                    inter[1] * 0.1 * frequency * 7,
                    inter[2] * 0.1 * frequency * 7);
  pn_v = get_perlin(inter[0] * 0.3 * frequency * 7,
                    inter[1] * 0.3 * frequency * 7,
                    inter[2] * 0.3 * frequency * 7);
  pn_b = get_perlin(inter[0] * 0.5 * frequency * 7,
                    inter[1] * 0.5 * frequency * 7,
                    inter[2] * 0.5 * frequency * 7);
  color_obj[0] = LIMIT(pn_r * 200 + 50, 0, 255);
  color_obj[1] = LIMIT(pn_v * 200 + 50, 0, 255);
  color_obj[2] = LIMIT(pn_b * 200 + 100, 0, 255);
  return (recomp_color(color_obj));
}

unsigned int	perlin_marble(double *inter, unsigned char *color_obj,
			      t_perl *ppt, UNUSED double frequency)
{
  int		level;

  level = 1;
  ppt->pn = 0;
  while (level < 10)
    {
      ppt->pn += (1.0f / level)
                 * (get_perlin(level * 0.2 * inter[0],
			       level * 0.2 * inter[1],
			       level * 0.2 * inter[2]));
      level++;
    }
  ppt->pn = 0.5 * sin((inter[0] + inter[1]) * 0.1 + ppt->pn) + 0.5;
  color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  return (recomp_color(color_obj));
}

unsigned int	perlin_zebra(double *inter, unsigned char *color_obj,
			     t_perl *ppt, UNUSED double frequency)
{
  ppt->pn = cos(get_perlin(0.02 * inter[0],
                           0.02 * inter[1],
                           0.02 * inter[2]) * 70);
  color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  return (recomp_color(color_obj));
}
