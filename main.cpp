#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include <iostream>

using namespace std;


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

    life_length_stats.Output();
    generation_hist.Output();
    // egg_hist.Output();
    sold_crickets_stats.Output();
    cout << "Sold liters: " << sold_crickets_stats.Number() / 600. << " (appr. "
         << static_cast<int>(300 * (sold_crickets_stats.Number() / 600.)) << " Kč)" << endl;


    return 0;
}