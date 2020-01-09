//      Algorithm


// I. Ввод исходной матрицы A.

// bool is_solvable = false;


// == ЦИКЛ ПОКА is_solvable == false ==
/*
 * II. Венгерский метод
 *
 * 1) Создание матрицы В, заполненной нулями.
 * 2) Создание двух массивов zero_row и zero_col для подсчета нулей.
 *
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


#include <iostream>

using namespace std;


////заполнение
//void fill_array(int** arr,int n){
//    for (int i = 0; i < n; i++){
//        arr[i] = new int[n];
//        for (int j = 0; j < n; j++){
//            arr[i][j] = rand() % 30;
//        }
//    }
//}

////печать матрицы
//void Hungarian::print_arr(int **arr, int n){
//    printf("Наша матрица: %i\n", n);
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            printf("%3d ",arr[i][j]);
//        }
//        cout << endl;
//    }
//}


//приведение матрицы по строкам
void Hungarian::minimal_row(int **arr, int n){
    for (int i = 0; i < n; i++)   {
           int min_row = arr[i][0];
           for (int j = 0; j < n; j++)  {
               if (arr[i][j] < min_row) {
                   min_row = arr[i][j];
               }
           }
           cout << endl;
           cout << "Minimum в строке " << i+1 << ": " << min_row << endl;

           //вычитаем минимум
           for (int j = 0; j < 4; j++)
               arr[i][j] -= min_row;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++)  {
               cout << arr[i][j] << " ";
           }
           cout << endl;
    }
    cout << endl;
}

//приведение по столбцам
void Hungarian::minimal_coll(int **arr, int n){
    for(int j = 0; j < n; ++j){
        int min_coll = arr[0][j];
        for(int i = 0; i < n; ++i){
            if (arr[i][j] < min_coll) {
                min_coll = arr[i][j];
            }
        }
        cout << "Minimum в столбце " << j+1 << ": " << min_coll << endl;

        for(int i = 0; i < n; ++i)
            arr[i][j] -= min_coll;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++)  {
               cout << arr[i][j] << " ";
           }
           cout << endl;
    }
    cout << endl;
}

// I. Ввод исходной матрицы A.

// bool is_solvable = false;
//------------------------------------------------------------------

// == ЦИКЛ ПОКА is_solvable == false ==




void Hungarian::fill_array_B(int** arr,int n){
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
        for (int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

}




