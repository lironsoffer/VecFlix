/*
 * VectorEntry.h
 *
 *  Created on: May 7, 2016
 *      Author: Ben
 */

#ifndef VECTORENTRY_H_
#define VECTORENTRY_H_

#include <iostream>

namespace VectorEntry {

class VectorEntry {
public:
	//TODO: Change size_t to typedef
	VectorEntry(std::size_t index, double rate): _index(index) , _rate(rate){}//default by val
	VectorEntry(std::size_t index): _index(index) , _rate(0){}// default by index
	VectorEntry(const VectorEntry &orig); // needs to be verify
	virtual ~VectorEntry();
	double getRate () const;
	bool setRate (const double rate);
	size_t getIndex() const; //TODO: change to Index()
	//TODO: void Operator*(double num);



private:
std::size_t _index; // can be type_def- size_t -> index
double _rate; // class member obj needs to have a _
VectorEntry* _prevEntry;//connected list
VectorEntry* _nextEntry;//connected list

VectorEntry(); //location needs to be verify


};
} /* namespace VectorEntry */

#endif /* VECTORENTRY_H_ */
