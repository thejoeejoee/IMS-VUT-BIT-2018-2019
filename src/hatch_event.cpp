//
// Created by thejoeejoee on 4.12.18.
//

#include "../lib/simlib/src/simlib.h"
#include "hatch_event.h"
#include "cricket.h"
#include <iostream>

using namespace std;
void HatchEvent::Behavior() {
    // cout << "New hatch! " << Time << endl;
    if (Random() > 0.9) {
        // dva tydny, ropztyl 2 dny
        auto v = max(Normal(14, 2), 0.);

        (new Cricket(generation))->Activate(Time + v);
    }

    this->Cancel();
}
