#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include <iostream>

using namespace std;
extern Stat stats;
extern int live_crickets;

extern Histogram generation_hist;
extern Histogram egg_hist;


class CricketSpawn : public Event {
        void Behavior() override {
            for (int i = 0; i < 4; ++i) {
                (new Cricket)->Activate();
            }

            this->Cancel();
        }
};

int main() {

    SetCalendar("cq");
    Init(0, 11 * 28);
    (new CricketSpawn)->Activate();

    Run();

    stats.Output();
    generation_hist.Output();
    egg_hist.Output();
    cout << "Live crickets: " << live_crickets << endl;


    return 0;
}