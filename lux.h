#ifndef LUX_H
#define LUX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>
#include <termios.h>
#include <unistd.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#include <windows.h>
#elif __linux__
#include <limits.h>
#include <unistd.h>
#elif __APPLE__
#include <limits.h>
#include <mach-o/dyld.h>
#endif

#define BUFF_STEP 255
char *text;
void read_file(char *);

#define CLEAR_SCREEN "\033[1;1H\033[2J"
void print_err(char *);

#endif
