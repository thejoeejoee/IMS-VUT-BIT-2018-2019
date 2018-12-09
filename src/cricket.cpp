/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */

#include "cricket.h"
#include "hatch_event.h"
#include "stats.h"
#include "settings.h"
#include <iostream>


void Cricket::Behavior() {
    generation_hist(generation); // sign into generation
    auto birth = Time;
    auto adolescence_time = ADOLESCENCE_TOTAL_DURATION; // generate length of adolescence

    // grow into young level of cricket
    Wait(ADOLESCENCE_DURATION_BEFORE_SELL);
    feed_amount_stats(FEED_AMOUNT_ADOLESCENCE * ADOLESCENCE_DURATION_BEFORE_SELL);
    power_consumption_stats(ADOLESCENCE_THERMAL_CONSUMPTION * ADOLESCENCE_DURATION_BEFORE_SELL);

    // first generation is not sold
    // crickets over limit - all of them are sold
    if (crickets_hatchery.Full() || (generation > 0 && Random() > YOUNG_CRICKET_KEEP_RATE)) {
        life_length_stats(Time - birth);
        sold_adolescents_stats(1);
        if (crickets_hatchery.Full())
            force_sold_adolescents_hist(generation);

        this->Terminate();
    }
    crickets_hatchery.Enter(this, 1);

    // grow into adult cricket
    Wait(adolescence_time - ADOLESCENCE_DURATION_BEFORE_SELL);
    feed_amount_stats(FEED_AMOUNT_ADOLESCENCE * (adolescence_time - ADOLESCENCE_DURATION_BEFORE_SELL));
    power_consumption_stats(ADOLESCENCE_THERMAL_CONSUMPTION * (adolescence_time - ADOLESCENCE_DURATION_BEFORE_SELL));

    auto female = Random() > FEMALE_RATE;
    int eggs = 0;
    int days = static_cast<int>(PRODUCTIVE_ADULT_DAYS);
    for (int i = 0; i < days; ++i) {
        if (female) {
            // spawn hatches
            int children = static_cast<int>(HATCHES_PER_ACTIVE_DAY);
            eggs += children;
            for (int j = 0; j < children; ++j) {
                (new HatchEvent(generation + 1))->Activate();
            }
        } else {
            // fight with other males
            if (Random() > MALE_KILL_PROBABILITY) {
                life_length_stats(Time - birth);
                crickets_hatchery.Leave(1);
                this->Terminate();
            }
        }
        // feed for day
        feed_amount_stats(FEED_AMOUNT_ADULT);
        power_consumption_stats(ADULT_THERMAL_CONSUMPTION);
        this->Activate(Time + 1);
    }
    egg_hist(eggs);
    sold_adults_stats(1);
    life_length_stats(Time - birth);
    crickets_hatchery.Leave(1);
}