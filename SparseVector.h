#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

class SparseVector {
public:
	SparseVector(unsigned int dimension) : _dimension(dimension),_vectorSize(0), _vector(0){}
	SparseVector(unsigned int dimension, std::vector<VectorEntry> &entries);
	SparseVector(const SparseVector & orig);

	void makeZero();
	double get(size_t indexvalue) const; // -L
	void getNonZeros(std::vector<VectorEntry> &vector) const;// -L
	void makeStandardBasis(size_t index); // -L
	void add(const SparseVector& vector); //TODO -L
	unsigned int dimension () const { return (_dimension);}
	//TODO: more constructors: assign -B
	//TODO: Operators -B
	//SparseVector operator + (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);
	//SparseVector operator = (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);

	SparseVector& set(size_t i,double value){return *this;} //TODO: unsigned int set(size_t i,double value); -B

private:
	unsigned int _dimension;
	unsigned int _vectorSize;
	VectorEntry *_vector;

	double getIndex(size_t indexvalue) const;

	//SparseVector(){}
};

//SparseVector scale(const SparseVector& vector, double factor); -B
SparseVector add(const SparseVector& left, const SparseVector& right); // -L
//SparseVector subtract(const SparseVector& left, const SparseVector& right); -L

#endif //HW3_SPARSEVECTOR_H
