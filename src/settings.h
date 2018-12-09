/****************************************************************
Implementační část projektu do IMS.
VUT FIT
@author Josef Kolář, xkolar71
@author Iva Kavánková, xkavan05
@date 2018; 05; 12
****************************************************************/

#ifndef VUT_FIT_IMS_SETTINGS_H
#define VUT_FIT_IMS_SETTINGS_H

// ALL DURATION/LENGTH values are in DAYS

// duration of hatch before cricket is birth
#define HATCH_DURATION (Normal(14, 2))

// 0-1 percentage of success birth hatches
#define HATCH_SUCCESS_PROBABILITY 0.9

// total length of adolescence
#define ADOLESCENCE_TOTAL_DURATION (Normal(4 * 7, 4))

// duration, after young cricket is sold
#define ADOLESCENCE_DURATION_BEFORE_SELL (7)

// mg per day for young cricket
#define FEED_AMOUNT_ADOLESCENCE 16

// mg per day for old cricket
#define FEED_AMOUNT_ADULT 34

// count of hatches for female spawn every day
#define HATCHES_PER_ACTIVE_DAY Normal(10, .5)

// count of productive days for adult cricket
#define PRODUCTIVE_ADULT_DAYS Normal(30, 2)

// daily probability of male cricket kill
#define MALE_KILL_PROBABILITY .95

// 0-1 rate of crickets, that are NOT sold directly, but kept for next generation spawn
#define YOUNG_CRICKET_KEEP_RATE .9 // sell 92.7 %

// rate of females in generation
#define FEMALE_RATE .5 // half

// count of crickets in initial generation (=0)
#define INITIAL_GENERATION_COUNT 1 * 800 // one liter

// length of simulation
#define SIMULATION_LENGTH 12 * 28 // 12 months

// count of adult crickets in liter for sell
#define ADULT_CRICKETS_IN_LITER 600.

// count of adolescence crickets in liter for sell
#define ADOLESCENCE_CRICKETS_IN_LITER 800.

// price of cricket liter
#define CRICKETS_LITER_PRICE 300

// price of kilogram of feed
#define FEED_KG_PRICE 800

// how many watts needs one liter of crickets?
#define CRICKET_LITER_THERMAL_CONSUMPTION 12.

// power consumption for one adult cricket
#define ADULT_THERMAL_CONSUMPTION (CRICKET_LITER_THERMAL_CONSUMPTION / ADULT_CRICKETS_IN_LITER)

// power consumption for one adolescence cricket
#define ADOLESCENCE_THERMAL_CONSUMPTION (CRICKET_LITER_THERMAL_CONSUMPTION / ADOLESCENCE_CRICKETS_IN_LITER)

// price of one Watt-day
#define POWER_PRICE (1.2 * 24 * 0.001)

// soft cricket limit (not absolute value) - IMPORTANT
#define CRICKETS_LIMIT 20'000

#endif //VUT_FIT_IMS_SETTINGS_H
