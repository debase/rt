/*
** light_carac.c for light in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 28 17:07:41 2013 luc sinet
** Last update Mon Apr  1 20:48:48 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "nb.h"

int	light_carac(char *line, t_lig *ltab, int i)
{
  if (my_strncmp("intensity = ", line, 12) == 0)
    ltab[i].intensity = LIMIT(my_fgetnbr(&line[12]), 0, 1);
  else if (my_strncmp("Color = ", line, 8) == 0 &&
	   my_strlen(&line[8]) > 3)
    get_color(&line[10], ltab->lcolor);
  else if (my_strncmp("Ambiant = ", line, 10) == 0)
    ltab[i].ambiant = BOOL(my_getnbr(&line[10]));
  else
    return (-1);
  return (0);
}
