#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>
#include <iostream>
using namespace std;

class SparseVector {
public:
	explicit SparseVector(size_t dimension);
	SparseVector(size_t dimension, std::vector<VectorEntry> &entries);
	SparseVector(const SparseVector & orig);
	~SparseVector();
	SparseVector& operator=(const SparseVector &);

	SparseVector& set(size_t,double);
	double get(const size_t requiredIndex) const;
	size_t dimension () const { return (_dimension);}

	void getNonZeros(std::vector<VectorEntry> &vector) const;
	void makeZero();
	void makeStandardBasis(size_t index);
	void add(const SparseVector& vector);
	void subtract(const SparseVector& vector);
	void scale(double factor);


private:
	size_t _dimension;
	size_t _vectorSize;
	VectorEntry *_vector;

	size_t getIndex(size_t requiredIndex) const;
	void scanAndSet(const SparseVector& vector, const double scale);
	bool isValidIndex(const size_t index) const;
};

SparseVector scale(const SparseVector& vector, double factor);
SparseVector add(const SparseVector& left, const SparseVector& right);
SparseVector subtract(const SparseVector& left, const SparseVector& right);

#endif //HW3_SPARSEVECTOR_H
