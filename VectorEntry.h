/*
 * VectorEntry.h
 *
 *  Created on: May 7, 2016
 *      Author: Ben
 */

#ifndef VECTORENTRY_H_
#define VECTORENTRY_H_


#include  <iostream>
class VectorEntry
{
public:
	VectorEntry();
	VectorEntry(size_t  index, double value): _index(index) , _value(value){} //defalut by val
	VectorEntry(size_t  index): _index(index) , _value(0){} // default by index
	VectorEntry(const VectorEntry & orig) : _index(orig.index()) , _value(orig.value()){}
	virtual ~VectorEntry(){}
	double value () const {return (_value); }
	void setValue (const double value) { _value=value; }
	size_t  index() const { return (_index); }

	//VectorEntry operator + (const VectorEntry &a, const VectorEntry &b);
private:

size_t _index;
double _value; // class member obj needs to have a _

};


#endif /* VECTORENTRY_H_ */
