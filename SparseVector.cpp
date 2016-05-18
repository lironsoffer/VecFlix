#include "SparseVector.h"
/*
SparseVector scale(const SparseVector& vector, double factor)
{
    SparseVector result = vector;
    result.scale(factor);
    return result;
}
*/
/*
SparseVector add(const SparseVector& left, const SparseVector& right)
{
    SparseVector result(left);
    result.add(right);
    return result;
}
*/

/*
SparseVector subtract(const SparseVector& left, const SparseVector& right)
{
    SparseVector result = left;
    result.subtract(right);
    return result;
}
*/
/*
SparseVector SparseVector::operator+ (const SparseVector &a, const SparseVector &b)
{
	SparseVector newVector(a.dimension());
	_dimension=this->a.dimension();
	for(size_t temp=0; temp<a._vectorSize; temp++)
		{
		newvector.set((a[temp].getIndex(temp),a[temp].indexValue());
		}
	for(size_t temp2=0; temp2<b._vectorSize; temp2++)
		{
		newVector.add(b);
		}

}
*/
/*
SparseVector SparseVector::operator= (size_t dim, size_t VectorSize, VectorEntry *vector)
{

}
*/
SparseVector::SparseVector(size_t dimension, std::vector<VectorEntry> &entries)
{
	 //_dimension(dimension),_vectorSize(entries.size()), _vector(new VectorEntry[entries.size()])
	for(size_t  i=0;i<_vectorSize;i++)
	{
		_vector[i]=entries[i];
	}
}

SparseVector::SparseVector(const SparseVector & orig)
{
	_dimension=orig.dimension();
	_vectorSize=orig.vectorSize();
	_vector=orig._vector;
}
SparseVector& SparseVector::set(size_t  index,double inValue)
{

	if(this->get(index)!=0) //if the rating isn't 0 change it
	{
		_vector[(this->getIndex(index))].setValue(inValue);
	}
	else //  replace the old arry and make a new arry containing the new rating
	{

		size_t newSize=_vectorSize+1;
		SparseVector* newVec&=new SparseVector[newSize];
		for(size_t x=0; x<newSize; x++)
		{
			newVec[x]=_vector[x];
			if (x==(newSize-1))
			{
				newVec[x]=(index,inValue);
				return newVec;
			}
		}
	}
	return (_vector);
}

}
void SparseVector::makeZero()
{
	_vectorSize=0;
	delete[] _vector; //TODO: Read again the chapter about delete
}

double SparseVector::get(size_t  indexvalue) const
{
	if (indexvalue>=_dimension) //TODO: Check if should be > or >=
	{
		std::cerr << "Index is larger than dimension" << std::endl;
	}

		for (size_t  i=0;i<_vectorSize;i++)
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
	for (size_t  i=0;i<_vectorSize;i++)
	{
		vector.push_back(_vector[i]);
	}
}

void SparseVector::makeStandardBasis(size_t  index)
{
	this->makeZero();
	this->set(index,1);
}

void SparseVector::add(const SparseVector& vector)
{
	for (size_t  i=0;i<_vectorSize;i++)
	{
		double num;
		num=vector.get(i) + vector.get(_vector[i].index());
	}
}
