#ifndef IGL_EDGE_LENGTHS_H
#define IGL_EDGE_LENGTHS_H
#include "igl_inline.h"

#include <Eigen/Dense>

namespace igl
{
  // Constructs a list of lengths of edges opposite each index in a face
  // (triangle) list
  // Templates:
  //   DerivedV derived from vertex positions matrix type: i.e. MatrixXd
  //   DerivedF derived from face indices matrix type: i.e. MatrixXi
  //   DerivedL derived from edge lengths matrix type: i.e. MatrixXd
  // Inputs:
  //   V  eigen matrix #V by 3
  //   F  #F by 3 list of mesh faces (must be triangles)
  // Outputs:
  //   E #E by 2 list of edges in no particular order
  //
  // See also: adjacency_matrix
  template <typename DerivedV, typename DerivedF, typename DerivedL>
  IGL_INLINE void edge_lengths(
    const Eigen::PlainObjectBase<DerivedV>& V,
    const Eigen::PlainObjectBase<DerivedF>& F,
    Eigen::PlainObjectBase<DerivedL>& L);
}

#ifdef IGL_HEADER_ONLY
#  include "edge_lengths.cpp"
#endif

#endif

