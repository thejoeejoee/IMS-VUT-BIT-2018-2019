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

    // crickets_hatchery.Output();
    // life_length_stats.Output();
    generation_hist.Output();
    force_sold_adolescents_hist.Output();
    // egg_hist.Output();
    // sold_adults_stats.Output();
    // sold_adolescents_stats.Output();
    // feed_amount_stats.Output();

    auto sold_liters = (sold_adults_stats.Number() / ADULT_CRICKETS_IN_LITER) +
                       (sold_adolescents_stats.Number() / ADOLESCENCE_CRICKETS_IN_LITER);

    auto cricket_price = static_cast<int>(sold_liters * CRICKETS_LITER_PRICE);

    auto feed_price = static_cast<int>(FEED_KG_PRICE * (feed_amount_stats.Sum() / 1'000'000.)); // mg -> kg
    auto power_price = static_cast<int>(POWER_PRICE * power_consumption_stats.Sum());
    auto initial_generation_price = static_cast<int>((INITIAL_GENERATION_COUNT / ADOLESCENCE_CRICKETS_IN_LITER) *
                                                     CRICKETS_LITER_PRICE);
    cout << endl;
    cout << "Initial: " << INITIAL_GENERATION_COUNT << " pcs (appr. "
         << initial_generation_price << " Kč)" << endl;
    cout << "Sold: " << sold_liters << " l (appr. "
         << cricket_price << " Kč)" << endl;
    cout << "Feed: " << feed_amount_stats.Sum() / 1'000'000. << " kg (appr. "
         << feed_price << " Kč)" << endl;
    cout << "Power: " << power_consumption_stats.Sum() / (24. * 1'000) << " WattDay (appr. "
         << power_price << " Kč)" << endl;
    cout << "Total: " << cricket_price - feed_price - power_price - initial_generation_price << " Kč" << endl;


    return 0;
}