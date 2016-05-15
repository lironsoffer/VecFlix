#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

class SparseVector {
public:
	SparseVector(unsigned int dim) : _dim(dim),_vector(NULL){}
	SparseVector(unsigned int dim, std::vector<VectorEntry> &entries);
	SparseVector(const SparseVector & orig);
	//TODO: more constructors: copy, assign-B
	//TODO: Operators-B
	//TODO: void getNonZeros(std::vector<VectorEntry> &vector)-L
	//TODO: makeZero()-L
	//TODO: makeStandardBasis(int ?)-L
	unsigned int set(size_t i, double)//TODO: unsigned int set(size_t i,double value);-B
	{

	}
	unsigned int get(size_t i) const//TODO: unsigned int get(size_t i) const;
	{
		return i;
	}
	inline size_t dimension() const
	{
		return _dim;
	}

private:
	unsigned int _dim;
	VectorEntry *_vector;

	SparseVector(){}
};

//SparseVector scale(const SparseVector& vector, double factor); -B faction
//SparseVector add(const SparseVector& left, const SparseVector& right);
//SparseVector subtract(const SparseVector& left, const SparseVector& right);

#endif //HW3_SPARSEVECTOR_H
