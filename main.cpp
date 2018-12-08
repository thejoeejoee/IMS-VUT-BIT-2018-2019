#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include "src/settings.h"
#include <iostream>

using namespace std;


class CricketSpawn : public Event {
        void Behavior() override {
            for (int i = 0; i < INITIAL_GENERATION_COUNT; ++i) {
                (new Cricket)->Activate();
            }

            this->Cancel();
        }
};

int main() {
    // RandomSeed(time(nullptr));

    SetCalendar("cq");
    Init(0, SIMULATION_LENGTH);
    (new CricketSpawn)->Activate();

    Run();

    life_length_stats.Output();
    generation_hist.Output();
    // egg_hist.Output();
    sold_crickets_stats.Output();
    feed_amount_stats.Output();

    auto cricket_price = static_cast<int>(300 * (sold_crickets_stats.Number() / 600.));
    auto feed_price = static_cast<int>(800 * (feed_amount_stats.Sum() / 1'000'000.));

    cout << "Sold liters: " << sold_crickets_stats.Number() / 600. << " (appr. "
         << cricket_price << " Kč)" << endl;
    cout << "Feed amount: " << feed_amount_stats.Sum() / 1'000'000. << " (appr. "
         << feed_price << " Kč)" << endl;
    cout << "Total: " << cricket_price - feed_price << " Kč" << endl;


    return 0;
}