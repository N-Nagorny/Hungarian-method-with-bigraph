#include "square_matrix.h"
#include <unistd.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <iomanip>

SquareMatrix::SquareMatrix(size_t n)
{
    //заполнение рандомными числами
    this->n = n;
    if (n != 4 && n != 5 && n != 6 && n != 9) {
        arr = new unsigned int* [n];
        for (unsigned int i = 0; i < n; ++i){
            arr[i] = new unsigned int[n];
            for (unsigned int j = 0; j < n; ++j){
                if(i == j)
                    arr[i][j] == 0;
                else
                    arr[i][j] = rand() % 30;
            }
        }
    }
    else if (n == 4) {
        unsigned int a[4][4] = {{2, 0, 3, 0},
                                {0, 5, 1, 0},
                                {0, 1, 0, 2},
                                {3, 2, 0, 0}};
        arr = new unsigned int* [n];
        for (unsigned int i = 0; i < n; ++i){
            arr[i] = new unsigned int[n];
            for (unsigned int j = 0; j < n; ++j){
                    arr[i][j] = a[i][j];
            }
        }
    }
    else if (n == 5) {
        unsigned int a[5][5] = {{13, 16, 27, 25, 23},
                                {25, 16 ,12	,9	,1 },
                                { 2, 7  ,20	,19	,23},
                                {16, 0  ,6	,22	,16},
                                {11, 8  ,27	,9	,2 }};
        arr = new unsigned int* [n];
        for (unsigned int i = 0; i < n; ++i){
            arr[i] = new unsigned int[n];
            for (unsigned int j = 0; j < n; ++j){
                    arr[i][j] = a[i][j];
            }
        }
    }
    else if(n == 6) {
        unsigned int a[6][6] = {{13 ,	16,	27,	25,	23,	25},
                                {16 ,	12,	9 ,  1,	2 ,  7},
                                {20 ,	19,	23,	16,	0 ,  6},
                                {22 ,	16,	11,	8 , 27,	9 },
                                {2  ,  20  ,  2,	13,	7 , 25},
                                {29 ,	12,	12,	18,	29,	27}};
        arr = new unsigned int* [n];
        for (unsigned int i = 0; i < n; ++i){
            arr[i] = new unsigned int[n];
            for (unsigned int j = 0; j < n; ++j){
                    arr[i][j] = a[i][j];
            }
        }

    }
    else if (n == 9) {
    unsigned a[9][9] ={{ 0,        6,       21,       10,       13,       17,        7,  1,  0},
                       { 0,        4,       13,       17,       21,       27,       19,  1,  9},
                       {16,       13,       12,        0,       24,        8,        0, 16,  0},
                       { 3,        0,       22,       17,        5,        7,       12, 21, 21},
                       { 5,       11,        0,       12,        4,        0,       17, 23, 10},
                       { 4,        8,       18,        0,        0,       25,       17,  0, 21},
                       {20,        0,        3,       12,       13,        0,       13, 11, 12},
                       {15,       17,        0,        2,        0,        6,        9, 14,  7},
                       { 5,       11,       14,       18,       10,       12,        0, 15,  4}};
    arr = new unsigned int* [n];
    for (unsigned int i = 0; i < n; ++i){
        arr[i] = new unsigned int[n];
        for (unsigned int j = 0; j < n; ++j){
                arr[i][j] = a[i][j];
        }
    }
   }
}

//конструктор копирования
SquareMatrix::SquareMatrix(const SquareMatrix& sm) {
    n = sm.n;
    arr = new unsigned int* [n];
    for (unsigned int i = 0; i < n; ++i){
        arr[i] = new unsigned int[n];
        for (unsigned int j = 0; j < n; ++j){
            arr[i][j] = sm.arr[i][j];
        }
    }
}

SquareMatrix::~SquareMatrix() {
    for (unsigned int i = 0; i < n; ++i) {
        delete arr[i];
    }
    delete arr;
}

//Печать матрицы
void SquareMatrix::print() {
    for(unsigned int i = 0; i < n; ++i) {
        for(unsigned int j = 0; j < n; ++j) {
            std::cout << std::setfill(' ') << std::setw(n) << arr[i][j];
        }
        std::cout << std::endl;
    }
}

