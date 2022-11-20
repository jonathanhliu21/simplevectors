#include "simplevectors/vectors.hpp"

namespace svector_kinematics_example {
/**
 * Represents a 2D object which has a mass, position, velocity and acceleration
 */
struct Object2D {
  double mass;
  svector::Vector2D position;
  svector::Vector2D velocity;
  svector::Vector2D acceleration;
};

/**
 * Finds the average velocity given an object's change in position and an
 * interval of time
 *
 * @param pos_0 The initial position
 * @param pos_f The final position
 * @param time_interval The given time interval
 *
 * @returns The average velocity over that time interval
 */
svector::Vector2D avgVelocity(svector::Vector2D pos_0, svector::Vector2D pos_f,
                              double time_interval) {
  svector::Vector2D delta = pos_f - pos_0;
  return delta / time_interval;
}

/**
 * Finds the average acceleration given an object's change in velocity and an
 * interval of time
 *
 * @param v_0 The initial position
 * @param v_f The final position
 * @param time_interval The given time interval
 *
 * @returns The average acceleration over that time interval
 */
svector::Vector2D avgAcceleration(svector::Vector2D v_0, svector::Vector2D v_f,
                                  double time_interval) {
  svector::Vector2D delta = v_f - v_0;
  return delta / time_interval;
}

/**
 * Finds the change in position given the velocity and an interval of time
 *
 * @param vel The velocity
 * @param time_interval An interval of time
 *
 * @returns The change in position after travelling at a certain velocity for a
 * certain interval of time
 */
svector::Vector2D changeInPosition(svector::Vector2D vel,
                                   double time_interval) {
  return vel * time_interval;
}

/**
 * Finds the change in velocity given the acceleration and an interval of time
 *
 * @param acc The acceleration
 * @param time_interval An interval of time
 *
 * @returns The change in velocity after accelerating for a certain interval of
 * time
 */
svector::Vector2D changeInVelocity(svector::Vector2D acc,
                                   double time_interval) {
  return acc * time_interval;
}

/**
 * Updates velocity and position of an object given a new acceleration and a
 * time interval
 *
 * @param object The 2D object given
 * @param acc The acceleration of the object
 * @param time_interval The time interval that the object has that acceleration
 */
void updateVelocityPosition(Object2D &object, svector::Vector2D acc,
                            double time_interval) {
  object.acceleration = acc;
  object.velocity = changeInVelocity(acc, time_interval);
  object.position = changeInPosition(object.velocity, time_interval);
}
} // namespace svector_kinematics_example
