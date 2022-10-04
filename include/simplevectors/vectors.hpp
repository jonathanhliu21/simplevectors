#ifndef INCLUDE_SVECTOR_VECTOR_HPP_
#define INCLUDE_SVECTOR_VECTOR_HPP_

#include "core/units.hpp"
#include "core/vector.hpp"
#include "core/vector2d.hpp"
#include "core/vector3d.hpp"
#include "utils.hpp"
#include "utils_stl.hpp"

// COMBINER_PY_START
#ifdef SVECTOR_EXPERIMENTAL_FEATURES
namespace svector {
template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator<(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) < 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator>(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) > 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator<=(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) <= 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator>=(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) >= 0;
}
} // namespace svector
#endif
// COMBINER_PY_END

#endif
