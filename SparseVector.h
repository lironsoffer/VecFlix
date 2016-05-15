#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

namespace SpraseVector {
class SparseVector {
public:
	SparseVector(unsigned int dim) : _dim(dim){}
	//TODO: SparseVector(unsigned int dim, std::vector<VectorEntry> entries):_dim(dim){}
	//TODO: more constructors
	//TODO: Operators

	//TODO: unsigned int get(unsigned int i) const;
	//TODO: unsigned int set(unsigned int i,double value);
	//TODO: void getNonZeros(std::vector<VectorEntry> &vector)
	//TODO: makeZero()
	//TODO: makeStandardBasis(int ?)

private:
	unsigned int _dim;

	SparseVector(){}
};
} /* namespace SpraseVector */

SparseVector scale(const SparseVector& vector, double factor);
SparseVector add(const SparseVector& left, const SparseVector& right);
SparseVector subtract(const SparseVector& left, const SparseVector& right);

#endif //HW3_SPARSEVECTOR_H
