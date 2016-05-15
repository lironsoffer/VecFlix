/*
 * VectorEntry.cpp
 *
 *  Created on: May 7, 2016
 *      Author: Ben
 */
#include <stdio.h>
#include <string.h>//include string factions
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <mem.h> //includes memory faction +memcpp
#include "VectorEntry.h"



VectorEntry::VectorEntry(const VectorEntry & orig)
{
	_index=VectorEntry(orig.index());
	_value(orig.value());
}
/*VectorEntry::VectorEntry(const VectorEntry &orig)
{
	//TODO: data=VectorEntry(orig.index(),orig.getRate())
}
*/
VectorEntry::VectorEntry(size_t index, double value): _index(index) , _value(value)
{

}
VectorEntry::VectorEntry(size_t index): _index(index) , _value(0)
{

}
VectorEntry::~VectorEntry() {
	// TODO Auto-generated destructor stub
}


