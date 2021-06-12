#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "list.h"

typedef struct {
    float sales;
    float tips;
    linkedList *guests;
    customerParty **tables;
    int tableCount;
    meal **menu;
    int availableChefs;
} restaurant;

#endif // RESTAURANT_H
