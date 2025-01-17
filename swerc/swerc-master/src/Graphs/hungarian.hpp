#include <bits/stdc++.h>
using namespace std;

typedef int32_t i32;

int hungarian(vector<vector<i32>>& value) {
  size_t n = value.size();
  vector<i32> row(n), col(n);
  for(size_t i = 0; i < n; i++) {
    row[i] =
        *min_element(value[i].begin(), value[i].end());
  }
  for(size_t i = 0; i < n; i++) {
    i32 min_nonzero = value[0][i] - row[0];
    for(size_t j = 1; j < n; j++) {
      min_nonzero = min(min_nonzero, value[j][i] - row[j]);
    }
    col[i] = min_nonzero;
  }
  vector<i32> selected_for_row(n, -1),
      selected_for_col(n, -1);
  size_t solution_size = 0;
  i32 solution = 0;
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      if(value[i][j] - row[i] - col[j] == 0 &&
         selected_for_row[i] < 0 &&
         selected_for_col[j] < 0) {
        selected_for_row[i] = j;
        selected_for_col[j] = i;
        solution_size++;
      }
    }
  }
  vector<bool> visited(n * 2);
  auto matched = [&selected_for_col,
                  &selected_for_row](size_t node) -> bool {
    size_t true_node = node >> 1;
    if(node & 1) {
      return selected_for_col[true_node] >= 0;
    } else {
      return selected_for_row[true_node] >= 0;
    }
  };
  function<bool(size_t)> search_augmenting =
      [&n, &visited, &value, &col, &row, &selected_for_col,
       &selected_for_row, &matched,
       &search_augmenting](size_t node) -> bool {
    visited[node] = true;
    if((node & 1) && !matched(node)) {
      return true;
    }
    size_t true_node = node >> 1;
    for(size_t i = 0; i < n; i++) {
      if(node & 1) { // DESTRA (colonne)
        if(value[i][true_node] - row[i] - col[true_node] ==
               0 &&
           !visited[i * 2] &&
           (size_t)selected_for_col[true_node] == i) {
          if(search_augmenting(i * 2)) {
            return true;
          }
        }
      } else { // SINISTRA (righe)
        if(value[true_node][i] - row[true_node] - col[i] ==
               0 &&
           !visited[i * 2 + 1] &&
           (size_t)selected_for_row[true_node] != i) {
          if(search_augmenting(i * 2 + 1)) {
            selected_for_col[i] = true_node;
            selected_for_row[true_node] = i;
            return true;
          }
        }
      }
    }
    return false;
  };

  while(solution_size < n) {
    bool at_least_one = true;
    while(at_least_one) {
      at_least_one = false;
      fill(visited.begin(), visited.end(), false);
      for(size_t i = 0; i < n; i++) {
        if(!visited[i * 2] && !matched(i * 2)) {
          if(search_augmenting(i * 2)) {
            solution_size++;
            at_least_one = true;
          }
        }
      }
    }
    if(solution_size >= n) {
      break;
    }
    i32 min_value = INT_MAX;
    for(size_t i = 0; i < n; i++) {
      for(size_t j = 0; j < n; j++) {
        if(visited[i * 2] && !visited[j * 2 + 1]) {
          min_value = min(min_value,
                          value[i][j] - row[i] - col[j]);
        }
      }
    }
    assert(min_value > 0 && min_value < INT_MAX);
    for(size_t i = 0; i < n; i++) {
      if(!visited[i * 2 + 1]) {
        col[i] += min_value;
      }
      if(!visited[i * 2]) {
        row[i] -= min_value;
      }
    }
  }
  solution = 0;
  for(size_t i = 0; i < n; i++) {
    solution += row[i] + col[i];
  }
  return solution;
}
