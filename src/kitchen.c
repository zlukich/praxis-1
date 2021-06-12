
#include <string.h>

#include "kitchen.h"

/**
 * This function is a max-search() over a given array of meals with a given size.
 * @param order array of meals containing all orders from one customerParty
 * @param orderSize length of the order array, equal to the size of the group
 * @return prepTime of the meal with the highest preparation time
 */

int getPrepTime(meal* order, int orderSize){
    /* ------------ hier code einfügen ------------*/ 
    int max = -1;
    for (int i = 0; i < orderSize; i++)
    {
        if (max < order[i].prepTime) max = order[i].prepTime;
    }
    return max;
    

    
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
    customerParty* party = NULL;
    int max = -1;
    int k = 0;
    //printf("\r\n Test  %d  \r\n",res->tables[0]->stamps[4])
    for(int i = 0;i<res->tableCount;i++){
        if(res->tables[i] == NULL) continue;
        if(res->tables[i]->stamps[4]==0) continue;
        if(res->tables[i]->stamps[5]!=0) continue;
        //printf("!!!!!!!!!!!!!!   %d    !!!!!!!!!!!!!!!!!!!!",res->tables[i]->stamps[4]);
        double d = (currentTime - res->tables[i]->stamps[4] + getPrepTime(res->tables[i]->order, res->tables[i]->groupSize)) / getPrepTime(res->tables[i]->order, res->tables[i]->groupSize);
        if(d>max) {max = d;k = i;}
        //if(party->stamp[1] vergleichen)
        
    }
    if(max!=-1) party = res->tables[k];
    return party;
    



    /* ---------- bis hier code einfügen ---------- */
}

