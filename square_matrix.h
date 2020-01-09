#ifndef MATRIX_H
#define MATRIX_H

#include "graph_arrow.h"
#include <vector>
#include <cstdlib>

class SquareMatrix
{
public:
    SquareMatrix() = delete;
    SquareMatrix(size_t n);
    SquareMatrix(const SquareMatrix& sm);
    ~SquareMatrix();
    void print();
    void transpose();
    void getZeros();
    bool createBigraph(std::vector<GraphArrow> *);
    void old_hungarian(const std::vector<GraphArrow> &indep_zeros);
    void hungarian(const std::vector<GraphArrow> &indep_zeros);
    unsigned getElement(unsigned i, unsigned j);
    unsigned getSize();
private:
    void subMinFromRows();

    unsigned int** arr;
    size_t n;
};

#endif // MATRIX_H
