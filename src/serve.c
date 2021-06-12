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
    //int k = 0;
    //printf("%d\r\n",res->tableCount);
    
    if (stage == ARRIVED) {
        /* ------------ hier code einfügen ------------ */
        for(int i = 0;i<res->tableCount;i++){
           if(res->tables[i] ==NULL) {res->tables[i] = customer;customer->tableID = i;return 0;}
        }
        return -1;


        
        /* ---------- bis hier code einfügen ---------- */
    } //SEAT
    if (stage == DECIDED) {
        return 0;
    } //ORDER
    if (stage == EATEN) 
    {
        /* ------------ hier code einfügen ------------ */
        float W = customer->stamps[2] - customer->stamps[1] + customer->stamps[4] - customer->stamps[3] + customer->stamps[6] - customer->stamps[5];
        float p = 20 - (0.5*(W-5));
        if(p<0) p = 0;
        if(p>20) p = 20;
        p = p/100;
       // printf("\r\n%f\r\n",p);
        for(int i = 0;i<customer->groupSize;i++){
            customer->bill+=customer->order[i].price;
            res->sales+=customer->order[i].price;
            customer->tip+=customer->order[i].price*p;
            res->tips+=customer->order[i].price*p;
        }
        for(int i = 0;i<res->tableCount;i++)
        {
            if(customer == res->tables[i]) 
            {
                res->tables[i] = NULL; break;
            }
        }
        return 0;   
        /* ---------- bis hier code einfügen ---------- */
    }
    
}
