
.. _program_listing_file_include_simplevectors_core_vector3d.hpp:

Program Listing for File vector3d.hpp
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_core_vector3d.hpp>` (``include/simplevectors/core/vector3d.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_VECTOR3D_HPP_
   #define INCLUDE_SVECTOR_VECTOR3D_HPP_
   
   #include "units.hpp"  // svector::AngleDir
   #include "vector.hpp" // svector::Vector
   
   namespace svector {
   // COMBINER_PY_START
   
   typedef Vector<3> Vec3_; 
   
   class Vector3D : public Vec3_ {
   public:
     using Vec3_::Vector;
   
     Vector3D(const double x, const double y, const double z) {
       this->m_components[0] = x;
       this->m_components[1] = y;
       this->m_components[2] = z;
     }
   
     Vector3D(const Vec3_ &other) {
       this->m_components[0] = other[0];
       this->m_components[1] = other[1];
       this->m_components[2] = other[2];
     }
   
     double x() const { return this->m_components[0]; }
   
     void x(const double &newX) { this->m_components[0] = newX; }
   
     double y() const { return this->m_components[1]; }
   
     void y(const double &newY) { this->m_components[1] = newY; }
   
     double z() const { return this->m_components[2]; }
   
     void z(const double &newZ) { this->m_components[2] = newZ; }
   
     Vector3D cross(const Vector3D &other) const {
       double newx = this->y() * other.z() - this->z() * other.y();
       double newy = this->z() * other.x() - this->x() * other.z();
       double newz = this->x() * other.y() - this->y() * other.x();
   
       return Vector3D{newx, newy, newz};
     }
   
     template <typename T> T componentsAs() const {
       return T{this->x(), this->y(), this->z()};
     }
   
     template <typename T> T anglesAs() const {
       return T{this->getAlpha(), this->getBeta(), this->getGamma()};
     }
   
     template <AngleDir D> double angle() const {
       switch (D) {
       case ALPHA:
         return this->getAlpha();
       case BETA:
         return this->getBeta();
       default:
         return this->getGamma();
       }
     }
   
     template <AngleDir D> Vector3D rotate(const double &ang) const {
       switch (D) {
       case ALPHA:
         return this->rotateAlpha(ang);
       case BETA:
         return this->rotateBeta(ang);
       default:
         return this->rotateGamma(ang);
       }
     };
   
   private:
     double getAlpha() const { return std::acos(this->x() / this->magn()); }
   
     double getBeta() const { return std::acos(this->y() / this->magn()); }
   
     double getGamma() const { return std::acos(this->z() / this->magn()); }
   
     Vector3D rotateAlpha(const double &ang) const {
       double xPrime = this->x();
       double yPrime = this->y() * std::cos(ang) - this->z() * std::sin(ang);
       double zPrime = this->y() * std::sin(ang) + this->z() * std::cos(ang);
   
       return Vector3D{xPrime, yPrime, zPrime};
     }
   
     Vector3D rotateBeta(const double &ang) const {
       double xPrime = this->x() * std::cos(ang) + this->z() * std::sin(ang);
       double yPrime = this->y();
       double zPrime = -this->x() * std::sin(ang) + this->z() * std::cos(ang);
   
       return Vector3D{xPrime, yPrime, zPrime};
     }
   
     Vector3D rotateGamma(const double &ang) const {
       double xPrime = this->x() * std::cos(ang) - this->y() * std::sin(ang);
       double yPrime = this->x() * std::sin(ang) + this->y() * std::cos(ang);
       double zPrime = this->z();
   
       return Vector3D{xPrime, yPrime, zPrime};
     }
   };
   // COMBINER_PY_END
   } // namespace svector
   
   #endif
