#include <stdio.h>
#define CELSBEG -150
#define CELSEND 150
#define CELSSTEP 20
#define PLACEHOLDER 8

typedef struct {
  const char *head;
  int place;
} tablerow;

void line(const tablerow *arr) {
  int i;
  if (arr->head != NULL)
    putchar('+');
  while (arr->head != NULL) {
    for (i = 0; i < arr->place + 2; ++i)
      putchar('-');
    putchar('+');
    ++arr;
  }
  putchar('\n');
}

void heads(const tablerow *arr) {
  if (arr->head != NULL)
    putchar('|');
  while (arr->head != NULL) {
    printf(" %*s |", arr->place, arr->head);
    ++arr;
  }
  putchar('\n');
}

void header(const tablerow *arr) {
  line(arr);
  heads(arr);
  line(arr);
}

int main() {
  int cels;  
  int i, j;
  tablerow arr[] = {{"cels", PLACEHOLDER}, {"fahr", PLACEHOLDER}, {NULL, 0}};
  header(arr);

  for (cels = CELSBEG; cels <= CELSEND; cels += CELSSTEP) {
    printf("| %*d | %*.1f |\n", PLACEHOLDER, cels, PLACEHOLDER, (9.0/5.0)*cels+32);
  }
  
  line(arr);

  return 0;
}
