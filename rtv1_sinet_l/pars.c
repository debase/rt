/*
** pars.c for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 18:33:58 2013 luc sinet
** Last update Sun Mar 17 16:39:01 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "pars.h"
#include "get_next_line.h"

int	check_shape(char *line, int *accol, int nb_line)
{
  int	i;
  char	*shape[6];

  i = 0;
  shape[0] = "Sphere";
  shape[1] = "Cone";
  shape[2] = "Cylinder";
  shape[3] = "Plan";
  shape[4] = "Light";
  shape[5] = "{";
  shape[6] = "}";
  while (i < 7 && my_strcmp(shape[i], line) != 0)
    i++;
  if (i == 5)
    *accol += 1;
  else if (i == 6)
    *accol -= 1;
  if (*accol > 1 || *accol < 0 || (i < 5 && *accol != 0))
    {
      my_putstr("line ", 2);
      my_put_nbr(nb_line, 2);
      return (merror(", file is incorectly formatted\n", -1));
    }
  return (i < 4 ? 1 : (i == 4) ? 2 : 0);
}

int	get_size(char *name, t_obj *opt)
{
  if ((opt->fd = open(name, O_RDONLY)) == -1)
    return (merror("Could open the file\n", -2));
  while ((opt->line = get_next_line(opt->fd)))
    {
      opt->nb_line++;
      if ((opt->rv = check_shape(opt->line, &opt->accol, opt->nb_line)) == -1)
	return (-2);
      if (opt->rv == 1)
	++opt->nb_shape;
      else if (opt->rv == 2)
	++opt->nb_light;
      free(opt->line);
    }
  close(opt->fd);
  return ((opt->nb_shape == 0 || opt->accol != 0) ? -1 : opt->nb_shape + 1);
}

int	check_size(t_elem *tab)
{
  int	i;
  int	obj;

  obj = 0;
  while (tab[obj].type != -1)
    {
      i = 0;
      while (i < 3)
	{
	  if (tab[obj].angle[i] == IVAL || tab[obj].pos[i] == IVAL)
	    return (merror("Not enough informations specified\n", -1));
	  ++i;
	}
      if (tab[obj].type == 2 && tab[obj].angle[3] == IVAL)
	return (merror("Missing angle info for the Cone\n", -1));
      if (tab[obj].type != 1 && tab[obj].type == IVAL)
	return (merror("Missing size's information\n", -1));
      if (tab[obj].color == -1)
	tab[obj].color = 0xFFFFFF;
      obj++;
    }
  return (0);
}

int	pars(t_rt *rpt, char *fname)
{
  t_obj	opt;
  int	size;

  opt.accol = 0;
  opt.nb_line = 0;
  opt.nb_shape = 0;
  opt.nb_light = 0;
  if ((size = get_size(fname, &opt)) < 0)
    return (size == -2 ? -2 : merror("Enter at least one shape\n", -1));
  opt.nb_shape += 1;
  opt.nb_light += 1;
  if ((rpt->tab = malloc(sizeof(t_elem) * opt.nb_shape)) == NULL ||
      (rpt->ltab = malloc(sizeof(t_lig) * opt.nb_light)) == NULL)
    return (merror("Malloc failed\n", -1));
  init_elem(rpt->tab, &opt);
  init_light(rpt->ltab, &opt);
  if (fill_tab(&opt, rpt->tab, fname) == -1 ||
      fill_light(&opt, rpt->ltab, fname) == -1)
    return (-1);
  return (check_size(rpt->tab));
}
