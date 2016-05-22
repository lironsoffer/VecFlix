#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>
#include <iostream>
using namespace std;

enum Action{ADD,SUBTRACT};

static bool DEBUG = 0;

class SparseVector {
public:
	explicit SparseVector(unsigned int dimension);
	SparseVector(unsigned int dimension, std::vector<VectorEntry> &entries);
	SparseVector(const SparseVector & orig);
	~SparseVector();
	SparseVector& operator=(const SparseVector &);

	SparseVector& set(size_t,double);
	double get(const size_t requiredIndex) const;
	unsigned int dimension () const { return (_dimension);}

	void getNonZeros(std::vector<VectorEntry> &vector) const;
	void makeZero();
	void makeStandardBasis(size_t index);
	void add(const SparseVector& vector);
	void subtract(const SparseVector& vector);
	void scale(double factor);


private:
	unsigned int _dimension;
	unsigned int _vectorSize;
	VectorEntry *_vector;

	size_t getIndex(size_t requiredIndex) const;
	void scanAndSet(const Action toDo, const SparseVector& vector);
};

SparseVector scale(const SparseVector& vector, double factor);
SparseVector add(const SparseVector& left, const SparseVector& right);
SparseVector subtract(const SparseVector& left, const SparseVector& right);

#endif //HW3_SPARSEVECTOR_H
