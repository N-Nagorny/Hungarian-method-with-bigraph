#include <iostream>
#include <unistd.h>

#include <hungarian.h>
#include <bigraph.h>
#include <square_matrix.h>


void getAnswer(const std::vector<GraphArrow>& graph, unsigned int n) {
    unsigned int** res = new unsigned int*[n];

    for (const auto& arrow : graph) {
        res[arrow.start][arrow.end] = 1;
    }
    std::cout << "Result: " << n << std::endl;
    for(unsigned int i = 0; i < n; ++i) {
        for(unsigned int j = 0; j < n; ++j) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{
    bool is_solvable = false;

    int n = 0;
    std::cout << "Введите размер матрицы NxN: " << std::endl;
    std::cin >> n;
    std::cout << "Матрица:" << std::endl;
    SquareMatrix A = SquareMatrix(n);
    A.print();

    SquareMatrix A_copy = A;

    std::cout << "Нормализация: " << std::endl;
    A_copy.getZeros();
    A_copy.print();

    bigraph *graph = new bigraph(A_copy);
    if (graph->isSuccessful()) {
        getAnswer(graph->getResult(), n);
    } else {
        while (!is_solvable)
        {
            A_copy.hungarian(graph->getResult());
            A_copy.print();
            std::cout << "Нормализация: " << std::endl;
            A_copy.getZeros();
            A_copy.print();
            delete graph;

            graph = new bigraph(A_copy);
            if (graph->isSuccessful()) {
                is_solvable = true;
                getAnswer(graph->getResult(), n);
            } else {
                std::cout << "Hungarian method" << std::endl;
            }
        }
    }
    return 0;
}
