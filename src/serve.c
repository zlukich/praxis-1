#include "serve.h"
#include "kitchen.h"
/**
 * @param customer that needs attention based on status:
 *          ARRIVED -> check for empty table and seat customer, return 0
 *          DECIDED -> return 0
 *          EATEN   ->  calculate price and tip (if any). Save them for customer and add to restaurant. Free the table. return 0.
 * @param res
 * @return -1 if not successful
 */


int serveCustomer(customerParty *customer, restaurant *res) {
    int stage = customer->currentStage;
    int k = 0;
    printf("%d\r\n",res->tableCount);
    
    if (stage == ARRIVED) {
        /* ------------ hier code einfügen ------------ */
        for(int i = 0;i<res->tableCount;i++){
           if(res->tables[i] ==NULL) {res->tables[i] = customer;customer->tableID = i;k = i;return 0;}
        }
        return -1;


        
        /* ---------- bis hier code einfügen ---------- */
    } //SEAT
    if (stage == DECIDED) {
        return 0;
    } //ORDER
    if (stage == EATEN) {
        /* ------------ hier code einfügen ------------ */
        int W = customer->stamps[2] - customer->stamps[1] + customer->stamps[4] - customer->stamps[3] + customer->stamps[6] - customer->stamps[5];
        int p = 20 - (0.5*(W-5));
        if(p<0) p = 0;
        if(p>20) p = 20;
        res->tables[k] = NULL;

        
        /* ---------- bis hier code einfügen ---------- */
    } //PAY
    return -1;
}
