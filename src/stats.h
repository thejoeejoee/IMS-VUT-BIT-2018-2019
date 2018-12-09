/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */

#ifndef VUT_FIT_IMS_STATS_H
#define VUT_FIT_IMS_STATS_H

#include "settings.h"
#include <simlib.h>

extern Histogram life_length_stats;

extern Histogram generation_hist;

extern Histogram egg_hist;

extern Stat sold_adults_stats;

extern Stat sold_adolescents_stats;

extern Histogram force_sold_adolescents_hist;

extern Stat feed_amount_stats;

extern Stat power_consumption_stats;

extern Store crickets_hatchery;

#endif //VUT_FIT_IMS_STATS_H
