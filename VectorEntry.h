/*
 * VectorEntry.h
 *
 *  Created on: May 7, 2016
 *      Author: Ben
 */

#ifndef VECTORENTRY_H_
#define VECTORENTRY_H_



class VectorEntry
{
public:

	VectorEntry(size_t index, double value): _index(index) , _value(value){} //defalut by val
	VectorEntry(size_t index): _index(index) , _value(0){} // default by index
	VectorEntry(const VectorEntry & orig) : _index(orig.index()) , _value(orig.value()){}
	virtual ~VectorEntry(){}
	double value () const {return (_value); }
	void setvalue (const double value) { _value=value; }
	size_t index() const { return (_index); }




private:
// can be type_def- size_t -> index
size_t _index;
double _value; // class member obj needs to have a _
VectorEntry();
};


#endif /* VECTORENTRY_H_ */
