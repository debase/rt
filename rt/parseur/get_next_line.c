/*
** get_next.c for get_next in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 19 11:20:55 2013 luc sinet
** Last update Fri Apr 12 14:43:48 2013 Adrien Della Maggiora
*/

#include "../include/get_next_line.h"

char	*spe_strcat(char *dest, char *src, char opt)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  if (opt == 1)
    while (dest[x])
      x++;
  while (src[i])
    dest[x++] = src[i++];
  dest[x] = '\0';
  return (dest);
}

char	*get_realloc(char *line)
{
  char	*new_line;
  int	sizel;

  sizel = 0;
  while (line[sizel])
    sizel++;
  if ((new_line = malloc(sizel + SIZE + 1)) == NULL)
    return (NULL);
  spe_strcat(new_line, line, 0);
  free(line);
  return (new_line);
}

int	check_line(char *line, char *buf)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (line[i] && line[i] != '\n')
    i++;
  if (line[i] == '\n')
    {
      line[i] = '\0';
      i = 0;
      while (buf[i] && buf[i] != '\n')
	i++;
      if (buf[i] == '\n')
	i++;
      while (buf[i])
	buf[x++] = buf[i++];
      buf[x] = '\0';
      return (1);
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buf[SIZE + 1];
  char		*line;
  int		s_read;

  if ((line = malloc(SIZE + 1)) == NULL)
    return (NULL);
  spe_strcat(line, buf, 0);
  while (check_line(line, buf) == 0)
    {
      if ((s_read = read(fd, buf, SIZE)) <= 0)
	{
	  if (s_read == 0 && line[0])
	    {
	      buf[0] = '\0';
	      return (line);
	    }
	  free(line);
	  return (NULL);
	}
      buf[s_read] = '\0';
      if (line[0] != '\0' && (line = get_realloc(line)) == NULL)
	return (NULL);
      spe_strcat(line, buf, 1);
    }
  return (line);
}
