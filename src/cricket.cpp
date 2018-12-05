//
// Created by thejoeejoee on 4.12.18.
//

#include "cricket.h"
#include "hatch_event.h"
#include "stats.h"
#include <iostream>

extern Stat stats;
extern int live_crickets;
extern Histogram generation_hist;
extern Histogram egg_hist;

void Cricket::Behavior() {
    // std::cout << "Spawned! " << Time << std::endl;

    auto birth = Time;
    live_crickets++;

    auto adolescence_time = Normal(4 * 7, 4);// rust, 4 tydny +- 4 dny
    Wait(adolescence_time);

    auto female = Random() > .5;
    int eggs = 0;
    int days = static_cast<int>(Normal(30, 2));
    for (int i = 0; i < days; ++i) {
        // this->Passivate();
        if (female) {
            int children = static_cast<int>(Normal(10, .5));
            eggs += children;
            for (int j = 0; j < children; ++j) {
                if (generation < MAX_GENERATION)
                    (new HatchEvent(generation + 1))->Activate();
            }
        }

        this->Activate(Time + 1);
    }
    egg_hist(eggs);

    auto life_length = Normal(3 * 28, 4);
    if (life_length > (adolescence_time + days)) {
        Wait(life_length - (adolescence_time + days));
    }

    live_crickets--;
    stats(Time - birth);
    generation_hist(generation);

    // std::cout << "Killed " << ++c << " in generation " << generation << '.' << std::endl;
}