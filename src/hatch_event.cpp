//
// Created by thejoeejoee on 4.12.18.
//

#include "../lib/simlib/src/simlib.h"
#include "hatch_event.h"
#include "cricket.h"
#include "settings.h"
#include <iostream>

using namespace std;
void HatchEvent::Behavior() {
    // cout << "New hatch! " << Time << endl;
    if (Random() > HATCH_SUCCESS_PROBABILITY) {
        // dva tydny, ropztyl 2 dny
        auto v = max(HATCH_DURATION, 0.);

        (new Cricket(generation))->Activate(Time + v);
    }

    this->Cancel();
}
