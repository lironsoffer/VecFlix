#include "SparseVector.h"
#include "Print.h"
#include <iostream>

void printVector(const SparseVector& vector)
{
    std::cout << "[";
    const char* separator = "";
    for(size_t i = 0; i < vector.dimension(); ++i)
    {
        std::cout << separator << vector.get(i);
        separator = ", ";
    }
    std::cout << "]" << std::endl;
}

void swap(VectorEntry& left, VectorEntry& right)
{
    VectorEntry temp = left;
    left = right;
    right = temp;
}

void sortByIndex(std::vector<VectorEntry>& entries)
{
    for(size_t i = 0; i < entries.size(); ++i)
        for(size_t j = i + 1; j < entries.size(); ++j)
            if (entries[i].index() > entries[j].index())
                swap(entries[i], entries[j]);
}

void printEntries(std::vector<VectorEntry> entries)
{
    sortByIndex(entries);

    std::cout << "{";
    const char* separator = "";
    for(std::vector<VectorEntry>::const_iterator it = entries.begin();
        it != entries.end(); ++it)
    {
        std::cout << separator
                  << "(" << it->index() << ", " << it->value() << ")";
        separator = ", ";
    }
    std::cout << "}" << std::endl;
}