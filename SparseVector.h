#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

class SparseVector {
public:
	SparseVector(unsigned int dim) : _dim(dim),_vector(NULL){}
	SparseVector(unsigned int dim, std::vector<VectorEntry> &entries);
	//TODO: more constructors: copy, assign -B
	//TODO: Operators -B

	//TODO: unsigned int get(size_t i) const; -L
	//TODO: unsigned int set(size_t i,double value); -B
	//TODO: void getNonZeros(std::vector<VectorEntry> &vector) -L
	void makeZero(); //TODO: makeZero() -L
	//TODO: makeStandardBasis(int ?) -L
	inline size_t dimension() const
	{
		return _dim;
	}

private:
	unsigned int _dim;
	VectorEntry *_vector;

	SparseVector(){}
};

//SparseVector scale(const SparseVector& vector, double factor); -B
//SparseVector add(const SparseVector& left, const SparseVector& right); -L
//SparseVector subtract(const SparseVector& left, const SparseVector& right); -L

#endif //HW3_SPARSEVECTOR_H
