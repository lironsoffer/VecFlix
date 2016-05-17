#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

class SparseVector {
public:
	explicit SparseVector(unsigned int dim) : _dimension(dim),_vectorSize(0), _vector(0){}
	SparseVector(unsigned int dim, std::vector<VectorEntry> &entries);

	SparseVector(const SparseVector & orig);
	inline unsigned int dimension() const
	{
		return _dimension;
	}
	void makeZero(); //-L
	double get(unsigned int  i) const; // -L
	void getNonZeros(std::vector<VectorEntry> &vector) const;// -L
	void makeStandardBasis(unsigned int  index); // -L
	void add(const SparseVector& vector); //TODO -L

	//TODO: more constructors: assign -B
	//TODO: Operators -B
	SparseVector operator + (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);
	SparseVector operator = (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);
	SparseVector& set(unsigned int  i,double value){return (*this);} //TODO: unsigned int set(unsigned int  i,double value); -B




private:
	unsigned int _dimension;
	unsigned int _vectorSize;
	VectorEntry *_vector;

	//SparseVector(){}
};

//SparseVector scale(const SparseVector& vector, double factor); -B
//SparseVector add(const SparseVector& left, const SparseVector& right); // -L
//SparseVector subtract(const SparseVector& left, const SparseVector& right); -L

#endif //HW3_SPARSEVECTOR_H
