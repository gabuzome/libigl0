// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "colon.h"

#include <cstdio>

template <typename L,typename S,typename H,typename T>
IGL_INLINE void igl::colon(
  const L low, 
  const S step, 
  const H hi, 
  Eigen::Matrix<T,Eigen::Dynamic,1> & I)
{
  if(low < hi)
  {
    if(step < 0)
    {
      I.resize(0);
      //fprintf(stderr,"WARNING: colon() low(%g)<hi(%g) but step(%g)<0\n",
      //  (double)low,
      //  (double)hi,
      //  (double)step);
      //assert(false && "low<hi but step<0");
      return;
    }
  }
  if(low > hi)
  {
    if(step > 0)
    {
      I.resize(0);
      //fprintf(stderr,"Error: colon() low(%g)>hi(%g) but step(%g)>0\n",
      //  (double)low,
      //  (double)hi,
      //  (double)step);
      //assert(false && "low>hi but step<0");
      return;
    }
  }
  // resize output
  int n = floor(double((hi-low)/step))+1;
  I.resize(n);
  int i = 0;
  T v = (T)low;
  while((low==hi && (H)v==hi) || (low<hi && (H)v<=hi) || (low>hi && (H)v>=hi))
  {
    I(i) = v;
    v = v + (T)step;
    i++;
  }
  assert(i==n);
}

template <typename L,typename H,typename T>
IGL_INLINE void igl::colon(
  const L low, 
  const H hi, 
  Eigen::Matrix<T,Eigen::Dynamic,1> & I)
{
  return igl::colon(low,(T)1,hi,I);
}

template <typename T,typename L,typename H>
IGL_INLINE Eigen::Matrix<T,Eigen::Dynamic,1> igl::colon(
  const L low, 
  const H hi)
{
  Eigen::Matrix<T,Eigen::Dynamic,1> I;
  igl::colon(low,hi,I);
  return I;
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
// generated by autoexplicit.sh
template Eigen::Matrix<int, -1, 1, 0, -1, 1> igl::colon<int, int, int>(int, int);
// generated by autoexplicit.sh
template Eigen::Matrix<int, -1, 1, 0, -1, 1> igl::colon<int, int, long>(int, long);
template void igl::colon<int, long, int, int>(int, long, int, Eigen::Matrix<int, -1, 1, 0, -1, 1>&);
template void igl::colon<int, int, long, int>(int, int, long, Eigen::Matrix<int, -1, 1, 0, -1, 1>&);
template void igl::colon<int, long, int>(int, long, Eigen::Matrix<int, -1, 1, 0, -1, 1>&);
template void igl::colon<int, int, int>(int, int, Eigen::Matrix<int, -1, 1, 0, -1, 1>&);
#endif