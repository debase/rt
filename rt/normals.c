/*
** normals.c for normals in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 13:20:23 2013 luc sinet
** Last update Sun Mar 31 13:22:20 2013 luc sinet
*/

#include "main.h"
#include "light.h"

void	assign_normal1(t_lco *lpt, int type)
{
  if (type == 0)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = lpt->obj_coor[2];
    }
  else if (type == 1)
    {
      lpt->nvec[0] = 0;
      lpt->nvec[1] = 0;
      lpt->nvec[2] = 100;
    }
}

void	assign_normal2(t_lco *lpt, int type)
{
  if (type == 2)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = -0.6 * lpt->obj_coor[2];
    }
  else if (type == 3)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = 0;
    }
}