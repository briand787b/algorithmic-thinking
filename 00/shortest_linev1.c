#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 300

int shortest_line_index(int len, int arr[len]) {
  int shortest_idx = 0;
  for (int i = 1; i < len; i++) {
    if (arr[i] < arr[shortest_idx]) {
      shortest_idx = i;
    }
  }

  return shortest_idx;
}

int[] solve(int num_lines, int lines[len], int num_ppl) {
  for (int i = 0; i < num_ppl; i++) {
    lines[shortest_line_index(num_lines, lines)]++;
  }
}

int main(void) {
  int lines[MAX_LINES] = {0};
  int n, m;
  scanf("%d %d", &n, &m);

  return EXIT_SUCCESS;
}