//транспонирование матрицы
void SquareMatrix::transpose() {
    unsigned int ** tmp = new unsigned int* [n];
    for (unsigned int i = 0; i < n; ++i) {
        tmp[i] = new unsigned int[n];
    }
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            tmp[j][i] = arr[i][j];
        }
    }
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            arr[i][j] = tmp[i][j];
        }
    }
}


void SquareMatrix::subMinFromRows() {
    for (unsigned int i = 0; i < n; ++i)   {
       unsigned int min_row = arr[i][0];
       for (unsigned int j = 0; j < n; ++j)  {
           if (arr[i][j] < min_row) {
               min_row = arr[i][j];
           }
       }
       //вычитаем минимум
       for (unsigned int j = 0; j < n; j++)
           arr[i][j] -= min_row;
    }
}

//нормализуем
void SquareMatrix::getZeros() {
    subMinFromRows();
    bool each_row_has_zero = true;
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (arr[i][j] == 0) {
                break;
            }
            each_row_has_zero = false;
        }
    }
    if (!each_row_has_zero) {
        transpose();
        subMinFromRows();
        transpose();
    }
}

unsigned SquareMatrix::getElement(unsigned i, unsigned j) {
    return arr[i][j];
}
unsigned SquareMatrix::getSize() {
    return n;
}

//венгерский метод
void SquareMatrix::hungarian(const std::vector<GraphArrow> &indep_zeros) {
    std::cout << "New hung!!!" << std::endl;
    unsigned int** B = new unsigned int*[n];
    for (unsigned int i = 0; i < n; ++i) {
        B[i] = new unsigned int[n];
        for (unsigned int j = 0; j < n; ++j) {
            B[i][j] = 0;
        }
    }

    bool is_row_marked[n], is_col_marked[n];
    for (unsigned int i = 0; i < n; ++i) {
        is_col_marked[i] = false;
        is_row_marked[i] = false;
    }
    for (const GraphArrow& arrow : indep_zeros) {
        std::cout << arrow.start << ' ' << arrow.end << std::endl;
    }
    std::vector<unsigned> marked_rows, marked_cols;
    bool finish = false;
    for (unsigned int i = 0; i < n; ++i) {
        if (std::find_if(indep_zeros.begin(), indep_zeros.end(),
                        [i] (const GraphArrow& x) {
                            return x.start == i;
                        }) == indep_zeros.end() && is_row_marked[i] == false) {
            std::cout << "Row " << i << " doesn't contain indep zero" << std::endl;
            is_row_marked[i] = true;
            marked_rows.push_back(i);
        }
    }


    while(!finish) {
        marked_cols.clear();
        for (const unsigned row : marked_rows) {
            for (unsigned int j = 0; j < n; ++j) {
                if (is_col_marked[j] == false && arr[row][j] == 0) {
                    is_col_marked[j] = true;
                    marked_cols.push_back(j);
                }
            }
        }
        if (marked_cols.empty()) {
            finish = true;
            break;
        }
        marked_rows.clear();
        for (const unsigned col : marked_cols) {
            for (unsigned int k = 0; k < n; ++k) {
                if (std::find_if(indep_zeros.begin(), indep_zeros.end(),
                                [k, col] (const GraphArrow& x) {
                                    return x.start == k && x.end == col;
                                }) != indep_zeros.end() && is_row_marked[k] == false) {
                    is_row_marked[k] = true;
                    marked_rows.push_back(k);
                }
            }
        }
        if (marked_rows.empty()) {
            finish = true;
        }
    }

    for (unsigned int i = 0; i < n; ++i) {
        if (is_col_marked[i]) {
            for (unsigned int j = 0; j < n; ++j) {
                B[j][i]++;
            }
        }
        if (!is_row_marked[i]) {
            for (unsigned int j = 0; j < n; ++j) {
                B[i][j]++;
            }
        }
    }

    std::cout << "Hungarian while: "  << std::endl;

    for(unsigned int i = 0; i < n; ++i) {
        for(unsigned int j = 0; j < n; ++j) {
            std::cout << B[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    //ищем минимальный элемент
    unsigned int nonFilledMin = UINT_MAX;
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (B[i][j] == 0) {
                if (arr[i][j] < nonFilledMin) {
                    nonFilledMin = arr[i][j];
                }
            }
        }
    }
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (B[i][j] == 0) {
                arr[i][j] -= nonFilledMin;
            } else if (B[i][j] == 2) {
                arr[i][j] += nonFilledMin;
            }
        }
    }
}
