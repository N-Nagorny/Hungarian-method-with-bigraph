#ifndef BIGRAPH_H
#define BIGRAPH_H

#include <square_matrix.h>

class bigraph
{
public:
    bigraph() = delete;
    bigraph(const SquareMatrix &graph);
    bool isSuccessful();
    std::vector<GraphArrow> getResult();
private:
    bool searchIndepZeros();
    bool DFS(std::vector<GraphArrow> graph_tmp, std::vector<std::vector<GraphArrow>::iterator>& vec, const GraphArrow& arrow,unsigned debug);
    std::vector<GraphArrow> graph, result;
    SquareMatrix arr;
    bool* s = NULL, *t = NULL;
};

#endif // BIGRAPH_H
