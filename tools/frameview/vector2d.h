/*
 * Copyright (c) 1999 - 2001, Artur Merke <amerke@ira.uka.de> 
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <math.h>
#include <iostream>
#include "angle.h"

/**
   The class Vector2d is used to represent 2 dimensional vectors. It supports
   (almost) all operations  you can perform with 2 dimensional vectors.
 */
class Vector2d {
 public:
  double   x ;
  double   y ;
  
  explicit Vector2d(double vx = 0.0,double vy = 0.0) { x= vx; y= vy;}
  void init_polar(double n, const Angle& a);
  
  void    operator +=(const Vector2d& v) ;
  void    operator -=(const Vector2d& v) ;
  void    operator *=(double a) ;
  void    operator /=(double a) ;

  double sqr_norm() const { return square(x)+square(y); }
  /// computes the euclidian norm of the vector
  double norm() const { return sqrt(sqr_norm()); }

  void normalize(double len = 1.0);

  /** computes the argument of this vector as it would be a complex number. In 
      other words it computes the angle between this vector and the vector
      (1,0). If this vector in the null vector a 0 is returned */
  Angle arg() const;
  
  friend Vector2d operator *(double a, const Vector2d& b);
  friend Vector2d operator +(const Vector2d& a, const Vector2d& b);
  friend Vector2d operator -(const Vector2d& a, const Vector2d& b);

  /** */
  //void normalize(double l = 1.0) ;
  
  /// computes the euclidian distance between this vector and the vector given as a parameter
  double distance(const Vector2d& orig) const;
  double sqr_distance(const Vector2d& orig) const;
  
  /// computes the angle between this vector and the vector given as a parameter
  Angle angle(const Vector2d& dir) const;
  
  /// rotates the vector by the given angle
  void rotate(const Angle& ang) ;
 private:
  double square(double v) const { return v * v; }
};


extern ostream& operator<< (ostream& o, const Vector2d& v) ;

#endif
