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

double SparseVector::getIndex(size_t indexvalue) const
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
	std::cout << _vectorSize << std::endl;
	for (size_t i=0;i<_vectorSize;i++)
	{
		size_t movieIndex=_vector[i].index();
		double tmp=vector.get(i) + vector.get(movieIndex);
		VectorEntry newVec(_vector[i].index(),tmp);
		std::cout << tmp << std::endl;
		_vector[i]=newVec;
	}

}
