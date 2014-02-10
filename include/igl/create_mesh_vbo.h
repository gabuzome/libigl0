// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_CREATE_MESH_VBO_H
#define IGL_CREATE_MESH_VBO_H
#ifndef IGL_NO_OPENGL
#include "igl_inline.h"
// NOTE: It wouldn't be so hard to template this using Eigen's templates

#include <Eigen/Core>

#include "OpenGL_convenience.h"

// Create a VBO (Vertex Buffer Object) for a mesh. Actually two VBOs: one 
// GL_ARRAY_BUFFER for the vertex positions (V) and one
// GL_ELEMENT_ARRAY_BUFFER for the triangle indices (F)
namespace igl
{

  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  // Outputs:
  //   V_vbo_id  buffer id for vertex positions
  //   F_vbo_id  buffer id for face indices
  //
  // NOTE: when using glDrawElements VBOs for V and F using MatrixXd and
  // MatrixXi will have types GL_DOUBLE and GL_UNSIGNED_INT respectively
  //
  IGL_INLINE void create_mesh_vbo(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    GLuint & V_vbo_id,
    GLuint & F_vbo_id);

  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  //   N  #V by 3 eigen Matrix of mesh vertex 3D normals
  // Outputs:
  //   V_vbo_id  buffer id for vertex positions
  //   F_vbo_id  buffer id for face indices
  //   N_vbo_id  buffer id for vertex positions
  IGL_INLINE void create_mesh_vbo(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const Eigen::MatrixXd & N,
    GLuint & V_vbo_id,
    GLuint & F_vbo_id,
    GLuint & N_vbo_id);

}

#ifdef IGL_HEADER_ONLY
#  include "create_mesh_vbo.cpp"
#endif

#endif
#endif