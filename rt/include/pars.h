/*
** pars.h for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 15:55:16 2013 luc sinet
** Last update Sun Apr 14 00:01:22 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

# define LIMIT(x, n1, n2) (x < n1) ? n1 : (x > n2) ? n2 : x
# define BOOL(x) (x >= 1) ? 1 : 0
# define T_ACCOL(x) (x == 7) ? 1 : (x == 8) ? -1 : 0

typedef struct	s_obj	t_obj;
typedef struct	s_lig	t_lig;
typedef struct	s_cam	t_cam;

typedef struct	s_pars
{
  char		*line;
  int		accol;
  int		fd;
  int		rv;
  int		nb_line;
  int		nb_shape;
  int		nb_light;
  int		nb_cam;
  int		nb_opt;
}		t_pars;

int	other_opt(char *line, t_obj *ept);
void	fill_angle(t_obj *ept, char *line);
void	fill_center(t_obj *ept, char *line);
void	init_light(t_lig *ltab, t_pars *opt);
void	init_elem(t_obj *tab, t_pars *opt);
void	init_nb_obj(t_pars *opt);
int	fill_tab(t_pars *opt, t_obj *tab, char *name);
int	fill_light(t_pars *opt, t_lig *ltab, char *name);
int	fill_cam(t_cam *cpt, char *name);
void	fill_pert(char *line, double *pert);
int	fill_opt(t_rt *rpt, char *fname);
int	pars(t_rt *rpt, char *fname, t_cam *cpt);
void	fill_limits(char *line, double *limit);
void	get_color(char *line, unsigned char *color);
void	init_shapes(char **shape);
void	init_cam(t_cam *cpt);
void	skip_adds(char *line, int *i);
int	light_carac(char *line, t_lig *ltab, int i);

#endif