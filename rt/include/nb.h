/*
** function_c2.h for function2 in /home/sinet_l//minishell
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Dec 13 13:57:35 2012 luc sinet
** Last update Fri Mar 15 01:37:27 2013 luc sinet
*/

#ifndef F2_H_
# define F2_H_

int	my_sgetnbr(char *s1, int *i);
int	my_getnbr(char *s1);
void	my_put_nbr(int nb, int fd);
double	my_fgetnbr(char *s1);
int	get_tab_size(char **tab);
int	my_getnbr_base(char *s1, char *base);

#endif
