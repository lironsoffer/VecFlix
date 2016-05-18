#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>

class SparseVector {
public:
    SparseVector(size_t dim) : _dimension(dim),_vectorSize(0), _vector(0){}
	SparseVector(size_t dim, std::vector<VectorEntry> &entries);

	SparseVector(const SparseVector & orig);

	void makeZero(); //-L
	double get(size_t  i) const;
	void getNonZeros(std::vector<VectorEntry> &vector) const;// -L
	void makeStandardBasis(size_t  index); // -L
	void add(const SparseVector& vector); //TODO -L
	size_t dimension () const { return (_dimension);}
	size_t vectorSize () const { return (_vectorSize);}
	SparseVector& set(size_t  index,double invalue);
	//TODO: more constructors: assign -B
	//TODO: Operators -B
	//SparseVector operator + (size_t dim, size_t VectorSize, VectorxEntry *vector);
	//SparseVector operator = (size_t dim, size_t VectorSize, VectorEntry *vector);
	 //TODO: size_t set(size_t  i,double value); -B




private:
	size_t _dimension; // the amount of videos
	size_t _vectorSize; // the amount of rated videos
	VectorEntry *_vector;
	double getIndex(size_t indexvalue) const;
	//SparseVector(){}
};

//SparseVector scale(const SparseVector& vector, double factor); -B
//SparseVector add(const SparseVector& left, const SparseVector& right); // -L
//SparseVector subtract(const SparseVector& left, const SparseVector& right); -L

#endif //HW3_SPARSEVECTOR_H
