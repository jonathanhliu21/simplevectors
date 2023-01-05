
.. _program_listing_file_include_simplevectors_embed.h:

Program Listing for File embed.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_embed.h>` (``include/simplevectors/embed.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_EMBED_HPP_
   #define INCLUDE_SVECTOR_EMBED_HPP_
   
   #include <math.h> // atan2, cos, sin, sqrt
   
   struct EmbVec2D {
     EmbVec2D() : x(0), y(0){};
   
     EmbVec2D(const double x_other, const double y_other)
         : x(x_other), y(y_other) {}
   
     EmbVec2D(const EmbVec2D &other) : x(other.x), y(other.y) {}
   
     EmbVec2D(EmbVec2D &&) noexcept = default;
   
     EmbVec2D &operator=(const EmbVec2D &other) {
       x = other.x;
       y = other.y;
       return *this;
     }
   
     EmbVec2D &operator=(EmbVec2D &&) noexcept = default;
   
     virtual ~EmbVec2D() = default;
   
     EmbVec2D &operator+=(const EmbVec2D &other) {
       x += other.x;
       y += other.y;
       return *this;
     }
   
     EmbVec2D &operator-=(const EmbVec2D &other) {
       x -= other.x;
       y -= other.y;
       return *this;
     }
   
     EmbVec2D &operator*=(const double &other) {
       x *= other;
       y *= other;
       return *this;
     }
   
     EmbVec2D &operator/=(const double &other) {
       x /= other;
       y /= other;
       return *this;
     }
   
     double x; 
     double y; 
   };
   
   struct EmbVec3D {
     EmbVec3D() : x(0), y(0), z(0) {}
   
     EmbVec3D(const double x_other, const double y_other, const double z_other)
         : x(x_other), y(y_other), z(z_other) {}
   
     EmbVec3D(const EmbVec3D &other) : x(other.x), y(other.y), z(other.z) {}
   
     EmbVec3D(EmbVec3D &&) noexcept = default;
   
     EmbVec3D &operator=(const EmbVec3D &other) {
       x = other.x;
       y = other.y;
       z = other.z;
       return *this;
     }
   
     EmbVec3D &operator=(EmbVec3D &&) noexcept = default;
   
     virtual ~EmbVec3D() = default;
   
     EmbVec3D &operator+=(const EmbVec3D &other) {
       x += other.x;
       y += other.y;
       z += other.z;
       return *this;
     }
   
     EmbVec3D &operator-=(const EmbVec3D &other) {
       x -= other.x;
       y -= other.y;
       z -= other.z;
       return *this;
     }
   
     EmbVec3D &operator*=(const double &other) {
       x *= other;
       y *= other;
       z *= other;
       return *this;
     }
   
     EmbVec3D &operator/=(const double &other) {
       x /= other;
       y /= other;
       z /= other;
       return *this;
     }
   
     double x; 
     double y; 
     double z; 
   };
   
   inline EmbVec2D operator+(const EmbVec2D &lhs, const EmbVec2D &rhs) {
     return EmbVec2D{lhs.x + rhs.x, lhs.y + rhs.y};
   }
   
   inline EmbVec2D operator-(const EmbVec2D &lhs, const EmbVec2D &rhs) {
     return EmbVec2D{lhs.x - rhs.x, lhs.y - rhs.y};
   }
   
   inline EmbVec2D operator-(const EmbVec2D &vec) {
     return EmbVec2D{-vec.x, -vec.y};
   }
   
   inline EmbVec2D operator*(const EmbVec2D &lhs, const double rhs) {
     return EmbVec2D{lhs.x * rhs, lhs.y * rhs};
   }
   
   inline EmbVec2D operator/(const EmbVec2D &lhs, const double rhs) {
     return EmbVec2D{lhs.x / rhs, lhs.y / rhs};
   }
   
   inline bool operator==(const EmbVec2D &lhs, const EmbVec2D &rhs) {
     return lhs.x == rhs.x && lhs.y == rhs.y;
   }
   
   inline bool operator!=(const EmbVec2D &lhs, const EmbVec2D &rhs) {
     return !(lhs == rhs);
   }
   
   inline double dot(const EmbVec2D &lhs, const EmbVec2D &rhs) {
     return lhs.x * rhs.x + lhs.y * rhs.y;
   }
   
   inline double magn(const EmbVec2D &vec) {
     return sqrt(vec.x * vec.x + vec.y * vec.y);
   }
   
   inline double angle(const EmbVec2D &vec) { return atan2(vec.y, vec.x); }
   
   inline EmbVec2D normalize(const EmbVec2D &vec) { return vec / magn(vec); }
   
   inline EmbVec2D rotate(const EmbVec2D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)   -sin(ang) | |x|
     // | sin(ang)    cos(ang) | |y|
     //
   
     double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
     double yPrime = vec.x * sin(ang) + vec.y * cos(ang);
   
     return EmbVec2D{xPrime, yPrime};
   }
   
   inline EmbVec3D operator+(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     return EmbVec3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
   }
   
   inline EmbVec3D operator-(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     return EmbVec3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
   }
   
   inline EmbVec3D operator-(const EmbVec3D &vec) {
     return EmbVec3D{-vec.x, -vec.y, -vec.z};
   }
   
   inline EmbVec3D operator*(const EmbVec3D &lhs, const double rhs) {
     return EmbVec3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
   }
   
   inline EmbVec3D operator/(const EmbVec3D &lhs, const double rhs) {
     return EmbVec3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
   }
   
   inline bool operator==(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
   }
   
   inline bool operator!=(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     return !(lhs == rhs);
   }
   
   inline double dot(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
   }
   
   inline EmbVec3D cross(const EmbVec3D &lhs, const EmbVec3D &rhs) {
     double newx = lhs.y * rhs.z - lhs.z * rhs.y;
     double newy = lhs.z * rhs.x - lhs.x * rhs.z;
     double newz = lhs.x * rhs.y - lhs.y * rhs.x;
   
     return EmbVec3D{newx, newy, newz};
   }
   
   inline double magn(const EmbVec3D &vec) {
     return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
   }
   
   inline EmbVec3D normalize(const EmbVec3D &vec) { return vec / magn(vec); }
   
   inline double getAlpha(const EmbVec3D &vec) { return acos(vec.x / magn(vec)); }
   
   inline double getBeta(const EmbVec3D &vec) { return acos(vec.y / magn(vec)); }
   
   inline double getGamma(const EmbVec3D &vec) { return acos(vec.z / magn(vec)); }
   
   inline EmbVec3D rotateAlpha(const EmbVec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // |1   0           0     | |x|
     // |0  cos(ang)  −sin(ang)| |y|
     // |0  sin(ang)   cos(ang)| |z|
     //
   
     double xPrime = vec.x;
     double yPrime = vec.y * cos(ang) - vec.z * sin(ang);
     double zPrime = vec.y * sin(ang) + vec.z * cos(ang);
   
     return EmbVec3D{xPrime, yPrime, zPrime};
   }
   
   inline EmbVec3D rotateBeta(const EmbVec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // | cos(ang)  0  sin(ang)| |x|
     // |   0       1      0   | |y|
     // |−sin(ang)  0  cos(ang)| |z|
     //
   
     double xPrime = vec.x * cos(ang) + vec.z * sin(ang);
     double yPrime = vec.y;
     double zPrime = -vec.x * sin(ang) + vec.z * cos(ang);
   
     return EmbVec3D{xPrime, yPrime, zPrime};
   }
   
   inline EmbVec3D rotateGamma(const EmbVec3D &vec, const double ang) {
     //
     // Rotation matrix:
     //
     // |cos(ang)  −sin(ang)  0| |x|
     // |sin(ang)  cos(ang)   0| |y|
     // |  0         0        1| |z|
     //
   
     double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
     double yPrime = vec.x * sin(ang) + vec.y * cos(ang);
     double zPrime = vec.z;
   
     return EmbVec3D{xPrime, yPrime, zPrime};
   }
   
   #endif
