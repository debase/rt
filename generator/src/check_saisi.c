/*
** check_saisi.c for check_saisi in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Jun  8 18:11:42 2013 remi robert
** Last update Sun Jun  9 12:34:54 2013 remi robert
*/

#include "my_func.h"

int	check_string_format(char *str, char c)
{
  int	indice;
  int	ret;

  indice = -1;
  ret = 0;
  while (str[++indice] != '\0')
    if (c == str[indice])
      ret = 1;
  return (ret);
}

int	spe_check_saisi(t_param *param, char c)
{
  if (param->on_click == TRIANGLE || param->on_click == SQUARE)
    if (param->saisi.type == 11 || param->saisi.type == 12)
      return (check_string_format("0123456789-.,", c));
  if (param->on_click == HYPERBOLOIDE || param->on_click == PARABOLOIDE)
    if (param->saisi.type == 12)
      return (check_string_format("0123456789-.", c));
  return (2);
}

int	check_saisi(t_param *param, char c)
{
  int	ret;

  if ((ret = spe_check_saisi(param, c)) != 2)
    return (ret);
  if (param->saisi.type == 1 || param->saisi.type == 4 ||
      param->saisi.type == 11 || param->saisi.type == 12)
    return (check_string_format("0123456789-", c));
  if (param->saisi.type == 3 || param->saisi.type == 10)
    return (check_string_format("0123456789-,", c));
  if (param->saisi.type == 5 || param->saisi.type == 6 ||
      param->saisi.type == 9)
    return (check_string_format("0123456789-.", c));
  if (param->saisi.type == 2)
    return (check_string_format("xABCDEFabcdef0123456789", c));
  return (1);
}
