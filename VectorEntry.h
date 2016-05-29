/*
 * VectorEntry.h
 *
 * This module represents an object in a sparse-vector,
 * holding an index and a value.
 * It includes the following:
 * value - getter
 * index - getter
 * setIndex - setter
 */

#ifndef VECTORENTRY_H_
#define VECTORENTRY_H_

#include <iostream>

class VectorEntry {
public:
/*
 * Constructor: VectorEntry () -  Constructor by default value
 */
	VectorEntry(): _index(0), _value(0){}
/*
 * Constructor: VectorEntry (size_t index, double value) -
 * Constructor that creates an Entry with a given index and a given value
 *
 *@param index - index to set
 *@param value - value to set
 *
 */
	VectorEntry(size_t index, double value=0): _index(index) , _value(value){}
/*
 * Constructor: VectorEntry (const VectorEntry & orig) - Copy Constructor
 *
 * @param orig - the Vector Entry to copy
 */
	VectorEntry(const VectorEntry & orig) : _index(orig.index()) , _value(orig.value()){}
	~VectorEntry(){}
	double value () const
	{
		return (_value);
	}
	void setValue (const double value)
	{
		_value=value;
	}
	size_t  index() const
	{
		return (_index);
	}

private:
size_t _index;
double _value; // class member obj needs to have a _
};


#endif /* VECTORENTRY_H_ */
