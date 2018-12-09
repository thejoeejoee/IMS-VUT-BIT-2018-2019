/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */

#include <simlib.h>
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
