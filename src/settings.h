//
// Created by thejoeejoee on 8.12.18.
//

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
#define YOUNG_CRICKET_KEEP_RATE .073 // sell 92.7 %

// rate of females in generation
#define FEMALE_RATE .5 // half

// count of crickets in initial generation (=0)
#define INITIAL_GENERATION_COUNT 1 * 600 // one liter

// length of simulation
#define SIMULATION_LENGTH 12 * 28 // 12 months


#endif //VUT_FIT_IMS_SETTINGS_H
