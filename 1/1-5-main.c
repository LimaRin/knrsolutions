#include <stdio.h>
#define FAHRBEG 300
#define FAHREND 0
#define FAHRSTEP 20
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
  int fahr;  
  int i, j;
  tablerow arr[] = {{"fahr", PLACEHOLDER}, {"cels", PLACEHOLDER}, {NULL, 0}};
  header(arr);

  for (fahr = FAHRBEG; fahr >= FAHREND; fahr -= FAHRSTEP) {
    printf("| %*d | %*.1f |\n", PLACEHOLDER, fahr, PLACEHOLDER, (5.0/9.0)*(fahr-32));
  }
  
  line(arr);

  return 0;
}
