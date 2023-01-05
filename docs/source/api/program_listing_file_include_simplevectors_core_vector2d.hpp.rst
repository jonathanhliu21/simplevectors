
.. _program_listing_file_include_simplevectors_core_vector2d.hpp:

Program Listing for File vector2d.hpp
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_core_vector2d.hpp>` (``include/simplevectors/core/vector2d.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_VECTOR2D_HPP_
   #define INCLUDE_SVECTOR_VECTOR2D_HPP_
   
   #include "vector.hpp" // svector::Vector
   
   namespace svector {
   // COMBINER_PY_START
   
   typedef Vector<2> Vec2_; 
   
   class Vector2D : public Vec2_ {
   public:
     using Vec2_::Vector;
   
     Vector2D(const double x, const double y) {
       this->m_components[0] = x;
       this->m_components[1] = y;
     }
   
     Vector2D(const Vec2_ &other) {
       this->m_components[0] = other[0];
       this->m_components[1] = other[1];
     }
   
     double x() const { return this->m_components[0]; }
   
     void x(const double &newX) { this->m_components[0] = newX; }
   
     double y() const { return this->m_components[1]; }
   
     void y(const double &newY) { this->m_components[1] = newY; }
   
     double angle() const { return std::atan2(this->y(), this->x()); }
   
     Vector2D rotate(const double ang) const {
       //
       // Rotation matrix:
       //
       // | cos(ang)   -sin(ang) | |x|
       // | sin(ang)    cos(ang) | |y|
       //
   
       double xPrime = this->x() * std::cos(ang) - this->y() * std::sin(ang);
       double yPrime = this->x() * std::sin(ang) + this->y() * std::cos(ang);
   
       return Vector2D{xPrime, yPrime};
     }
   
     template <typename T> T componentsAs() const {
       return T{this->x(), this->y()};
     }
   };
   // COMBINER_PY_END
   } // namespace svector
   
   #endif
