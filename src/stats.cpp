//
// Created by thejoeejoee on 4.12.18.
//

#include "stats.h"


Stat sold_crickets_stats("Sold crickets (directly sold)");

Histogram life_length_stats("Life length", 10, 10, 10);
Histogram generation_hist("Generation histogram", 0, 1, 10);
Histogram egg_hist("Eggs count histogram (for females)", 100, 20, 20);
