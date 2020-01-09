//Algorithm
// I. Ввод исходной матрицы A.

// bool is_solvable = false;

// == ЦИКЛ ПОКА is_solvable == false ==

/*
 * II. Венгерский метод
 *
 * 1) Создание матрицы В, заполненной нулями.
 * 2) Создание двух массивов zero_row и zero_col для подсчета нулей.

 * === ЦИКЛ ПОКА zero_row И zero_col СОДЕРЖАТ НУЛИ ===
 * 3) Подсчет нулей в столбцах и строках среди элементов матрицы А,
 * которым соответствуют нули в матрице B.
 * 4) Поиск максимального эл-та max_1 среди эл-тов zero_row и zero_col.
 * 5) Поиск максимального эл-та max_2 в массиве, противоположном массиву эл-та max_1.
 * 6) Прибавление единиц к каждому элементу матрицы B, находящемуся в строке или столбце,
 * соответствующим max_1 и max_2.
   === КОНЕЦ ЦИКЛА ===
*/
// III. Нормализация


// IV. Метод двудольного графа
// int n; //размерность матрицы А
// struct {
//   int start;
//   int end;
//   graph_arrow(int i, int j) {
//     start = i;
//     end = j;
//   };
// } graph_arrow;
// graph_arrow graph[];
// int i, j, graph_i = 0;
// for (i = 0; i < n; ++i) {
//   for (j = 0; j < n; ++j) {
//     if (A[i][j] == 0) {
//       graph[graph_i++] = graph_arrow(i, j);
//     }
//   }
// }
// bool s[n](true), t[n](true);
//
// for (i = 0; i < graph_i; ++i) {
//   if (s[graph[graph_i].start] == true && t[graph[graph_i].end] == true) {
//     swap(graph[graph_i].start, graph[graph_i].end);
//     s[graph[graph_i].start] = false;
//     t[graph[graph_i].end] = false;
//   }
// }
//
// for (i = 0; i < n; ++i) {
//   if (s[i] == true || t[i] == true) {
//     break;
//   }
//   if (i == n - 1)
//     is_solvable = true;
// }
// == КОНЕЦ ЦИКЛА ==

// V. Расчёт результирующей матрицы
//------------------------------------------------------------------------------------



#ifndef GRAPH_ARROW_H
#define GRAPH_ARROW_H

struct GraphArrow {
  unsigned int start;
  unsigned int end;
  bool is_left;
  GraphArrow(unsigned int i, unsigned int j, bool k) {
    start = i;
    end = j;
    is_left = k;
  }
  bool is_reversed(const GraphArrow& x) {
      return x.start == this->end && x.end == this->start && x.is_left != this->is_left;
  }
  void reverse() {
      unsigned tmp = this->start;
      this->start = this->end;
      this->end = tmp;
      this->is_left = !this->is_left;
  }
  bool operator== (const GraphArrow& x) {
      return this->start == x.start && this->end == x.end && this->is_left == x.is_left;
  }
  bool operator!= (const GraphArrow& x) {
      return this->start != x.start || this->end != x.end || this->is_left != x.is_left;
  }
};


#endif // GRAPH_ARROW_H
