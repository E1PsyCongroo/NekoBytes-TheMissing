#include <stdio.h>
#include <string.h>

#include "snake_utils.h"
#include "state.h"

int main(int argc, char* argv[]) {
  bool io_stdin = false;
  char* in_filename = NULL;
  char* out_filename = NULL;
  game_state_t* state = NULL;

  // 解析参数
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0 && i < argc - 1) {
      if (io_stdin) {
        fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
        return 1;
      }
      in_filename = argv[i + 1];
      i++;
      continue;
    } else if (strcmp(argv[i], "--stdin") == 0) {
      if (in_filename != NULL) {
        fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
        return 1;
      }
      io_stdin = true;
      continue;
    }
    if (strcmp(argv[i], "-o") == 0 && i < argc - 1) {
      out_filename = argv[i + 1];
      i++;
      continue;
    }
    fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
    return 1;
  }

  // 请不要修改这行以上的任何内容

  /* Task 7 */

  // 从文件读取游戏板，或创建默认游戏板
  if (in_filename != NULL) {
    // TODO: 从in_filename读取游戏板
    // TODO: 如果文件不存在，则返回-1
    // TODO: 然后对你创建的state应用initialize_snakes函数
  } else if (io_stdin) {
    // TODO: 从stdin读入游戏板
    // TODO: 然后对你创建的state应用initialize_snakes函数
  } else {
    // TODO: 创建默认游戏板
  }

  // TODO: 更新state,然后使用deterministic_food(已经在snake_tuils.h中实现)来添加食物

  // 将更新过的游戏板写入到文件中或者stdout
  if (out_filename != NULL) {
    // TODO: 将游戏板保存到out_filename中
  } else {
    // TODO: 将游戏板打印到stdout
  }

  // TODO: 释放state的内存

  return 0;
}
