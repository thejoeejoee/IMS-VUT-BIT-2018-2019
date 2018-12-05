#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include <iostream>

using namespace std;
extern Stat stats;
extern TStat sold_crickets;
extern int live_crickets;

extern Histogram generation_hist;
extern Histogram egg_hist;


class CricketSpawn : public Event {
        void Behavior() override {
            for (int i = 0; i < 50 * 600; ++i) {
                (new Cricket)->Activate();
            }

            this->Cancel();
        }
};

int main() {
    RandomSeed(time(nullptr));

    SetCalendar("cq");
    Init(0, 12 * 28);
    (new CricketSpawn)->Activate();

    Run();

    stats.Output();
    generation_hist.Output();
    // egg_hist.Output();
    sold_crickets.Output();
    cout << "Live crickets: " << live_crickets << endl;
    cout << "Sold liters: " << sold_crickets.Number() / 600. << " ("
         << static_cast<int>(300 * (sold_crickets.Number() / 600.)) << " Kč)" << endl;


    return 0;
}