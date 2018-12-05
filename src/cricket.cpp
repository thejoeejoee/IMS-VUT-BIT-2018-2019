//
// Created by thejoeejoee on 4.12.18.
//

#include "cricket.h"
#include "hatch_event.h"
#include "stats.h"
#include <iostream>


void Cricket::Behavior() {
    auto birth = Time;

    auto adolescence_time = Normal(4 * 7, 4); // rust, 4 tydny +- 4 dny
    Wait(adolescence_time);

    generation_hist(generation);
    if (generation > 0 && Random() > .073) {
        life_length_stats(Time - birth);
        sold_crickets_stats(1);
        this->Terminate();
    }


    auto female = Random() > .5;
    int eggs = 0;
    int days = static_cast<int>(Normal(30, 2));
    for (int i = 0; i < days; ++i) {
        if (female) {
            // samicky rodi
            int children = static_cast<int>(Normal(10, .5));
            eggs += children;
            for (int j = 0; j < children; ++j) {
                if (generation < MAX_GENERATION)
                    (new HatchEvent(generation + 1))->Activate();
            }
        } else {
            // samci se zabijeji
            if (Random() > .95) {
                this->Terminate();
            }
        }

        this->Activate(Time + 1);
    }
    egg_hist(eggs);

    auto life_length = Normal(3 * 28, 4);
    if (life_length > (adolescence_time + days)) {
        Wait(life_length - (adolescence_time + days));
    }

    sold_crickets_stats(1);
    life_length_stats(Time - birth);

    // std::cout << "Killed " << ++c << " in generation " << generation << '.' << std::endl;
}