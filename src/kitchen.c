
#include <string.h>

#include "kitchen.h"

/**
 * This function is a max-search() over a given array of meals with a given size.
 * @param order array of meals containing all orders from one customerParty
 * @param orderSize length of the order array, equal to the size of the group
 * @return prepTime of the meal with the highest preparation time
 */

int getPrepTime(meal* order, int orderSize){
    /* ------------ hier code einfügen ------------ 
    int max = -1;
    for (int i = 0; i < orderSize; i++)
    {
        if (max < meal[i].prepTime) max = meal[i].prepTime;
    }
    return max;
    */

    
    /* ---------- bis hier code einfügen ---------- */
}
/**
 * This function determines the next CustomerParty to get their food prepared by an available chef.
 * It does this by using the HRRN-schedule. For every customerParty the response ration is calculated by adding the time passed since ordering to the preparation time needed
 * to prepare the food  and dividing that by the preparation time. Should two parties have the same response ratio the first one will be choosen.
 * A pointer the customerParty with the highest response ratio is returned or NULL, if no orders currently exist.
 * @param res Pointer to restaurant struct
 * @param currentTime the current Tick
 * @return pointer to a customerParty with the highest response ratio
 */


customerParty *cooking_queue_next_HRRN(restaurant *res, int currentTime) { 
    /* ------------ hier code einfügen ------------ */
    /*CustomerParty* party = NULL;
    foreach(*table in * res){
        double d = (currentTime - stamp[4] + getPrepTime(*table->meal, *table.groupSize)) / getPrepTime(*table->meal, *table.groupSize);
        //if(party->stamp[1] vergleichen)
        party = *res->tables[i];
    }
    return party;
    */



    /* ---------- bis hier code einfügen ---------- */
}

