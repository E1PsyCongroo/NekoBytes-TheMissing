#include <assert.h>
#include <stdio.h>

typedef enum RetType_t { ret_int, ret_double } RetType_t;
typedef struct {
  RetType_t ret_type;
  union {
    int int_val;
    double double_val;
  }; // 匿名联合体
} Ret_t;

Ret_t f(RetType_t ret_type) {
  switch (ret_type) {
  case ret_int:
    return (Ret_t){.ret_type = ret_int, .int_val = 1};
  case ret_double:
    return (Ret_t){.ret_type = ret_double, .double_val = 1.0};
  default:
    assert(0);
  }
}

int main(void) {
  printf("%f\n", f(ret_double).double_val);
  printf("%d\n", f(ret_int).int_val);
  return 0;
}
