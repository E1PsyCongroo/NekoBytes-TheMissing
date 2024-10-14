#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char hello_str[6];

  hello_str[0] = 'h';
  hello_str[1] = 'e';
  hello_str[2] = 'l';
  hello_str[3] = 'l';
  hello_str[4] = 'o';

  hello_str[5] = '\n';

  assert(!strcmp("hello", hello_str));
  printf("prints hello: %s\n", hello_str);

  printf("length of hello: %lu\n", strlen(hello_str));

  char world_str[6];

  const char *static_world_str = "world";

  strcpy(world_str, static_world_str);

  assert(!strcmp("world", world_str));
  printf("prints world: %s\n", world_str);

  printf("address of world_str: %p\n", world_str);

  char *ptr_to_r = &world_str[2];
  printf("address of 'r': %p\n", ptr_to_r);

  char hello_world_str[12];

  strcpy(hello_world_str, hello_str);

  hello_world_str[5] = ' ';

  strcpy(hello_world_str + 6, world_str);

  assert(!strcmp("hello world", hello_world_str));
  printf("prints hello world: %s\n", hello_world_str);

  return EXIT_SUCCESS;
}
