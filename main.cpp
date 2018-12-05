#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include <iostream>

using namespace std;
extern Stat stats;


class CricketSpawn : public Event {
        void Behavior() override {
            for (int i = 0; i < 4; ++i) {
                (new Cricket)->Activate();
            }

            this->Cancel();
        }
};

int main() {

    Init(0, 6 * 28);
    (new CricketSpawn)->Activate();
    Run();

    stats.Output();


    return 0;
}