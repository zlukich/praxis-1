
#ifndef PRAXIS1_CUSTOMERPARTY_H
#define PRAXIS1_CUSTOMERPARTY_H


/**
 * ARRIVED, DECIDED, EATEN need waiter for seating, order and paying
 */
enum STAGES {
    NOT_ARRIVED, ARRIVED, /*wait*/ SEATED, /*busy*/ DECIDED, /*wait*/ ORDERED, /*queued*/ COOKING, /*wait*/ SERVED, /*busy*/ EATEN, /*wait*/ PAYED //
};


typedef struct {
    char *name;
    int prepTime;
    int price;
} meal;


typedef struct CustomerParty{
    char *name;
    meal* order;
    float bill;
    float tip;
    int groupSize; //equals order size
    int tableID;
    int stamps[9];
    enum STAGES currentStage;
    struct CustomerParty *next;
} customerParty;


#endif //PRAXIS1_CUSTOMERPARTY_H
