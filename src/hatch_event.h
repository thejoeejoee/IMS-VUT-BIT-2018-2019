/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */

#ifndef VUT_FIT_IMS_HATCH_EVENT_H
#define VUT_FIT_IMS_HATCH_EVENT_H


class HatchEvent : public Event {
        size_t generation;
        void Behavior() override;
    public:
        explicit HatchEvent(size_t generation = 0) : generation{generation} {};
};

#endif //VUT_FIT_IMS_HATCH_EVENT_H
