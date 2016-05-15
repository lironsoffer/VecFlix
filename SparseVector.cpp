#include "SparseVector.h"
/*
SparseVector scale(const SparseVector& vector, double factor)
{
    SparseVector result = vector;
    result.scale(factor);
    return result;
}

SparseVector add(const SparseVector& left, const SparseVector& right)
{
    SparseVector result = left;
    result.add(right);
    return result;
}

SparseVector subtract(const SparseVector& left, const SparseVector& right)
{
    SparseVector result = left;
    result.subtract(right);
    return result;
}*/

SparseVector::SparseVector(unsigned int dim, std::vector<VectorEntry> &entries) : _dim(dim), _vector(new VectorEntry[entries.size()])
{
	for(size_t i=0;i<entries.size();i++)
	{
		_vector[i]=new VectorEntry(entries[i]);
	}
}

void SparseVector::makeZero()
{
	for (size_t i=0;i<)
}
