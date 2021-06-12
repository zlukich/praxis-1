#include <stdio.h>
#include <string.h>

#include "output.h"


/**
 * print the status of all tables in rows
 *
 * colored output src & more info: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 */
void printCurrentTick(restaurant *res, int currentTime) {
    printf("%-*d", 7, currentTime);

    //iterate tables
    for (int i = 0; i < res->tableCount; ++i) {
        customerParty *pParty = res->tables[i];
        if (pParty) {
            //build output string based on customer state
            char *name = pParty->name;
            char *state;
            switch (pParty->currentStage) {
                case NOT_ARRIVED:
                    state = "NAR";
                    break;
                case ARRIVED:
                    state = "ARVD";
                    break;
                case SEATED:
                    printf(ANSI_COLOR_BLUE);
                    state = "SEATED";
                    break;
                case DECIDED:
                    printf(ANSI_COLOR_RED);
                    state = "DECD";
                    break;
                case ORDERED:
                    printf(ANSI_COLOR_MAGENTA);
                    state = "ORD";
                    break;
                case COOKING:
                    printf(ANSI_COLOR_YELLOW);
                    state = "COOK";
                    break;
                case SERVED:
                    printf(ANSI_COLOR_CYAN);
                    state = "SRVD";
                    break;
                case EATEN:
                    printf(ANSI_COLOR_GREEN);
                    state = "ETN";
                    break;
                case PAYED:
                    state = "PAYED";
                    break;

            }
            printf("%-*s:%-*s", 9, name, 10, state); //column width: 20 chars
            printf(ANSI_COLOR_RESET);
        } else {
            //table is empty
            printf("%-*s", 20, "-");
        }

    }
    printf("%-*.2f", 20, res->sales);

    //As entering and paying does not show up at the tables, check for these states
    for (customerParty *customer = res->guests->first; customer != //print actions that happened this tick
                                                       NULL; customer = customer->next) {
        if (customer->currentStage == PAYED && customer->stamps[customer->currentStage] == currentTime) {
            printf(ANSI_COLOR_CYAN"%s"ANSI_COLOR_RESET, customer->name); //set output color. src & more info: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
            if(customer->tip == 0){
                printf(" payed "ANSI_COLOR_YELLOW"%.2f"ANSI_COLOR_RESET", didn't leave a tip and left the Chat. ", customer->bill);
            } else{
                printf(" payed "ANSI_COLOR_YELLOW"%.2f"ANSI_COLOR_RESET", tipped "ANSI_COLOR_GREEN"%.2f"ANSI_COLOR_RESET" and left the Chat. ", customer->bill, customer->tip);
            }
        } else if (customer->currentStage == ARRIVED && customer->stamps[customer->currentStage] == currentTime) {
            printf(ANSI_COLOR_CYAN"%s"ANSI_COLOR_RESET, customer->name);
            printf(" entered the Chat. ");
        }
    }
    printf("\n");
}

/**
 * sum up key simulation data in one print
 */
void printSummary(restaurant *res, int currentTime, int guestCount) {
    printf("\nThe restaurant has turned over %.2f€. The staff was tipped %.2f€ and served %i customers in %i minutes.\n",
           res->sales, res->tips, guestCount, currentTime);
}
