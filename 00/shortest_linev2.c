#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINES_MAX 100

unsigned* assign_line(unsigned num_lines, unsigned line_sizes[num_lines], unsigned num_ppl) {
  unsigned* chosen_lines = malloc(sizeof(unsigned) * num_ppl);
  unsigned smallest_line_idx = 0;
  unsigned smallest_line_size = UINT_MAX;
  for (unsigned person = 0; person < num_ppl; person++) {
    smallest_line_idx = 0;
    smallest_line_size = line_sizes[smallest_line_idx];
    for (unsigned line_idx = 1; line_idx < num_lines; line_idx++) {
      if (line_sizes[line_idx] < smallest_line_size) {
        smallest_line_idx = line_idx;
        smallest_line_size = line_sizes[line_idx];
      }
    }

    chosen_lines[person] = smallest_line_idx;
    line_sizes[smallest_line_idx]++;
  }

  return chosen_lines;
}

// returns -1 in case of failure
int parse_args(unsigned* num_lines, unsigned line_sizes[LINES_MAX], unsigned* num_ppl) {
  if (scanf("%u %u", num_lines, num_ppl) == EOF) {
    perror("could not scan first line");
    return -1;
  }

  // assumes: 
  // 1) all scanned args > 0
  // 2) all scanned args < LINES_MAX

  for (unsigned i = 0; i < *num_lines; i++) {
    if (scanf("%u", &(line_sizes[i])) == EOF) {
      perror("could not scan first line");
      return -1;
    }
  }

  return 0;
}

int main(void) {
  unsigned num_lines = 0;
  unsigned num_ppl = 0;
  unsigned line_sizes[LINES_MAX] = {0};

  if (parse_args(&num_lines, line_sizes, &num_ppl) < 0) {
    puts("parse args error encountered");
    exit(EXIT_FAILURE);
  }

  printf("num_lines: %u\n", num_lines);
  printf("num_ppl: %u\n", num_ppl);

  unsigned* assignments = assign_line(num_lines, line_sizes, num_ppl);
  printf("line_assignments: ");
  for (unsigned i = 0; i < num_ppl; i++) {
    printf("%u ", assignments[i]);
  }
  putchar('\n');

  free(assignments);
  return EXIT_SUCCESS;
}
