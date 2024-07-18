#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// error condition is return value 0
unsigned parse_unsigned(char str[]) {
  unsigned long num_lines = strtoul(str, NULL, 0);
  switch (num_lines) {
    case EINVAL:
      printf("could not convert %s to unsigned long\n", str);
      return 0;
    case ERANGE:
      printf("%s is out of range\n", str);
      return 0;
    case 0:
      printf("could not convert %s to unsigned long\n", str);
      return 0;
  }

  if (errno) {
    perror("could not convert %s to unsigned long");
    exit(EXIT_FAILURE);
  }

  if (num_lines > 100) {
    printf("%lu > 100\n", num_lines);
  }

  return (unsigned)num_lines;
}

int main(int argc, char* argv[argc]) {
  if (argc < 4) {
    puts("please provide two positive integer arguments, followed by output filename");
    exit(EXIT_FAILURE);
  }

  unsigned num_lines = parse_unsigned(argv[1]);
  if (!num_lines)
    exit(EXIT_FAILURE);

  unsigned num_ppl = parse_unsigned(argv[2]);
  if (!num_ppl)
    exit(EXIT_FAILURE);

  FILE* fp = fopen(argv[3], "w");
  if (!fp) {
    perror("could not open file");
    exit(EXIT_FAILURE);
  }

  printf("num_lines: %u\n", num_lines);
  printf("num_ppl: %u\n", num_ppl);
  if (fprintf(fp, "%u %u\n", num_lines, num_ppl) == EOF) {
    perror("could not put string in file");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));
  for (unsigned i = 0; i < num_lines; i++) {
    if (fprintf(fp, "%d ", rand() % 100) == EOF) {
      perror("could not put rand data in file");
      fclose(fp);
      exit(EXIT_FAILURE);
    }
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
