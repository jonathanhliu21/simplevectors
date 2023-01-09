#include "simplevectors/vectors.hpp"

#include <cmath>
#include <initializer_list>

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

  Complex getReciprocal() {
    T a = this->m_components[0];
    T b = this->m_components[1];

    T re = a / (a * a + b * b);
    T im = b / (a * a + b * b);

    return Complex<T>(re, -im);
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

// Application of complex numbers: sinusoidal AC circuits

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
 * @param xc The magnitude of the capacitive reactance (positive).
 * @param xl The magnitude of the inductive reactance.
 *
 * @returns The total impedence of the circuit.
 */
template <typename T>
Complex<T> getImpedence(const T r, const T xc, const T xl) {
  return Complex<T>(r, xl - xc);
}

/**
 * Finds the total series impedence given a list of impedences.
 *
 * These impedences can be calculated using getImpedence().
 *
 * @param list An initializer list of impedences represented by complex numbers.
 *
 * @returns The total impedence of the series circuit.
 */
template <typename T>
Complex<T> getSeriesImpedence(std::initializer_list<Complex<T>> list) {
  Complex<T> total;

  for (const auto &impedence : list) {
    total += impedence;
  }

  return total;
}

/**
 * Finds the total parallel impedence given a list of impedences.
 *
 * These impedences can be calculated using getImpedence().
 *
 * @param list An initializer list of impedences represented by complex numbers.
 *
 * @returns The total impedence of the parallel circuit.
 */
template <typename T>
Complex<T> getParallelImpedence(std::initializer_list<Complex<T>> list) {
  Complex<T> total;

  for (const auto &impedence : list) {
    auto reciprocal = impedence.getReciprocal();
    total += reciprocal;
  }

  return total.getReciprocal();
}

/**
 * Calculates the voltage given the impedence and current.
 *
 * This is done using Ohm's Law: V_rms = I_rms * Z. The voltage and current are
 * represented as polar coordinates with r representing the
 * amplitudes of the voltage and current and ang representing the phase
 * shifts. The impedence can be calculated using getImpedence().
 *
 * @param i The current.
 * @param z The impedence.
 *
 * @returns The voltage, calculated using Ohm's Law.
 */
template <typename T>
Polar<T> getVoltage(const Polar<T> i, const Complex<T> z) {
  Complex<T> currentComplex(i);
  Complex<T> product = i * z;
  return product.toPolar();
}

/**
 * Calculates the current given the impedence and voltage.
 *
 * This is done using Ohm's Law: V_rms = I_rms * Z. The voltage and current are
 * represented as polar coordinates with r representing the
 * amplitudes of the voltage and current and ang representing the phase
 * shifts. The impedence can be calculated using getImpedence().
 *
 * @param v The voltage.
 * @param z The impedence.
 *
 * @returns The current, calculated using Ohm's Law.
 */
template <typename T>
Polar<T> getCurrent(const Polar<T> v, const Complex<T> z) {
  Complex<T> voltageComplex(v);
  Complex<T> quotient = v / z;
  return quotient.toPolar();
}

/**
 * Calculates the apparent power.
 *
 * This is done using the formula VA = Irms * Vrms. The voltage and current are
 * represented as polar coordinates with r representing the
 * amplitudes of the voltage and current and ang representing the phase
 * shifts. These must be the RMS voltage and current.
 *
 * @param v The RMS voltage.
 * @param i The RMS current.
 *
 * @returns The apparent power, represented as a polar coordinate with r being
 * the apparent power and ang being the added phase shifts of the voltage and
 * current.
 */
template <typename T>
Polar<T> getApparentPower(const Polar<T> v, const Polar<T> i) {
  Complex<T> voltageComplex(v);
  Complex<T> currentComplex(i);

  Complex<T> powerComplex = voltageComplex * currentComplex;

  return powerComplex.toPolar();
}

/**
 * Calculates the power factor.
 *
 * This is done by finding the cosine of the phase shift between the voltage and
 * current. The voltage and current are represented as polar coordinates with r
 * representing the amplitudes of the voltage and current and ang representing
 * the phase shifts.
 *
 * Since this is the ratio between the real power and apparent power, this
 * can be used with getApparentPower() to calculate reactive power, real power,
 * and the reactive factor.
 *
 * @param v The voltage.
 * @param i The current.
 *
 * @returns The power factor (should be less than 1).
 */
template <typename T> T getReactiveFactor(const Polar<T> v, const Polar<T> i) {
  Complex<T> voltageComplex(v);
  Complex<T> currentComplex(i);

  // cosine of angle = (a dot b) / (magn(a) * magn(b))
  return voltageComplex.dot(currentComplex) /
         (voltageComplex.magn() * currentComplex.magn());
}
} // namespace svector_complex_example
