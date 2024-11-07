#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Course {
  int id;
  char *name;
};

struct Course *make_course(int id, char *name) {
  struct Course *new_course = malloc(sizeof(struct Course));
  new_course->id = id;
  new_course->name = name;

  return new_course;
}
int main() {
  struct Course *cstart = make_course(0x001, "cstart");
  printf("Welcome to CS%d: %s!\n", cstart->id, cstart->name);
  free(cstart);

  return 0;
}
