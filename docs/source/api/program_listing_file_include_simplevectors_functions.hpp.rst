
.. _program_listing_file_include_simplevectors_functions.hpp:

Program Listing for File functions.hpp
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_functions.hpp>` (``include/simplevectors/functions.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_FUNCTIONS_HPP_
   #define INCLUDE_SVECTOR_FUNCTIONS_HPP_
   
   #include <algorithm>        // std::min
   #include <array>            // std::array
   #include <cmath>            // std::atan2, std::acos, std::sqrt
   #include <cstddef>          // std::size_t
   #include <initializer_list> // std::initializer_list
   #include <vector>           // std::vector
   
   #include "core/vector.hpp"
   #include "core/vector2d.hpp"
   #include "core/vector3d.hpp"
   
   namespace svector {
   // COMBINER_PY_START
   
   template <std::size_t D, typename T>
   Vector<D, T> make_vector(std::array<T, D> array) {
     Vector<D, T> vec;
     for (std::size_t i = 0; i < D; i++) {
       vec[i] = array[i];
     }
   
     return vec;
   }
   
   template <std::size_t D, typename T>
   Vector<D, T> make_vector(std::vector<T> vector) {
     Vector<D, T> vec;
     for (std::size_t i = 0; i < std::min(D, vector.size()); i++) {
       vec[i] = vector[i];
     }
   
     return vec;
   }
   
   template <std::size_t D, typename T>
   Vector<D, T> make_vector(const std::initializer_list<T> args) {
     Vector<D, T> vec(args);
     return vec;
   }
   
   inline double x(const Vector2D &v) { return v[0]; }
   
   inline void x(Vector2D &v, const double x_value) { v[0] = x_value; }
   
   inline double x(const Vector3D &v) { return v[0]; }
   
   inline void x(Vector3D &v, const double x_value) { v[0] = x_value; }
   
   inline double y(const Vector2D &v) { return v[1]; }
   
   inline void y(Vector2D &v, const double y_value) { v[1] = y_value; }
   
   inline double y(const Vector3D &v) { return v[1]; }
   
   inline void y(Vector3D &v, const double y_value) { v[1] = y_value; }
   
   inline double z(const Vector3D &v) { return v[2]; }
   
   inline void z(Vector3D &v, const double z_value) { v[2] = z_value; }
   
   template <typename T, std::size_t D>
   inline T dot(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
     T result = 0;
   
     for (std::size_t i = 0; i < D; i++) {
       result += lhs[i] * rhs[i];
     }
   
     return result;
   }
   
   template <typename T, std::size_t D> inline T magn(const Vector<D, T> &v) {
     T sum_of_squares = 0;
   
     for (std::size_t i = 0; i < D; i++) {
       sum_of_squares += v[i] * v[i];
     }
   
     return std::sqrt(sum_of_squares);
   }
   
   template <typename T, std::size_t D>
   inline Vector<D, T> normalize(const Vector<D, T> &v) {
     return v / magn(v);
   }
   
   inline double angle(const Vector2D &v) { return std::atan2(y(v), x(v)); }
   
   inline Vector2D rotate(const Vector2D &v, const double ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)   -sin(ang) | |x|
     // | sin(ang)    cos(ang) | |y|
     //
   
     double xPrime = x(v) * std::cos(ang) - y(v) * std::sin(ang);
     double yPrime = x(v) * std::sin(ang) + y(v) * std::cos(ang);
   
     return Vector2D{xPrime, yPrime};
   }
   
   inline Vector3D cross(const Vector3D &lhs, const Vector3D &rhs) {
     double newx = y(lhs) * z(rhs) - z(lhs) * y(rhs);
     double newy = z(lhs) * x(rhs) - x(lhs) * z(rhs);
     double newz = x(lhs) * y(rhs) - y(lhs) * x(rhs);
   
     return Vector3D{newx, newy, newz};
   }
   
   inline double alpha(const Vector3D &v) { return std::acos(x(v) / magn(v)); }
   
   inline double beta(const Vector3D &v) { return std::acos(y(v) / magn(v)); }
   
   inline double gamma(const Vector3D &v) { return std::acos(z(v) / magn(v)); }
   
   inline Vector3D rotateAlpha(const Vector3D &v, const double &ang) {
     //
     // Rotation matrix:
     //
     // |1   0           0     | |x|
     // |0  cos(ang)  −sin(ang)| |y|
     // |0  sin(ang)   cos(ang)| |z|
     //
   
     double xPrime = x(v);
     double yPrime = y(v) * std::cos(ang) - z(v) * std::sin(ang);
     double zPrime = y(v) * std::sin(ang) + z(v) * std::cos(ang);
   
     return Vector3D{xPrime, yPrime, zPrime};
   }
   
   inline Vector3D rotateBeta(const Vector3D &v, const double &ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)  0  sin(ang)| |x|
     // |   0       1      0   | |y|
     // |−sin(ang)  0  cos(ang)| |z|
     //
   
     double xPrime = x(v) * std::cos(ang) + z(v) * std::sin(ang);
     double yPrime = y(v);
     double zPrime = -x(v) * std::sin(ang) + z(v) * std::cos(ang);
   
     return Vector3D{xPrime, yPrime, zPrime};
   }
   
   inline Vector3D rotateGamma(const Vector3D &v, const double &ang) {
     //
     // Rotation matrix:
     //
     // |cos(ang)  −sin(ang)  0| |x|
     // |sin(ang)  cos(ang)   0| |y|
     // |  0         0        1| |z|
     //
   
     double xPrime = x(v) * std::cos(ang) - y(v) * std::sin(ang);
     double yPrime = x(v) * std::sin(ang) + y(v) * std::cos(ang);
     double zPrime = z(v);
   
     return Vector3D{xPrime, yPrime, zPrime};
   }
   
   #ifndef SVECTOR_USE_CLASS_OPERATORS
   template <typename T, std::size_t D>
   inline Vector<D, T> operator+(const Vector<D, T> &lhs,
                                 const Vector<D, T> &rhs) {
     Vector<D, T> tmp;
     for (std::size_t i = 0; i < D; i++) {
       tmp[i] = lhs[i] + rhs[i];
     }
   
     return tmp;
   }
   
   template <typename T, std::size_t D>
   inline Vector<D, T> operator-(const Vector<D, T> &lhs,
                                 const Vector<D, T> &rhs) {
     Vector<D, T> tmp;
     for (std::size_t i = 0; i < D; i++) {
       tmp[i] = lhs[i] - rhs[i];
     }
   
     return tmp;
   }
   
   template <typename T, typename T2, std::size_t D>
   inline Vector<D, T> operator*(const Vector<D, T> &lhs, const T2 rhs) {
     Vector<D, T> tmp;
     for (std::size_t i = 0; i < D; i++) {
       tmp[i] = lhs[i] * rhs;
     }
   
     return tmp;
   }
   
   template <typename T, typename T2, std::size_t D>
   inline Vector<D, T> operator/(const Vector<D, T> &lhs, const T2 rhs) {
     Vector<D, T> tmp;
     for (std::size_t i = 0; i < D; i++) {
       tmp[i] = lhs[i] / rhs;
     }
   
     return tmp;
   }
   
   template <typename T, std::size_t D>
   inline bool operator==(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
     for (std::size_t i = 0; i < D; i++) {
       if (lhs[i] != rhs[i]) {
         return false;
       }
     }
   
     return true;
   }
   
   template <typename T, std::size_t D>
   inline bool operator!=(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
     return !(lhs == rhs);
   }
   #endif
   
   #ifdef SVECTOR_EXPERIMENTAL_COMPARE
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
   #endif
   // COMBINER_PY_END
   } // namespace svector
   
   #endif
