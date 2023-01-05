/**
 * This file is solely for clang-tidy to analyze the simplevectors library.
 *
 * It assumes usage of experimental features and class method operators.
 */

#define SVECTOR_EXPERIMENTAL_COMPARE
#define SVECTOR_USE_CLASS_OPERATORS

#include "simplevectors/embed.h"
#include "simplevectors/embed.hpp"
#include "simplevectors/vectors.hpp"

int main() { return 0; }
