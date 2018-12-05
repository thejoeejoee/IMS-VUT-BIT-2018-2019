//
// Created by thejoeejoee on 4.12.18.
//

#include "cricket.h"
#include "hatch_event.h"
#include "stats.h"
#include <iostream>

extern Stat stats;

void Cricket::Behavior() {
    // std::cout << "Spawned! " << Time << std::endl;

    auto birth = Time;
    Wait(Normal(4 * 7, 4)); // rust, 4 tydny +- 4 dny

    auto female = Random() > .5;

    int days = static_cast<int>(Normal(30, 4));
    for (int i = 0; i < days; ++i) {
        this->Activate(Time + 1);

        if (female) {
            int children = static_cast<int>(Normal(10, 2));
            for (int j = 0; j < children; ++j) {
                (new HatchEvent(generation + 1))->Activate();
            }
        }

    }
    stats(Time - birth);

    // std::cout << "Killed " << ++c << " in generation " << generation << '.' << std::endl;
}