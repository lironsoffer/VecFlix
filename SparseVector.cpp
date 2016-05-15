#include "SparseVector.h"

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
}





