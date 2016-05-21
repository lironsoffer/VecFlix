#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>
#include <iostream>
using namespace std;

class SparseVector {
public:
	SparseVector(unsigned int dimension=0) : _dimension(dimension),_vectorSize(0), _vector(new VectorEntry()){
        cout << "SparseVector(dimension) _vector = " << (void*)_vector << endl;
    }
	SparseVector(unsigned int dimension, std::vector<VectorEntry> &entries);
	SparseVector(const SparseVector & orig);
	~SparseVector(){
        cout << "~SparseVector() _vector = " << (void*)_vector << endl;
        delete[] _vector;
    }

	void makeZero();
	double get(size_t indexvalue) const; // -L
	void getNonZeros(std::vector<VectorEntry> &vector) const;// -L
	void makeStandardBasis(size_t index); // -L
	void add(const SparseVector& vector); //-L
	void subtract(const SparseVector& vector);
	unsigned int dimension () const { return (_dimension);}
	//TODO: more constructors: assign -B
	//TODO: Operators -B
	//SparseVector operator + (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);
	//SparseVector operator = (unsigned int dim, unsigned int VectorSize, VectorEntry *vector);
	SparseVector& operator=(const SparseVector &);
	SparseVector& set(size_t,double); //-B

private:
	unsigned int _dimension;
	unsigned int _vectorSize;
	VectorEntry *_vector;

	size_t getIndex(size_t indexvalue) const;

	//SparseVector():_dimension(0),_vectorSize(0),_vector(0){} //
};

//SparseVector scale(const SparseVector& vector, double factor); -B
SparseVector add(const SparseVector& left, const SparseVector& right); // -L
SparseVector subtract(const SparseVector& left, const SparseVector& right); //-L

#endif //HW3_SPARSEVECTOR_H
