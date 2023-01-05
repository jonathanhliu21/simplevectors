
.. _program_listing_file_include_simplevectors_core_units.hpp:

Program Listing for File units.hpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_core_units.hpp>` (``include/simplevectors/core/units.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_UNITS_HPP_
   #define INCLUDE_SVECTOR_UNITS_HPP_
   
   // all includes
   #include <algorithm> // std::min
   #include <array>     // std::array
   #include <cmath>     // std::acos, std::atan2, std::cos, std::sin, std::sqrt
   #include <cstddef>   // std::size_t
   #include <cstdint>   // std::int8_t
   #include <initializer_list> // std::initializer_list
   #include <string>           // std::string, std::to_string
   
   namespace svector {
   // COMBINER_PY_START
   enum AngleDir { ALPHA, BETA, GAMMA };
   // COMBINER_PY_END
   } // namespace svector
   
   #endif
