#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // TODO: allocate memory to store the string "hello"
  // Hint: how many bytes do we need to store this string?
  ______ hello_str[______];

  // TODO: store the characters one at a time
  // Hint: don't forget the null terminator
  // Note: we use single quotes for characters
  ______ = 'h';
  ______ = 'e';
  ______ = 'l';
  ______ = 'l';
  ______ = 'o';

  // TODO: store the null terminator
  ______ = ______;

  // Prints hello_str
  printf("prints hello: %s\n", hello_str);

  // TODO: print the length of hello_str
  printf("length of hello: %lu\n", ______(hello_str));

  // TODO: allocate memory to store the string "world"
  ______ world_str[______];

  // TODO: fill in the type
  // Note: this automatically stores the string "world" in static memory
  //       but static memory is immutable, so you may need to copy it
  //       to the stack or the heap
  ______ static_world_str = "world";

  // TODO: use strcpy and static_world_str to store "world" into world_str
  // Hint: strcpy takes two arguments:
  //       first the destination, then the source
  ______(______, ______);

  // Prints world_str
  printf("prints world: %s\n", world_str);

  // Prints the address of world_str
  printf("address of world_str: %p\n", world_str);

  // TODO: compute the address of the letter r using world_str
  ______ ptr_to_r = ____________;
  printf("address of 'r': %p\n", ptr_to_r);

  // TODO: allocate memory to store the string "hello world"
  ______ hello_world_str[______];

  // TODO: use strcpy and hello_str to store
  //       the string "hello" into hello_world_str
  ______(______, ______);

  // TODO: store the space character in "hello world" at the correct index
  // Note: a space is not the same as null terminator
  //       a null terminator is represented by '\0'
  ______ = ' ';

  // TODO: use strcpy, pointer arithmetic, and world_str to store
  //       the string "world" into hello_world_str
  ______(______ + ______, ______);

  // Prints hello_world_str
  printf("prints hello world: %s\n", hello_world_str);

  return 0;
}