//
// Created by thejoeejoee on 4.12.18.
//

#include "stats.h"

Stat stats("Life length");

Histogram generation_hist("Generation histogram", 0, 1, 10);
Histogram egg_hist("Eggs count histogram", 100, 20, 20);

int live_crickets = 0;