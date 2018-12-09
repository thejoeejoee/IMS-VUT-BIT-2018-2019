/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */
#include "stats.h"


Stat sold_adults_stats("Sold adult crickets (directly sold)");
Stat sold_adolescents_stats("Sold adolescence crickets (directly sold)");
Stat feed_amount_stats("Amount of feed (in mg)");
Stat power_consumption_stats("Amount of thermal power consumed (Watt-days)");

Histogram life_length_stats("Life length", 10, 10, 10);
Histogram generation_hist("Generation histogram", 0, 1, 8);
Histogram egg_hist("Eggs count histogram (for females)", 100, 20, 20);
Histogram force_sold_adolescents_hist("Force sold crickets (no free places)", 0, 1, 10);


Store crickets_hatchery("Free place for crickets", CRICKETS_LIMIT);
