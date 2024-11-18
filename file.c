#include "lux.h"
#include <string.h>

void get_path(char **path) {
  *path = NULL;
  *path = (char *)malloc(PATH_MAX);

  if (getcwd(*path, PATH_MAX) == NULL) {
    print_err("ERR! Error while getting path in function get_path()");
  }
}

void read_file(char *filename) {
  char *path = NULL;
  get_path(&path);

  strlcat(path, "/", strlen(path) + 2);
  strlcat(path, filename, strlen(path) + strlen(filename) + 1);
  printf("%s\n", path);
}
