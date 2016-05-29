/*
 * SparseVector.h
 *
 * Represents a Sparse Vector out of an array of vector entries.
 *
 * set: update a given value to a given index
 *
 * get: returns the value of the required index
 *
 * dimension : getter (returns the dimension of the total array)
 *
 * getNonZeros: returns a vector of VectorEntry that holds the objects
 * that their value isn't 0
 *
 * makeZero: changes any given vector to a default vector holding 0
 *
 * makeStandardBasis: changes the vector to hold 0 in all index
 * other than the given index, which will hold 1
 *
 * add: combine two vectors
 *
 * subtract: subtract the given SpraseVector from this SpraseVector
 *
 * scale : allows to alternate a vector multiplied by a scalar
 *
 */
#ifndef HW3_SPARSEVECTOR_H
#define HW3_SPARSEVECTOR_H

#include "VectorEntry.h"
#include <vector>
#include <iostream>
using namespace std;

class SparseVector {
public:
	/*
	 * SparseVector constructor - creates a new Sparse Vector in a given
	 * dimension
	 *
	 * @param dimension - the required dimension for the array
	 *
	 */
	explicit SparseVector(size_t dimension);
	/*
	 * SparseVector constructor - creates a new Sparse Vector in a given
	 * dimension and insert the array the Vector Entries from the vector
	 *
	 * @param dimension - the required dimension for the array
	 * @param entries - a vector that holds the Vector Entries to insert
	 *
	 */
	SparseVector(size_t dimension, std::vector<VectorEntry> &entries);
	/*
	 * SparseVector copy constructor
	 *
	 * @param orig - the SparseVector to copy
	 *
	 */
	SparseVector(const SparseVector & orig);
	~SparseVector();
	/*
	 * SparseVector assign operator
	 *
	 * @param orig - the SparseVector to assign
	 *
	 */
	SparseVector& operator=(const SparseVector &);

	/*
	 * set: update a given value to a given index
	 *
	 * @param index - the index to to change
	 * @param inValue - the rating value to change
	 *
	 */
	SparseVector& set(size_t index,double inValue);
	/*
	 * get: update a given value to a given index
	 *
	 * @param index - the index to to change
	 * @param inValue - the rating value to change
	 *
	 * @return - Updated sparse vector
	 */
	double get(const size_t requiredIndex) const;
	/*
	 * dimension: getter
	*/
	size_t dimension () const { return (_dimension);}
	/* getNonZeros: returns a vector of VectorEntry that holds the objects
	  that their value isn't 0
	  @param vector holds the VectorEntry (their value isn't 0)

	  @returns:  void
	 */
	void getNonZeros(std::vector<VectorEntry> &vector) const;
	/* makeZero: changes any given vector to a default vector holding 0
	 *
	 * returns void
	 */
	void makeZero();
	/*makeStandardBasis: changes the vector to hold 0 in all index
	  other than the given index, which will hold 1

	 * @param index holds the relevent  location that will hold 1
	 * return: void
	 */
	void makeStandardBasis(size_t index);
	/*
	 * add: combine two vectors
	 *
	 * @param vector - vector to be add
	 * return void
	 */
	void add(const SparseVector& vector);
    /*
     * subtract: subtract the given SpraseVector from this SpraseVector
     *
     * @param vector - vector to be add
	 * return void
     */
	void subtract(const SparseVector& vector);
	/*
	 * scale : allows to alternate a vector multiplied by a scalar
	 *
	 * @param factor - act's a scalar
	 * return void
	 */
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
