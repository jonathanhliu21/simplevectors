/**
 * This file is solely for clang-tidy to analyze the simplevectors library.
 *
 * It assumes usage of experimental features and class method operators in the
 * non-embeddable library.
 */

#define SVECTOR_EXPERIMENTAL_COMPARE
#define SVECTOR_USE_CLASS_OPERATORS

#include "simplevectors/vectors.hpp"

int main() { return 0; }
