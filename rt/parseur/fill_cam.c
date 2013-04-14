/*
** fill_cam.c for fill_cam in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  1 21:38:56 2013 luc sinet
** Last update Fri Apr 12 17:36:11 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"

void	skip_adds(char *line, int *i)
{
  while (line[*i] == ',' || line[*i] == ';' || line[*i] == ' ')
    ++(*i);
}

void		get_cam_rot(t_cam *cpt, char *line)
{
  int		i;
  double	angle[3];

  i = 0;
  angle[0] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  angle[1] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  angle[2] = my_sgetnbr(line, &i);
  cpt->ccos[0] = cos(angle[0] * M_PI / 180);
  cpt->ccos[1] = cos(angle[1] * M_PI / 180);
  cpt->ccos[2] = cos(angle[2] * M_PI / 180);
  cpt->csin[0] = sin(angle[0] * M_PI / 180);
  cpt->csin[1] = sin(angle[1] * M_PI / 180);
  cpt->csin[2] = sin(angle[2] * M_PI / 180);
}

void	get_cam_coor(t_cam *cpt, char *line)
{
  int	i;

  i = 0;
  cpt->cx = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->cy = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->cz = my_sgetnbr(line, &i);
}

int	get_cam_carac(t_cam *cpt, int fd)
{
  int	i;
  char	*line;

  free((line = get_next_line(fd)));
  while (my_strcmp((line = get_next_line(fd)), "}") != 0)
    {
      i = 0;
      while (line[i] == ' ')
	++i;
      if (my_strncmp(&line[i], "Center = ", 9) == 0)
	get_cam_coor(cpt, &line[i + 9]);
      else if (my_strncmp(&line[i], "Angle = ", 8) == 0)
	get_cam_rot(cpt, &line[i + 8]);
      else
	{
	  my_putstr("Line ", 2);
	  my_putstr(line, 2);
	  return (merror(" is invalid\n", -1));
	}
      free(line);
    }
  return (0);
}

int	fill_cam(t_cam *cpt, char *name)
{
  int	fd;
  char	*line;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (merror("Couldn't open the file", -1));
  while ((line = get_next_line(fd)))
    {
      if (my_strcmp(line, "Cam") == 0 && get_cam_carac(cpt, fd) == -1)
	return (-1);
      free(line);
    }
  close (fd);
  return (0);
}