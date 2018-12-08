#include "lib/simlib/src/simlib.h"
#include "src/hatch_event.h"
#include "src/cricket.h"
#include "src/stats.h"
#include "src/settings.h"
#include <iostream>

using namespace std;


class InitialGenerationSpawn : public Event {
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
    (new InitialGenerationSpawn)->Activate();
    Run();

    life_length_stats.Output();
    generation_hist.Output();
    // egg_hist.Output();
    sold_crickets_stats.Output();
    feed_amount_stats.Output();

    auto cricket_price = static_cast<int>(CRICKETS_LITER_PRICE * (sold_crickets_stats.Number() / CRICKETS_IN_LITER));
    auto feed_price = static_cast<int>(FEED_KG_PRICE * (feed_amount_stats.Sum() / 1'000'000.)); // mg -> kg

    cout << "Sold liters: " << sold_crickets_stats.Number() / CRICKETS_IN_LITER << " (appr. "
         << cricket_price << " Kč)" << endl;
    cout << "Feed amount: " << feed_amount_stats.Sum() / 1'000'000. << " (appr. "
         << feed_price << " Kč)" << endl;
    cout << "Total: " << cricket_price - feed_price << " Kč" << endl;


    return 0;
}