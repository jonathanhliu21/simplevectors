#include "simplevectors/vectors.hpp"

#include <cmath>

namespace svector_complex_example {
template <typename T> struct Polar { T r, ang; };

template <typename T> class Complex : public svector::Vector<2, T> {
public:
  Complex(const T real, const T imag) {
    this->m_components[0] = real;
    this->m_components[1] = imag;
  }

  Complex(const svector::Vector<2, T> &other) {
    this->m_components[0] = other[0];
    this->m_components[1] = other[1];
  }

  Complex(const Polar<T> polar) {
    this->m_components[0] = polar.r * std::cos(polar.ang);
    this->m_components[1] = polar.r * std::sin(polar.ang);
  }

  Complex getConjugate() {
    return Complex<T>(this->m_components[0], -this->m_components[1]);
  }

  double angle() {
    return std::atan2(this->m_components[1], this->m_components[0]);
  }

  Polar<T> toPolar() {
    Polar<T> polar = {this->magn(), angle()};
    return polar;
  }
};

template <typename T>
Complex<T> operator*(const Complex<T> &lhs, const Complex<T> &rhs) {
  // finding product of 2 complex numbers using polar coordinates
  Polar<T> p1 = lhs.toPolar();
  Polar<T> p2 = rhs.toPolar();

  T re = p1.r * p2.r * std::cos(p1.ang + p2.ang);
  T im = p1.r * p2.r * std::sin(p1.ang + p2.ang);

  return Complex<T>(re, im);
}

template <typename T>
Complex<T> operator/(const Complex<T> &lhs, const Complex<T> &rhs) {
  // finding quotient of 2 complex numbers using polar coordinates
  Polar<T> p1 = lhs.toPolar();
  Polar<T> p2 = rhs.toPolar();

  T re = (p1.r / p2.r) * std::cos(p1.ang - p2.ang);
  T im = (p1.r / p2.r) * std::sin(p1.ang - p2.ang);

  return Complex<T>(re, im);
}

// Application of complex numbers: AC circuits

/**
 * Finds the total sum wave of 2 sinusoidal AC sources.
 *
 * @param source1 The first AC source, represented by a polar coordinate, with r
 * being the amplitude and ang being the phase shift.
 * @param source2 The second AC source, represented by a polar coordinate, with
 * r being the amplitude and ang being the phase shift.
 *
 * @returns The resulting wave represented as a polar coordinate, with r being
 * the amplitude and ang being the phase shift.
 */
template <typename T>
Polar<T> getTotalAC(const Polar<T> source1, const Polar<T> source2) {
  Complex<T> wave1(source1);
  Complex<T> wave2(source2);

  Complex<T> res = wave1 + wave2;
  return res.toPolar();
}

/**
 * Finds the total impedence given the resistance and reactances.
 *
 * The total impedence is represented as a complex number, with the
 * resistance represented by the real part and the combined reactance (both
 * capacitive and inductive) represented by the imaginary part.
 *
 * The value for impedence used in Ohm's Law and other formulas
 * would be the magnitude of the complex number.
 *
 * @param r The resistance of the circuit.
 * @param xc The capacitive reactance.
 * @param xl The inductive reactance.
 *
 * @returns The total impedence of the circuit.
 */
template <typename T>
Complex<T> getImpedence(const T r, const T xc, const T xl) {
  T xTotal = xc + xl;

  return Complex<T>(r, xTotal);
}

/**
 * Calculates the RMS voltage given the impedence and current.
 *
 * This is done using Ohm's Law: V_rms = I_rms * Z
 *
 * @param i The RMS current.
 * @param z The impedence.
 *
 * @returns The RMS voltage, calculated using Ohm's Law.
 */
template <typename T> T getVoltage(const T i, const Complex<T> z) {
  T magn = z.magn();
  return i * magn;
}

/**
 * Calculates the RMS current given the impedence and voltage.
 *
 * This is done using Ohm's Law: V_rms = I_rms * Z
 *
 * @param v The RMS voltage.
 * @param z The impedence.
 *
 * @returns The RMS current, calculated using Ohm's Law.
 */
template <typename T> T getCurrent(const T v, const Complex<T> z) {
  T magn = z.magn();
  return v / magn;
}
} // namespace svector_complex_example
