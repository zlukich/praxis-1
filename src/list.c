#include <stdlib.h>

#include "list.h"


/**
 * Places a customerParty pointer at the beginning of an existing list
 * @param list pointer to an already initialized linkedList struct
 * @param newElem pointer to an existing customerParty that will be inserted into the list
 */
void listInsert(linkedList *list, customerParty *newElem) {
    if (list->first == NULL) {
        list->first = newElem;
        list->last = newElem;
        return;
    }
    list->last->next = newElem;
    list->last = newElem;
}

/**
 * Removes the passed element from the list and frees it's memory. The list is kept intact.
 * @param list pointer to an already initialized linkedList struct
 * @param newElem pointer to an existing customerParty that will be inserted into the list
 */
void listRemove(linkedList *list, customerParty *elem) {
    if (elem == list->first) {
        list->first = list->first->next;
        if (elem == list->last) {
            list->last = NULL;
        }
    }
    for (customerParty *curr = list->first; curr != NULL; curr = curr->next) {
        if (curr->next == elem) {
            if (curr->next == list->last) {
                list->last = curr;
                list->last->next = NULL;
            }
            curr->next = elem->next;
            break;
        }
    }

    elem->next = NULL;

    free(elem->name);
    free(elem->order);
    free(elem);
}

