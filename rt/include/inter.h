/*
** inter.h for render in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 05:58:41 2013 luc sinet
** Last update Tue May 14 18:21:32 2013 etienne debas
*/

#ifndef REND_H_
# define REND_H_

double	sphere(double *cam, double *vec, t_obj *ept);
double	cone(double *cam, double *vec, t_obj *ept);
double	plan(double *cam, double *vec, t_obj *ept);
double	cylinder(double *cam, double *vec, t_obj *ept);
double	circle(double *cam, double *vec, t_obj *ept);
double	square(double *cam, double *vec, t_obj *ept);
double	triangle(double *cam, double *vec, t_obj *ept);
double	paraboloide(double *cam, double *vec, t_obj *ept);
double	hyperboloide(double *cam, double *vec, t_obj *ept);
double 	moebius(double *cam, double *vec, t_obj *ept);
double 	tangle(double *cam, double *vec, t_obj *ept);
double	tore(double *cam, double *vec, t_obj *obj);
double	solve_quad(double *coef, double *res);
double	solve_cube(double *coef, double *res);

#endif
