#ifndef PARSE_H
#define PARSE_H

#include "customerParty.h"
#include "list.h"

void parseLine(char *line, customerParty *newCustomer, meal **menu);
int readData(char *path, linkedList *list, meal **menu);

#endif // PARSE_H
