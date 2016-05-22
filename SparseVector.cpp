#include "SparseVector.h"

SparseVector scale(const SparseVector& vector, double factor)
{
    SparseVector result = vector;
    result.scale(factor);
    return result;
}

SparseVector add(const SparseVector& left, const SparseVector& right)
{
    SparseVector result(left);
    result.add (right);
    return result;
}

SparseVector subtract(const SparseVector& left, const SparseVector& right)
{
    SparseVector result = left;
    result.subtract(right);
    return result;
}

void copyArray(VectorEntry* left, const VectorEntry* right,const size_t size)
{
	for(size_t i=0;i<size;i++)
		{
			left[i]=right[i];
		}
}

SparseVector::SparseVector(unsigned int dimension=0) : _dimension(dimension)
,_vectorSize(0), _vector(0)
{
	if(DEBUG)
	{
		cout << "SparseVector(dimension) _vector = " << (void*)_vector << endl;
	}
}

SparseVector::SparseVector(unsigned int dimension,
		std::vector<VectorEntry> &entries) :
				_dimension(dimension),_vectorSize(entries.size()),
				_vector(new VectorEntry[entries.size()])
{
	if (DEBUG)
	{
		cout << "SparseVector(dimension, entries) _vector = " << (void*)_vector
				<< endl;
	}
//	if (_dimension<_vectorSize)
//	{
//		std::cerr << "Error: vector<VectorEntry> is larger than dimension" << std::endl;
//	}

	for(size_t i=0;i<_vectorSize;i++)
	{
		_vector[i]=entries[i]; //No use of copyArray since entries is vector<> type, not array
	}
}

SparseVector::SparseVector(const SparseVector & orig)
{
	_dimension=orig._dimension;
	_vectorSize=orig._vectorSize;
	_vector=new VectorEntry[orig._vectorSize];
//	for(size_t i=0;i<_vectorSize;i++)
//	{
//		_vector[i]=orig._vector[i];
//	}
	copyArray(_vector,orig._vector,_vectorSize);


	if (DEBUG)
	{
		cout << "SparseVector(&orig) _vector = " << (void*)_vector << endl;
	}
}

SparseVector::~SparseVector()
{
	if (DEBUG)
	{
		cout << "~SparseVector() _vector = " << (void*)_vector << endl;
	}
	if (_vectorSize > 0)
	{
		delete[] _vector;
	}
	{
	}
}

SparseVector& SparseVector::operator=(const SparseVector & orig)
{
	if (this==&orig)
	{
		return *this;
	}

	if (DEBUG)
	{
		cout << "SparseVector(&orig) op= _vector=" << (void*)_vector
				<< " new _vector= " << orig._vector << endl;
	}

	_dimension=orig._dimension;
	_vectorSize=orig._vectorSize;
	delete[] _vector;
	_vector=new VectorEntry[orig._vectorSize];
//	for(size_t i=0;i<_vectorSize;i++)
//		{
//			_vector[i]=orig._vector[i];
//		}
	copyArray(_vector,orig._vector,_vectorSize);

	return *this;
}

SparseVector& SparseVector::set(size_t index,double inValue)
{

	if((index<_vectorSize)&&(this->get(index)!=0))
		//if the rating isn't 0 change it
	{
		_vector[(this->getIndex(index))].setValue(inValue);
	}
	else //replace the old array and make a new array containing the new rating
	{
		VectorEntry *newVec = new VectorEntry[_vectorSize+1];
		//Make new array with old size+1
		if (index>_dimension)
		{ // Sets a new dimension if the index exceeds the old dimension
			_dimension=index+1;
		}

//		for(size_t j=0; j<_vectorSize; j++)
//		{ // Copy the old array
//			newVec[j]=_vector[j];
//		}
		copyArray(newVec,_vector,_vectorSize); // Copy the old array

		VectorEntry *newEntry = new VectorEntry(index,inValue);
		newVec[_vectorSize++]=*newEntry;

		delete[] _vector;
		_vector=0;
		_vector=new VectorEntry[_vectorSize];
		_vector=newVec;
	}
	return *this;
}

void SparseVector::makeZero()
{
	if (DEBUG)
	{
		cout << "SparseVector()::makeZero() _vector = " << (void*)_vector;
	}
	this->_vectorSize=0;
	delete[] _vector;
	_vector=0;

	if (DEBUG)
	{
		cout << " _vector=" << (void*)_vector << endl;
	}
}

double SparseVector::get(size_t requiredIndex) const
{
//	if (requiredIndex>=_dimension) //TODO: Check if should be > or >=
//	{
//		std::cerr << "get: Index is larger than dimension" << std::endl;
//	}
//	for (unsigned int  i=0;i<_vectorSize;i++)
//	{
//		if(_vector[i].index()==requiredIndex)
//		{
//			return _vector[i].value();
//		}
//	}

	size_t index=this->getIndex(requiredIndex);
	if (index<_vectorSize)
	{
		return _vector[index].value();
	}
	return 0;
}

size_t SparseVector::getIndex(size_t requiredIndex) const
{
	if (requiredIndex>=_dimension)
	{
		std::cerr << "Index is larger than dimension" << std::endl;
	}
	for (unsigned int  i=0;i<_vectorSize;i++)
	{
		if(_vector[i].index()==requiredIndex)
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

void SparseVector::scanAndSet(const Action toDo, const SparseVector& vector)
{
	for (size_t i=0;i<_dimension;i++)
	{
		switch (toDo)
		{
		case ADD:
			this->set(i,this->get(i)+vector.get(i));
			break;
		case SUBTRACT:
			this->set(i,this->get(i)-vector.get(i));
			break;
		}
	}
}

void SparseVector::add(const SparseVector& vector)
{
//	for (size_t i=0;i<_dimension;i++)
//	{
//		this->set(i,this->get(i)+vector.get(i));
//	}
	this->scanAndSet(ADD,vector);
}

void SparseVector::subtract(const SparseVector& vector)
{
//	for (size_t i=0;i<_dimension;i++)
//		{
//			this->set(i,this->get(i)-vector.get(i));
//		}

	this->scanAndSet(SUBTRACT,vector);
}

void SparseVector::scale(double factor)
{
	for (size_t i=0;i<_dimension;i++)
		{
			this->set(i,factor*(this->get(i)));
		}
}
