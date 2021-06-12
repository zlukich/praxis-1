#ifndef PRAXIS1_KITCHEN_H
#define PRAXIS1_KITCHEN_H

#include <stdlib.h>

#include "customerParty.h"
#include "restaurant.h"

int getPrepTime(meal* order, int orderSize);
customerParty *cooking_queue_next_HRRN(restaurant* res, int currentTime);

#endif //PRAXIS1_KITCHEN_H
