
.. _program_listing_file_include_simplevectors_embed.hpp:

Program Listing for File embed.hpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_embed.hpp>` (``include/simplevectors/embed.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_EMBED_HPP_
   #define INCLUDE_SVECTOR_EMBED_HPP_
   
   #include <cmath>  // std::atan2, std::cos, std::sin, std::sqrt
   #include <string> // std::string
   
   namespace svector {
   struct Vec2D {
     Vec2D() : x(0), y(0){};
   
     Vec2D(const double x_other, const double y_other) : x(x_other), y(y_other) {}
   
     Vec2D(const Vec2D &other) : x(other.x), y(other.y) {}
   
     Vec2D(Vec2D &&) noexcept = default;
   
     Vec2D &operator=(const Vec2D &other) {
       x = other.x;
       y = other.y;
       return *this;
     }
   
     Vec2D &operator=(Vec2D &&) noexcept = default;
   
     virtual ~Vec2D() = default;
   
     Vec2D &operator+=(const Vec2D &other) {
       x += other.x;
       y += other.y;
       return *this;
     }
   
     Vec2D &operator-=(const Vec2D &other) {
       x -= other.x;
       y -= other.y;
       return *this;
     }
   
     Vec2D &operator*=(const double &other) {
       x *= other;
       y *= other;
       return *this;
     }
   
     Vec2D &operator/=(const double &other) {
       x /= other;
       y /= other;
       return *this;
     }
   
     double x; 
     double y; 
   };
   
   struct Vec3D {
     Vec3D() : x(0), y(x), z(0) {}
   
     Vec3D(const double x_other, const double y_other, const double z_other)
         : x(x_other), y(y_other), z(z_other) {}
   
     Vec3D(const Vec3D &other) : x(other.x), y(other.y), z(other.z) {}
   
     Vec3D(Vec3D &&) noexcept = default;
   
     Vec3D &operator=(const Vec3D &other) {
       x = other.x;
       y = other.y;
       z = other.z;
       return *this;
     }
   
     Vec3D &operator=(Vec3D &&) noexcept = default;
   
     virtual ~Vec3D() = default;
   
     Vec3D &operator+=(const Vec3D &other) {
       x += other.x;
       y += other.y;
       z += other.z;
       return *this;
     }
   
     Vec3D &operator-=(const Vec3D &other) {
       x -= other.x;
       y -= other.y;
       z -= other.z;
       return *this;
     }
   
     Vec3D &operator*=(const double &other) {
       x *= other;
       y *= other;
       z *= other;
       return *this;
     }
   
     Vec3D &operator/=(const double &other) {
       x /= other;
       y /= other;
       z /= other;
       return *this;
     }
   
     double x; 
     double y; 
     double z; 
   };
   
   inline std::string toString(const Vec2D &vec) {
     std::string s{"<"};
     s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ">";
     return s;
   }
   
   inline Vec2D operator+(const Vec2D &lhs, const Vec2D &rhs) {
     return Vec2D{lhs.x + rhs.x, lhs.y + rhs.y};
   }
   
   inline Vec2D operator-(const Vec2D &lhs, const Vec2D &rhs) {
     return Vec2D{lhs.x - rhs.x, lhs.y - rhs.y};
   }
   
   inline Vec2D operator-(const Vec2D &vec) { return Vec2D{-vec.x, -vec.y}; }
   
   inline Vec2D operator*(const Vec2D &lhs, const double rhs) {
     return Vec2D{lhs.x * rhs, lhs.y * rhs};
   }
   
   inline Vec2D operator/(const Vec2D &lhs, const double rhs) {
     return Vec2D{lhs.x / rhs, lhs.y / rhs};
   }
   
   inline bool operator==(const Vec2D &lhs, const Vec2D &rhs) {
     return lhs.x == rhs.x && lhs.y == rhs.y;
   }
   
   inline bool operator!=(const Vec2D &lhs, const Vec2D &rhs) {
     return !(lhs == rhs);
   }
   
   inline double dot(const Vec2D &lhs, const Vec2D &rhs) {
     return lhs.x * rhs.x + lhs.y * rhs.y;
   }
   
   inline double magn(const Vec2D &vec) {
     return std::sqrt(vec.x * vec.x + vec.y * vec.y);
   }
   
   inline double angle(const Vec2D &vec) { return std::atan2(vec.y, vec.x); }
   
   inline Vec2D normalize(const Vec2D &vec) { return vec / magn(vec); }
   
   inline Vec2D rotate(const Vec2D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)   -sin(ang) | |x|
     // | sin(ang)    cos(ang) | |y|
     //
   
     double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
     double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);
   
     return Vec2D{xPrime, yPrime};
   }
   
   inline std::string toString(const Vec3D &vec) {
     std::string s{"<"};
     s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ", " +
         std::to_string(vec.z) + ">";
     return s;
   }
   
   inline Vec3D operator+(const Vec3D &lhs, const Vec3D &rhs) {
     return Vec3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
   }
   
   inline Vec3D operator-(const Vec3D &lhs, const Vec3D &rhs) {
     return Vec3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
   }
   
   inline Vec3D operator-(const Vec3D &vec) {
     return Vec3D{-vec.x, -vec.y, -vec.z};
   }
   
   inline Vec3D operator*(const Vec3D &lhs, const double rhs) {
     return Vec3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
   }
   
   inline Vec3D operator/(const Vec3D &lhs, const double rhs) {
     return Vec3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
   }
   
   inline bool operator==(const Vec3D &lhs, const Vec3D &rhs) {
     return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
   }
   
   inline bool operator!=(const Vec3D &lhs, const Vec3D &rhs) {
     return !(lhs == rhs);
   }
   
   inline double dot(const Vec3D &lhs, const Vec3D &rhs) {
     return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
   }
   
   inline Vec3D cross(const Vec3D &lhs, const Vec3D &rhs) {
     double newx = lhs.y * rhs.z - lhs.z * rhs.y;
     double newy = lhs.z * rhs.x - lhs.x * rhs.z;
     double newz = lhs.x * rhs.y - lhs.y * rhs.x;
   
     return Vec3D{newx, newy, newz};
   }
   
   inline double magn(const Vec3D &vec) {
     return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
   }
   
   inline Vec3D normalize(const Vec3D &vec) { return vec / magn(vec); }
   
   inline double getAlpha(const Vec3D &vec) {
     return std::acos(vec.x / magn(vec));
   }
   
   inline double getBeta(const Vec3D &vec) { return std::acos(vec.y / magn(vec)); }
   
   inline double getGamma(const Vec3D &vec) {
     return std::acos(vec.z / magn(vec));
   }
   
   inline Vec3D rotateAlpha(const Vec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // |1   0           0     | |x|
     // |0  cos(ang)  −sin(ang)| |y|
     // |0  sin(ang)   cos(ang)| |z|
     //
   
     double xPrime = vec.x;
     double yPrime = vec.y * std::cos(ang) - vec.z * std::sin(ang);
     double zPrime = vec.y * std::sin(ang) + vec.z * std::cos(ang);
   
     return Vec3D{xPrime, yPrime, zPrime};
   }
   
   inline Vec3D rotateBeta(const Vec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)  0  sin(ang)| |x|
     // |   0       1      0   | |y|
     // |−sin(ang)  0  cos(ang)| |z|
     //
   
     double xPrime = vec.x * std::cos(ang) + vec.z * std::sin(ang);
     double yPrime = vec.y;
     double zPrime = -vec.x * std::sin(ang) + vec.z * std::cos(ang);
   
     return Vec3D{xPrime, yPrime, zPrime};
   }
   
   inline Vec3D rotateGamma(const Vec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // |cos(ang)  −sin(ang)  0| |x|
     // |sin(ang)  cos(ang)   0| |y|
     // |  0         0        1| |z|
     //
   
     double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
     double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);
     double zPrime = vec.z;
   
     return Vec3D{xPrime, yPrime, zPrime};
   }
   } // namespace svector
   
   #endif
