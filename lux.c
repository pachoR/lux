#include "lux.h"
#include "colors.h"

void print_err(char *errmsg) {
  printf(RED);
  printf("%s\n", errmsg);
  printf(DEFAULT);
}

int main(int argc, char **argv) {

  if (argc == 2 && argv[1]) {
    read_file(argv[1]);
  } else {
    print_err(
        "ERR! No file provided, expected exec command: lux filename|path");
    return 1;
  }
  return 0;
}
