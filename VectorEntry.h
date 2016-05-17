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

	VectorEntry(unsigned int  index, double value): _index(index) , _value(value){} //defalut by val
	VectorEntry(unsigned int  index): _index(index) , _value(0){} // default by index
	VectorEntry(const VectorEntry & orig) : _index(orig.index()) , _value(orig.value()){}
	virtual ~VectorEntry(){}
	double value () const {return (_value); }
	void setvalue (const double value) { _value=value; }
	unsigned int  index() const { return (_index); }

	VectorEntry operator + (const VectorEntry &a, const VectorEntry &b);
private:
// can be type_def- unsigned int  -> index
unsigned int _index;
double _value; // class member obj needs to have a _
VectorEntry();
};


#endif /* VECTORENTRY_H_ */
