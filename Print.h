#ifndef HW3_PRINT_H
#define HW3_PRINT_H

/**
 * Contains functions for printing of vectors and non-zero entries.
 */

#include "SparseVector.h"
#include <vector>

/**
 * Prints the given vector, in full dimensions, inside square brackets. For
 * example: [1, 0, -5, 3, 0, 0, 1]
 *
 *  vector
 *      The vector to be printed
 */
void printVector(const SparseVector& vector);

/**
 * Prints the list of VectorEntry objects as an array of (index, value) pairs,
 * inside curly braces. For example: { (1, -3), (4, 5), (1, -1) }.
 *
 *  entries
 *      The vector of entries to be printed
 */
void printEntries(std::vector<VectorEntry> entries);

#endif //HW3_PRINT_CPP_H
