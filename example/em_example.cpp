/**
 * https://en.wikipedia.org/wiki/Electromagnetic_radiation
 */

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "simplevectors/vectors.hpp"

namespace svector_em_example {
const double speed_of_light = 299792458; // m/s

enum EMSpectrum {
  GAMMA,
  XRAY,
  ULTRAVIOLET,
  VISIBLE,
  INFRARED,
  MICROWAVE,
  RADIO
};

enum VisibleSpectrum {
  VIOLET,
  BLUE,
  CYAN,
  GREEN,
  YELLOW,
  ORANGE,
  RED,
  UV_OR_SMALLER,
  IR_OR_LARGER
};

/**
 * Gets wavelength given frequency; uses c/f
 *
 * @param wavelength Frequency, in hertz.
 *
 * @returns Wavelength, in meters.
 */
double getWavelength(double frequency) { return speed_of_light / frequency; }

/**
 * Gets frequency given wavelength; uses c/λ
 *
 * @param wavelength Wavelength, in meters.
 *
 * @returns Frequency, in hertz.
 */
double getFrequency(double wavelength) { return speed_of_light / wavelength; }

/**
 * Gets wave type based on EM Spectrum.
 *
 * NOTE: The values shown on the table below are approximated, and more accurate
 * values should be used. This is just used as an example.
 *
 * Wave type:    |Gamma rays|X-Rays|--UV--|Visible|Infrared|Microwave|Radio|
 * Freq (log 10):  20-24     17-20  15-17  14-15    11-14    9-11      1-9
 *
 * @param log_frequency The common logarithm (log base 10) of frequency.
 *
 * @returns An enum representing the EM wave type.
 */
EMSpectrum getWaveType(double log_frequency) {
  if (log_frequency > 20) {
    return GAMMA;
  }
  if (log_frequency > 17 && log_frequency <= 20) {
    return XRAY;
  }
  if (log_frequency > 15 && log_frequency <= 17) {
    return ULTRAVIOLET;
  }
  if (log_frequency > 14 && log_frequency <= 15) {
    return VISIBLE;
  }
  if (log_frequency > 11 && log_frequency <= 14) {
    return INFRARED;
  }
  if (log_frequency > 9 && log_frequency <= 11) {
    return MICROWAVE;
  }
  return RADIO;
}

/**
 * Gets color based on wavelength.
 *
 * NOTE: The values shown on the table below are approximated, and more accurate
 * values should be used. This is just used as an example.
 *
 * Color:      | Red | Orange | Yellow | Green | Cyan | Blue | Violet |
 * λ_low (nm):  625     590      565     500     485    450     380
 * λ_high (nm): 750     625      590     565     500    485     450
 * https://en.wikipedia.org/wiki/Visible_spectrum
 *
 * @param wavelength The wavelength, in nanometers.
 *
 * @returns an enum representing the color.
 */
VisibleSpectrum getColor(double wavelength) {
  if (wavelength > 750) {
    return IR_OR_LARGER;
  }
  if (wavelength > 625 && wavelength <= 750) {
    return RED;
  }
  if (wavelength > 590 && wavelength <= 625) {
    return ORANGE;
  }
  if (wavelength > 565 && wavelength <= 590) {
    return YELLOW;
  }
  if (wavelength > 500 && wavelength <= 565) {
    return GREEN;
  }
  if (wavelength > 485 && wavelength <= 500) {
    return CYAN;
  }
  if (wavelength > 450 && wavelength <= 485) {
    return BLUE;
  }
  if (wavelength > 380 && wavelength <= 450) {
    return VIOLET;
  }
  return UV_OR_SMALLER;
}

/**
 * Gets direction of EM wave.
 *
 * An EM wave travels orthogonal to the directin of the elctric field E and the
 * direction of the magnetic field B.
 *
 * @param E An electric field, represented by a 3D vector.
 * @param B A magnetic field, represented by a 3D vector.
 *
 * @returns A unit 3D vector that is in the direction of the resulting EM
 * wave.
 */
svector::Vector3D EMDirection(const svector::Vector3D &E,
                              const svector::Vector3D &B) {
  svector::Vector3D crossed = E.cross(B);
  return crossed.normalize();
}

/**
 * Gets the resonant frequency of an LC circuit.
 *
 * @param c The capacitance of the LC circuit.
 * @param l The inductance of the LC circuit.
 *
 * @returns The resonant frequency of the circuit.
 */
template <typename T> T getResonantFrequency(T c, T l) {
  return 1 / (2 * M_PI * std::sqrt(l * c));
}
} // namespace svector_em_example
