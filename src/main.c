#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "kitchen.h"
#include "parse.h"
#include "output.h"
#include "serve.h"

/**
 * This function is the heart and soul of the program. It will be called in every iteration of the while loop in main(). Consisting of two main parts
 * it checks for new orders to be cooked at first. Then it iterates over all customers and depending on the current stage of their visit it will either call serveCustomer()
 * if the customer needs active serving (needs to be seated, wants to order or wants to pay), or it will determine if the customer has waited long enough to enter the next stage.
 *
 * @param res Pointer to the restaurant that is being managed
 * @param currentTime the current tick
**/

void updateTick(restaurant *res, int currentTime) {

   //call cooking_queue_next_HRRN() to determine the customerParty with the highest RR out of everyone who ordered.
    customerParty *next = cooking_queue_next_HRRN(res, currentTime);
    //check repeatedly if their is an order that isn't being prepared yet and if we have a chef available
    //if yes, save the current time as "startCooking" timeStamp for the customer and move them to next stage, also reduce available chefs by one
    while (res->availableChefs > 0 && next != NULL) {
        next->stamps[COOKING] = currentTime;
        next->currentStage++;
        res->availableChefs--;
        next = cooking_queue_next_HRRN(res, currentTime);
    }


    //iterate over all customers
    customerParty *customer = res->guests->first;
    while (customer != NULL) {
        int removed = 0; // needed to determine if list removed was called in the while-loop


        if (customer->currentStage == NOT_ARRIVED) { //if customer didn't arrive yet
            if (customer->stamps[ARRIVED] == currentTime) { //check if customer arrived
                customer->currentStage++; //move to next stage
            }

        } else if (customer->currentStage == ARRIVED || customer->currentStage == DECIDED ||
                    customer->currentStage == EATEN) { //the customer needs to be served
            int status = serveCustomer(customer, res);
            if (status != -1) { //if customer has been served successfully go to next stage and save the timestamp for entering that stage
                customer->currentStage++;
                customer->stamps[customer->currentStage] = currentTime; //set SEATED/ORDERED/PAYED timestamp
            }
        } else if (customer->currentStage == PAYED) { //if a customer has payed remove him from the list but remember his successor
            customerParty *tmp = customer;
            customer = customer->next;
            listRemove(res->guests, tmp);
            removed = 1;

        } else if (customer->currentStage == SEATED || customer->currentStage == SERVED || customer->currentStage ==
                                                                                           COOKING) {// The customer does not need serving and is busy/waiting SEATED/SERVED/COOKING*/
            int timeSinceLastStage = currentTime - customer->stamps[customer->currentStage]; //find out how long the customer is in his current stage

            int busytime;
            switch (customer->currentStage) { //depending on his stage determine how long he should be in that stage

                case SEATED: //if customer is seated and is now choosing he needs two ticks
                    busytime = 2;
                    break;
                case COOKING: //a customer whos order is being prepared needs to wait until that preparation is done
                    busytime = getPrepTime(customer->order, customer->groupSize);
                    break;
                case SERVED: //4 ticks needed for eating
                    busytime = 4;
                    break;
                case ORDERED: //waiting for the kitchen to start cooking
                    busytime = -1;
                    break;
                default:
                    perror("Invalid restaurant state.");
                    exit(-1);
            }

            if (busytime == timeSinceLastStage) { // if customer has waited long enough go into next stage
                if (customer->currentStage == COOKING) { //if customer has been served, make one chef available again
                    res->availableChefs++;
                }
                customer->currentStage++;
                customer->stamps[customer->currentStage] = currentTime; //set CHOSEN/EATEN timestamp

            }
        }
        if (!removed) { //if listRemove() hasn't been called this iteration we still need to get the successor of current element
            customer = customer->next;
        }

    }

}

meal pasta = {"Spaghetti", 12, 9};
meal chirashi = {"Chirashi", 5, 12};
meal rippchen = {"Rippchen", 12, 13};
meal kaiserschmarrn = {"Kaiserschmarrn", 30, 7};

/**
 *
 *
 * @return
 */
int main(int argc, char** argv) {

    if(argc != 2){
        printf("\nUsage: ./binary path/to/input/file\n");
        return -1;
    }

    meal *menu[] = {
            &pasta, &chirashi, &rippchen, &kaiserschmarrn,
    };

    int time = 0;
    linkedList list = {NULL, NULL};
    restaurant theChat = {0, 0, &list, NULL, 5, menu, 3};
    theChat.tables = calloc(theChat.tableCount, sizeof(customerParty *));
    int guestCount = readData(argv[1], &list, theChat.menu); //added back ../


    printf("%-*s", 7, "TIME");
    for (int i = 0; i < theChat.tableCount; ++i) {
        printf("%-*d", 20, i);
    }
    printf("%-*s\n", 20, "PROFIT");

    while (theChat.guests->first != NULL) {
        updateTick(&theChat, time);
        printCurrentTick(&theChat, time);

        time++;
//        usleep( 200 *1000); //sleep 200 ms
    }
    printSummary(&theChat, time, guestCount);

    free(theChat.tables);


}
