//
// Created by thejoeejoee on 4.12.18.
//

#ifndef VUT_FIT_IMS_CRICKET_H
#define VUT_FIT_IMS_CRICKET_H

#include "../lib/simlib/src/simlib.h"

static int count = 0;

class Cricket : public Process {
        size_t generation;
        void Behavior() override;
    public:
        explicit Cricket(size_t generation = 0) : generation{generation} {

        };
};

#endif //VUT_FIT_IMS_CRICKET_H
