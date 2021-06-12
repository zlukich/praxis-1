#ifndef LIST_H
#define LIST_H

#include "customerParty.h"


typedef struct {
    customerParty* first;
    customerParty* last;
}linkedList;

void listInsert (linkedList *list, customerParty *newElem);
void listRemove(linkedList *list, customerParty *elem);

#endif // LIST_H
