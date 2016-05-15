/*
 * VectorEntry.h
 *
 *  Created on: May 7, 2016
 *      Author: Ben
 */

#ifndef VECTORENTRY_H_
#define VECTORENTRY_H_

#include <iostream>

class VectorEntry {
public:
	VectorEntry(std::size_t index, double value): _index(index) , _value(value){}//default by val
	VectorEntry(std::size_t index): _index(index) , _value(0){}// default by index
	VectorEntry(const VectorEntry &orig); // needs to be verify
	virtual ~VectorEntry();
	double value() const
	{
		return _value;
	}
	void setValue(const double value)
	{
		_value=value;
	}
	size_t index() const; //TODO: change to Index()
	//TODO: void Operator*(double num);



private:
size_t _index; // can be type_def- size_t -> index
double _value; // class member obj needs to have a _

VectorEntry(); //location needs to be verify


};

#endif /* VECTORENTRY_H_ */
