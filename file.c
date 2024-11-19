#include "lux.h"
#include <stdlib.h>

void get_path(char **path, char *filename) {
  *path = NULL;
  *path = (char *)malloc(PATH_MAX);

  if (getcwd(*path, PATH_MAX) == NULL) {
    print_err("ERR! Error while getting path in function get_path()");
  }

  strlcat(*path, "/", strlen(*path) + 2);
  strlcat(*path, filename, strlen(*path) + strlen(filename) + 1);
}

void fget_text(FILE *file) {
  text = (char *)malloc(BUFF_STEP * sizeof(char));
  int n = 0; // counts the number of chars read;
  int c = 0; // current char

  while ((c = fgetc(file)) != EOF) {
    if (n == BUFF_STEP - 1) {
      text = (char *)realloc(text, sizeof(text) + BUFF_STEP + 1);
    }
    unsigned char c_char = (unsigned char)c;
    text[n++] = c_char;
  }
  text[n] = '\0';
  printf("%s", text);
}

void read_file(char *filename) {
  char *path = NULL;
  get_path(&path, filename);

  FILE *fptr = fopen(path, "r+");

  if (!fptr) {
    print_err("Err! Non-existing file in the current work directory");
    exit(EXIT_FAILURE);
  } else {
    fget_text(fptr);
  }

  fclose(fptr);
}
