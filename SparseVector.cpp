#include "SparseVector.h"

//SparseVector scale(const SparseVector& vector, double factor)
//{
//    SparseVector result = vector;
//    result.scale(factor);
//    return result;
//}
//
//
SparseVector add(const SparseVector& left, const SparseVector& right)
{
    SparseVector result(left);
    result.add (right);
    return result;
}
//
//SparseVector subtract(const SparseVector& left, const SparseVector& right)
//{
//    SparseVector result = left;
//    result.subtract(right);
//    return result;
//}


SparseVector::SparseVector(unsigned int dimension,
		std::vector<VectorEntry> &entries) :
				_dimension(dimension),_vectorSize(entries.size()),
				_vector(new VectorEntry[entries.size()])
{
	for(size_t i=0;i<_vectorSize;i++)
	{
		_vector[i]=entries[i];
	}
}

SparseVector::SparseVector(const SparseVector & orig)
{
	_dimension=orig._dimension;
	_vectorSize=orig._vectorSize;
	_vector=orig._vector;
}

SparseVector& SparseVector::set(size_t index,double inValue)
{

	if((index<_vectorSize)&&(this->get(index)!=0)) //if the rating isn't 0 change it
	{
		_vector[(this->getIndex(index))].setValue(inValue);
	}
	else
	{
		VectorEntry *newVec;
		if (index>_vectorSize) //  replace the old arry and make a new arry containing the new rating
		//Make new array with new size
		{
			newVec=new VectorEntry[index+1];
		}
		// Make new array with old size+1
		else
		{
			newVec=new VectorEntry[_vectorSize+1];
		}

		for(size_t j=0; j<_vectorSize; j++)
		{
			newVec[j]=_vector[j];
		}
		VectorEntry *newEntry = new VectorEntry(index,inValue);
		newVec[_vectorSize++]=*newEntry;
		delete[] _vector;
		_vector=newVec;
	}
	return *this;
}

void SparseVector::makeZero()
{
	_vectorSize=0;
	delete[] _vector; //TODO: Read again the chapter about delete
}

double SparseVector::get(size_t indexvalue) const
{
	if (indexvalue>=_dimension) //TODO: Check if should be > or >=
	{
		std::cerr << "Index is larger than dimension" << std::endl;
	}
	for (unsigned int  i=0;i<_vectorSize;i++)
	{
		if(_vector[i].index()==indexvalue)
		{
			return _vector[i].value();
		}
	}
//if was unused + double use of i
	return 0;
}

size_t SparseVector::getIndex(size_t indexvalue) const
{
	if (indexvalue>=_dimension) //TODO: Check if should be > or >=
	{
		std::cerr << "Index is larger than dimension" << std::endl;
	}
	for (unsigned int  i=0;i<_vectorSize;i++)
	{
		if(_vector[i].index()==indexvalue)
		{
			return i;
		}
	}
	return _vectorSize;
}

void SparseVector::getNonZeros(std::vector<VectorEntry> &vector) const
{
	if (!vector.empty())
	{
		  vector.clear();
	}
	for (size_t i=0;i<_vectorSize;i++)
	{
		vector.push_back(_vector[i]);
	}
}

void SparseVector::makeStandardBasis(size_t index)
{
	this->makeZero();
	this->set(index,1);
}

void SparseVector::add(const SparseVector& vector)
{
	for (size_t i=0;i<_dimension;i++)
	{
		double tmp=this->get(i)+vector.get(i);
		this->set(i,tmp);
	}
}
