/*
** lightning.h for light in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 13:09:39 2013 luc sinet
** Last update Mon Apr 22 15:31:39 2013 luc sinet
*/

#ifndef LIG_H_
# define LIG_H_

# define NX(type, xp) (type == 1) ? 0.0 : xp;
# define NY(type, yp) (type == 1) ? 0.0 : yp;
# define NZ(t, c, zp) (t == 1) ? 100 : (t == 2) ? (-c * zp) : (t == 3) ? 0 : zp
# define MAX(x, y) (x > y) ? x : y
# define LIMIT(x, n1, n2) (x < n1) ? n1 : (x > n2) ? n2 : x
# define DISTM 200000.0
# define SPE_SIZE 1

typedef struct	s_lco
{
  double	obj_coor[3];
  double	nvec[3];
  double	lvec[3];
  double	rvec[3];
  double	mx_cos;
  double	spec;
  unsigned char	c_color[3];
}		t_lco;

double		point_distance(double *p1, double *p2);
double		apply_distance(t_lco *lpt, t_lig *obj, double cosa);
void		assign_normal1(t_lco *lpt, int type);
void		assign_normal2(t_lco *lpt, int type);
void		apply_light_color(unsigned char *col_o, unsigned char *col_l,
				  double lg_i);
void		get_obj_distance(t_obj *obj, double *cpos, double *hit);
double		get_angle_specular(double lvec[3], double nvec[3], t_lco *lpt);
void		*apply_ambient(t_lig *light, unsigned char *color,
			       double *max_cos);
double		get_light_vector(t_lco *lpt, double *spot_p);
t_lig		move_light(double *pos, double intensity,
			   unsigned char *lcolor);
void		get_light_color(t_lig *light, t_lco *lpt, t_rt *rpt);
int		shadows(t_rt *rpt, double *cpos, double *lpos, double *opos);
void		get_impact(double *imp, double *cam, double k, double *vec);
double		vec_norme(double *vector);
void		sphere_normal(double *nvec, double *obj_coor, double *pert);
void		plan_normal(double *nvec, double *obj_coor, double *pert);
void		cone_normal(double *nvec, double *obj_coor, double *pert);
void		cylinder_normal(double *nvec, double *obj_coor, double *pert);
void		unitaire(double *vec);
double		norme_vec(double *vec);
double		scale(double *vec1, double *vec2);
double		cos_vector(double *vec1, double *vec2);

#endif
