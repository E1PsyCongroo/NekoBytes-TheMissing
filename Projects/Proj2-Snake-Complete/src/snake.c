#include <stdio.h>
#include <string.h>

#include "snake_utils.h"
#include "state.h"

int main(int argc, char* argv[]) {
  bool io_stdin = false;
  char* in_filename = NULL;
  char* out_filename = NULL;
  game_state_t* state = NULL;

  // Parse arguments
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

  // Do not modify anything above this line.

  /* Task 7 */

  // Read board from file, or create default board
  if (in_filename != NULL) {
    FILE* in_file = fopen(in_filename, "r");// TODO: Load the board from in_filename
    if (in_file == NULL)
    {
      return -1;
    }
    state = load_board(in_file);    // TODO: If the file doesn't exist, return -1
    initialize_snakes(state);
    fclose(in_file);// TODO: Then call initialize_snakes on the state you made
  } else if (io_stdin) {
    state = load_board(stdin);// TODO: Load the board from stdin
    initialize_snakes(state);// TODO: Then call initialize_snakes on the state you made
  } else {
    state = create_default_state();// TODO: Create default state
  }
  update_state(state, deterministic_food);// TODO: Update state. Use the deterministic_food function
                          // (already implemented in snake_utils.h) to add food.
  // Write updated board to file or stdout
  if (out_filename != NULL) {
    FILE* out_file = fopen(out_filename, "w");
    print_board(state, out_file);// TODO: Save the board to out_filename
  } else {
    print_board(state, stdout);// TODO: Print the board to stdout
  }

  free_state(state);// TODO: Free the state

  return 0;
}
