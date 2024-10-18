#include <criterion/criterion.h>
#include <string.h>

Test(sample, test) {
  cr_expect(strlen("Test") == 4, "Expected \"Test\" to have a length of 4.");
  cr_expect(strlen("Hello") == 4, "This will always fail, why did I add this?");
  cr_assert(strlen("") == 0);
}