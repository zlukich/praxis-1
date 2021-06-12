#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parse.h"

/**
 * Gets called by readData() for every line of the file and parses all arguments to newCustomer.
 * Also initializes all other values in customerParty struct with default values.
 * Order of arguments and example can be seen in example.txt
 * @param line one line of the file
 * @param newCustomer to be filled by function, allocated by readData
 * @param menu contains all meals of the restaurant
 */
//meal* meal* meal* meal*
void parseLine(char *line, customerParty *newCustomer, meal **menu) {
    /* ------------ hier code einfügen ------------ 
          line - Fischer 1 4 1 2 3 0
    */
    //printf("!!!Line is - %s\r\n",line);
    char* token = strtok(line, " ");

    // loop through the string to extract all other tokens
    int counter = 0;
    int mealnumber = 0;
    while (token != NULL) {
       // printf(" %s\n", token); //printing each token
        token = strtok(NULL, " ");
        if(token == NULL) break;
        if (counter == 0) {
            newCustomer->name = malloc(sizeof(char) * (strlen(token)+1);
            strncpy(newCustomer->name, token,strlen(token));
        }
        else if(counter==1)
        {
                newCustomer->stamps[1] = atoi(token);
        }
        else if(counter == 2){
            newCustomer->groupSize = atoi(token);
            newCustomer->order = (meal *) malloc(sizeof(meal));
        }
        else{
            //printf("---------------Token--------------%s\r\n",token);
            //printf("!!!%s!!!\r\n",menu[atoi(token)]->name);
            newCustomer->order = (meal *)realloc(newCustomer->order,++mealnumber*sizeof(meal));
            newCustomer->order->name = calloc(sizeof(char),strlen(menu[atoi(token)]->name));
            strncpy(newCustomer->order->name,menu[atoi(token)]->name,strlen(menu[atoi(token)]->name));
            newCustomer->order->price = menu[atoi(token)]->price;
            newCustomer->order->prepTime = menu[atoi(token)]->prepTime;
            newCustomer->bill+=menu[atoi(token)]->price;
        }
        counter++;
        
    }
    //fprintf("The line is: %s\n", line);



    
    /* ---------- bis hier code einfügen ---------- */
}
