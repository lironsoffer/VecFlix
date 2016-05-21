#include "VectorTests.h"
#include "SparseVector.h"
#include "Print.h"
#include <iostream>

static void testCreateAndPrint();
static void testGetNonZeros();
static void testMakeZero();
static void testMakeStandardBasis();
static void testSetValue();
static void testAdd();
static void testCopyAndAssign();
static void testScale();
static void testSubtract();

void runVectorTests()
{
    testCreateAndPrint();
    testGetNonZeros();
    testMakeZero();
    testMakeStandardBasis();
    testSetValue();
    testCopyAndAssign();
    testAdd();
//    testScale();
    testSubtract();
}

void testCreateAndPrint()
{
    std::cout << "testCreateAndPrint" << std::endl;

    VectorEntry entries[] = {VectorEntry(3, 4), VectorEntry(5, -3)};
    std::vector<VectorEntry> entriesVector(entries, entries + 2);
    SparseVector vector(8, entriesVector);
    printVector(vector);
}

void testGetNonZeros()
{
    std::cout << "testGetNonZeros" << std::endl;

    VectorEntry entries[] = {VectorEntry(3, 4), VectorEntry(5, -3)};
    std::vector<VectorEntry> entriesVector(entries, entries + 2);
    SparseVector vector(8, entriesVector);

    std::vector<VectorEntry> emptyVector;
    vector.getNonZeros(emptyVector);
    printEntries(emptyVector);

    std::vector<VectorEntry> nonEmptyVector;
    nonEmptyVector.push_back(VectorEntry(200, 300));
    nonEmptyVector.push_back(VectorEntry(300, 400));
    vector.getNonZeros(nonEmptyVector);
    printEntries(nonEmptyVector);
}

void testMakeZero()
{
    std::cout << "testMakeZero" << std::endl;

    VectorEntry entries[] = {VectorEntry(3, 4), VectorEntry(5, -3)};
    std::vector<VectorEntry> entriesVector(entries, entries + 2);
    SparseVector vector(8, entriesVector);

    vector.makeZero();
    printVector(vector);
}

void testMakeStandardBasis()
{
    std::cout << "testMakeStandardBasis" << std::endl;

    SparseVector vector1(5);

    VectorEntry entries[] = {VectorEntry(3, 4), VectorEntry(5, -3)};
    std::vector<VectorEntry> entriesVector(entries, entries + 2);
    SparseVector vector2(8, entriesVector);

    vector1.makeStandardBasis(3);
    vector2.makeStandardBasis(6);

    printVector(vector1);
    printVector(vector2);
}

void testSetValue()
{
    std::cout << "testSetValue" << std::endl;
    SparseVector vector(8);
    vector.set(5, -4).set(7, 3).set(2, 5).set(3, -5);

    printVector(vector);
}

void testCopyAndAssign()
{
    std::cout << "testCopyAndAssign" << std::endl;

    SparseVector original(5);
    original.set(1, 2).set(4, -3);
    printVector(original);

    SparseVector copy = original;
    printVector(copy);

    SparseVector toBeAsigned(10);
    toBeAsigned.set(1, 3).set(6, -2).set(7, 4);
    toBeAsigned = original;
    printVector(toBeAsigned);
}

void testAdd()
{
    std::cout << "testAdd" << std::endl;

    SparseVector vector1(10);
    SparseVector vector2(10);

    vector1.set(3, 5).set(6, 1).set(7, 3);
    vector2.set(3, -2).set(7, 4).set(8, 3);

    printVector(vector1);
    printVector(vector2);
    printVector(add(vector1, vector2));
}
//
//void testScale()
//{
//    std::cout << "testScale" << std::endl;
//
//    SparseVector vector(7);
//    vector.set(0,-5).set(3, 3).set(6, 1);
//
//    printVector(scale(vector, 4));
//}
//
void testSubtract()
{
    std::cout << "testSubtract" << std::endl;

    SparseVector vector1(SparseVector(9).set(0,2).set(4,-1).set(8,-3));
    SparseVector vector2(SparseVector(9).set(1,2).set(4,5).set(7,1));

    printVector(vector1);
    printVector(vector2);
    printVector(subtract(vector1, vector2));
}

