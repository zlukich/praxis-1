#ifndef OUTPUT_H
#define OUTPUT_H
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "customerParty.h"
#include "restaurant.h"
#include "list.h"

void printCurrentTick(restaurant*, int);
void printSummary(restaurant*, int, int);

#endif // OUTPUT_H

