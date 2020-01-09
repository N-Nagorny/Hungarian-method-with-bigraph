#include "bigraph.h"
#include <algorithm>
#include <iostream>

bigraph::bigraph(const SquareMatrix& arr) : arr(arr)
{
    s = new bool[this->arr.getSize()];
    t = new bool[this->arr.getSize()];
    for(unsigned int i = 0; i < this->arr.getSize(); ++i) {
        s[i] = true;
        t[i] = true;
    }
}

//возвращает true, если найдено решение, (т.е s=t=false)
bool bigraph::isSuccessful() {
    return searchIndepZeros();
}
std::vector<GraphArrow> bigraph::getResult() {
    return result;
}

//поиск в глубину
bool bigraph::DFS(std::vector<GraphArrow> graph_tmp,
                  std::vector<std::vector<GraphArrow>::iterator>& vec,
                  const GraphArrow& arrow, unsigned debug) {
    vec.push_back(std::find(graph.begin(), graph.end(), arrow));
    auto arrow_it = std::find(graph_tmp.begin(), graph_tmp.end(), arrow);

    //если стрелка слева направо и выход есть
    if (arrow_it->is_left && t[arrow_it->end] == true) {
        t[arrow_it->end] = false;
        return true;
    }

    //вектор всех дальнейших путей
    std::vector<GraphArrow> DFS_input;
    for (auto& x : graph_tmp) {
        //проходим по "истории" графа и ищем в нем первернутые стрелки
         if (std::find_if(vec.begin(), vec.end(),
                          [x] (const std::vector<GraphArrow>::iterator xx) {
                              return xx->is_reversed(x);
                          }) == vec.end()) {
             //если стрелка, которую мы обходим во временном графе не та, на которой стоим и
             //если конец текущей равен началу следующей и
             //если текущая стрелка слева направо не равна стрелке в графе слева направо,
             //то добавляем в сложный путь
             if (x != *arrow_it && x.start == arrow_it->end && x.is_left != arrow_it->is_left) {
                DFS_input.push_back(x);
             }
        }
    }
    //разворащиваем все, что нашли
    for (const auto& x : DFS_input) {
        arrow_it->reverse();        
        //вызываем DFS для следующей стрелки и идем дальше вглубь
        if (DFS(graph_tmp, vec, x, ++debug)) {
            return true;
        }
        //иначе очищаем все пути
        else {
            std::cout << "pop_back" << std::endl;
            vec.pop_back();
        }
    }
    return false;
}

//если найдены все независимые нули
bool bigraph::searchIndepZeros() {
    for (unsigned int i = 0; i < arr.getSize(); ++i) {
      for (unsigned int j = 0; j < arr.getSize(); ++j) {
        if (arr.getElement(i, j) == 0) {
          graph.push_back(GraphArrow(i, j, true));
        }
      }
    }

    //ищем простые пути
    for (auto& arrow : graph) {
       if (s[arrow.start] == true) {
          if (t[arrow.end] == true) {

                std::cout << "push_back " << arrow.start << ' ' << arrow.end << std::endl;
                result.push_back(arrow);

            s[arrow.start] = false;
            t[arrow.end] = false;
            arrow.reverse();
          }
       }
    }

    //ищем сложные пути
    for (const auto& arrow : graph) {
        //если стрелска слева направо и существует вход
        if (arrow.is_left == true && s[arrow.start] == true) {
            std::vector<std::vector<GraphArrow>::iterator> vec;
            //временная копия
            std::vector<GraphArrow> graph_tmp(graph);
            //обрабатываем очередное возможное начало сложного пути
            std::cout << "Long path" << ' ' << arrow.start << ' ' << arrow.end << std::endl;
            //если нашли сложный путь
            if (DFS(graph_tmp, vec, arrow, 1)) {
                s[arrow.start] = false;
                for (auto& xx : vec) {
                    //ищем в ответе обратную стрелку той, что обрабатываем в длинном пути
                    //и возвращаем её итератор
                    std::vector<GraphArrow>::iterator iter = std::find_if(result.begin(), result.end(),
                                                                          [xx] (GraphArrow& x) {
                                                                                return x.is_reversed(*xx);
                                                                          });
                    //если обр. срелка есть, то удаляем ее
                    if (iter != result.end()) {
                      std::cout << "erase " << iter->start << ' ' << iter->end << std::endl;
                      result.erase(iter);
                    }
                    else {
                      std::cout << "push_back " << xx->start << ' ' << xx->end << std::endl;
                      result.push_back(*xx);
                    }
                    //разворачиваем после прохода
                    xx->reverse();
                }
            }
        }
    }
    //если есть вход или выход, то false
    for (unsigned int i = 0; i < arr.getSize(); ++i) {
      if (s[i] == true || t[i] == true) {
        return false;
      }
      if (i == arr.getSize() - 1)
        return true;
    }
}
