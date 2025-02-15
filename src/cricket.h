/**
 * Part of implementation IMS project - cricket farm simulation.
 * VUT FIT
 * @author Josef Kolář, xkolar71
 * @author Iva Kavánková, xkavan05
 * @date 2018; 05; 12
 */

#ifndef VUT_FIT_IMS_CRICKET_H
#define VUT_FIT_IMS_CRICKET_H


#include <simlib.h>


class Cricket : public Process {
        size_t generation;
        void Behavior() override;
    public:
        explicit Cricket(size_t generation = 0) : generation{generation} {

        };
};

#endif //VUT_FIT_IMS_CRICKET_H
