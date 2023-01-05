
.. _program_listing_file_include_simplevectors_core_vector.hpp:

Program Listing for File vector.hpp
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_simplevectors_core_vector.hpp>` (``include/simplevectors/core/vector.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef INCLUDE_SVECTOR_BASEVECTOR_HPP_
   #define INCLUDE_SVECTOR_BASEVECTOR_HPP_
   
   #include "units.hpp" // all includes
   
   namespace svector {
   // COMBINER_PY_START
   template <std::size_t D, typename T = double> class Vector {
   public:
   #ifdef SVECTOR_EXPERIMENTAL_COMPARE
     template <std::size_t D1, std::size_t D2, typename T1, typename T2>
     friend bool operator<(const Vector<D1, T1> &, const Vector<D2, T2> &);
   
     template <std::size_t D1, std::size_t D2, typename T1, typename T2>
     friend bool operator<=(const Vector<D1, T1> &, const Vector<D2, T2> &);
   
     template <std::size_t D1, std::size_t D2, typename T1, typename T2>
     friend bool operator>(const Vector<D1, T1> &, const Vector<D2, T2> &);
   
     template <std::size_t D1, std::size_t D2, typename T1, typename T2>
     friend bool operator>=(const Vector<D1, T1> &, const Vector<D2, T2> &);
   #endif
   
     typedef
         typename std::array<T, D>::iterator iterator; 
     typedef typename std::array<T, D>::const_iterator
         const_iterator; 
     typedef typename std::array<T, D>::reverse_iterator
         reverse_iterator; 
     typedef typename std::array<T, D>::const_reverse_iterator
         const_reverse_iterator; 
   
     Vector() { this->m_components.fill(0); }
   
     Vector(const std::initializer_list<T> args) {
       // in case length of args < dimensions
       this->m_components.fill(0);
   
       std::size_t counter = 0;
       for (auto num : args) {
         if (counter >= D) {
           break;
         }
   
         this->m_components[counter] = num;
         counter++;
       }
     }
   
     Vector(const Vector<D, T> &other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] = other[i];
       }
     }
   
     Vector(Vector<D, T> &&) noexcept = default;
   
     Vector<D, T> &operator=(const Vector<D, T> &other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] = other[i];
       }
   
       return *this;
     }
   
     Vector<D, T> &operator=(Vector<D, T> &&) noexcept = default;
   
     virtual ~Vector() = default;
   
     virtual std::string toString() const {
       std::string str = "<";
       for (std::size_t i = 0; i < D - 1; i++) {
         str += std::to_string(this->m_components[i]);
         str += ", ";
       }
   
       str += std::to_string(this->m_components[D - 1]);
       str += ">";
   
       return str;
     }
   
   #ifdef SVECTOR_USE_CLASS_OPERATORS
     Vector<D, T> operator+(const Vector<D, T> &other) const {
       Vector<D, T> tmp;
       for (std::size_t i = 0; i < D; i++) {
         tmp[i] = this->m_components[i] + other[i];
       }
   
       return tmp;
     }
   
     Vector<D, T> operator-(const Vector<D, T> &other) const {
       Vector<D, T> tmp;
       for (std::size_t i = 0; i < D; i++) {
         tmp[i] = this->m_components[i] - other[i];
       }
   
       return tmp;
     }
   
     Vector<D, T> operator*(const T other) const {
       Vector<D, T> tmp;
       for (std::size_t i = 0; i < D; i++) {
         tmp[i] = this->m_components[i] * other;
       }
   
       return tmp;
     }
   
     Vector<D, T> operator/(const T other) const {
       Vector<D, T> tmp;
       for (std::size_t i = 0; i < D; i++) {
         tmp[i] = this->m_components[i] / other;
       }
   
       return tmp;
     }
   
     bool operator==(const Vector<D, T> &other) const {
       for (std::size_t i = 0; i < D; i++) {
         if (this->m_components[i] != other[i]) {
           return false;
         }
       }
   
       return true;
     }
   
     bool operator!=(const Vector<D, T> &other) const {
       return !((*this) == other);
     }
   #endif
   
     Vector<D, T> operator-() const {
       Vector<D, T> tmp;
       for (std::size_t i = 0; i < D; i++) {
         tmp[i] = -this->m_components[i];
       }
   
       return tmp;
     }
   
     Vector<D, T> &operator+=(const Vector<D, T> &other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] += other[i];
       }
   
       return *this;
     }
   
     Vector<D, T> &operator-=(const Vector<D, T> &other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] -= other[i];
       }
   
       return *this;
     }
   
     Vector<D, T> &operator*=(const T other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] *= other;
       }
   
       return *this;
     }
   
     Vector<D, T> &operator/=(const T other) {
       for (std::size_t i = 0; i < D; i++) {
         this->m_components[i] /= other;
       }
   
       return *this;
     }
   
     T dot(const Vector<D, T> &other) const {
       T result = 0;
   
       for (std::size_t i = 0; i < D; i++) {
         result += this->m_components[i] * other[i];
       }
   
       return result;
     }
   
     T magn() const {
       T sum_of_squares = 0;
   
       for (auto i : this->m_components) {
         sum_of_squares += i * i;
       }
   
       return std::sqrt(sum_of_squares);
     };
   
     Vector<D, T> normalize() const { return (*this) / this->magn(); }
   
     constexpr std::size_t numDimensions() const { return D; }
   
     const T &operator[](const std::size_t index) const {
       return this->m_components[index];
     }
   
     T &operator[](const std::size_t index) { return this->m_components[index]; }
   
     const T &at(const std::size_t index) const {
       return this->m_components.at(index);
     }
   
     T &at(const std::size_t index) { return this->m_components.at(index); }
   
     iterator begin() noexcept { return iterator{this->m_components.begin()}; }
   
     const_iterator begin() const noexcept {
       return const_iterator{this->m_components.begin()};
     }
   
     iterator end() noexcept { return iterator{this->m_components.end()}; }
   
     const_iterator end() const noexcept {
       return const_iterator{this->m_components.end()};
     }
   
     reverse_iterator rbegin() noexcept {
       return reverse_iterator{this->m_components.rbegin()};
     }
   
     const_reverse_iterator rbegin() const noexcept {
       return const_reverse_iterator{this->m_components.rbegin()};
     }
   
     reverse_iterator rend() noexcept {
       return reverse_iterator{this->m_components.rend()};
     }
   
     const_reverse_iterator rend() const noexcept {
       return const_reverse_iterator{this->m_components.rend()};
     }
   
   protected:
     std::array<T, D> m_components; 
   
   #ifdef SVECTOR_EXPERIMENTAL_COMPARE
   private:
     template <std::size_t D2, typename T2>
     std::int8_t compare(const Vector<D2, T2> &other) const noexcept {
       std::size_t min_dim = std::min(D, D2);
       std::size_t counter = 0;
   
       // check dimensions first
       if (D != D2) {
         return D < D2 ? -1 : 1;
       }
   
       // compare one by one
       for (std::size_t i = 0; i < min_dim; i++) {
         if (this->m_components[i] == other[i]) {
           counter++;
         } else if (this->m_components[i] < other[i]) {
           return -1;
         } else {
           return 1;
         }
       }
   
       if (counter != D || counter != D2) {
         return -1;
       }
   
       // means two vectors are equal
       return 0;
     }
   #endif
   };
   // COMBINER_PY_END
   } // namespace svector
   
   #endif
