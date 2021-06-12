#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

/**
 * Reads data line by line from file specified in path and adds all elements to list. Also dynamically allocates memory for every customerParty object
 * @param path path to file containing customerParties input data
 * @param list list pointer where every entry has to be entered
 * @param pointer to array of menues
 * @returns number of lines read
 */


int readData(char *path, linkedList *list, meal **menu) {
    /* ------------ hier code einfügen ------------ */
    FILE* in_file = fopen(path, "r"); // read only  
    if (!in_file) // equivalent to saying if ( in_file == NULL ) 
    {
        printf("oops, file can't be read\n");
        exit(-1);
    }
    int counter = 0;
    char line[100];
    while (fgets(line, 100, in_file) != NULL)
    {
        customerParty* party = (customerParty *) malloc(sizeof(customerParty));
        parseLine(line,party, menu);
        listInsert(list, party);//!!!!!!!!!!!!//
        counter++;
    }
    return counter;

    
    /* ---------- bis hier code einfügen ---------- */
}
