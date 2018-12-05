cmake_minimum_required(VERSION 3.10)
project(VUT_FIT_IMS)

set(CMAKE_CXX_STANDARD 17)

set(BASEFILES
    lib/simlib/src/atexit.cc
    lib/simlib/src/calendar.cc
    lib/simlib/src/debug.cc
    lib/simlib/src/entity.cc
    lib/simlib/src/error.cc
    lib/simlib/src/errors.cc
    lib/simlib/src/event.cc
    lib/simlib/src/link.cc
    lib/simlib/src/list.cc
    lib/simlib/src/name.cc
    lib/simlib/src/object.cc
    lib/simlib/src/print.cc
    lib/simlib/src/run.cc
    lib/simlib/src/sampler.cc
    lib/simlib/src/version.cc
)

set(CONTIFILES
    lib/simlib/src/delay.cc
    lib/simlib/src/zdelay.cc
    lib/simlib/src/simlib2D.cc
    lib/simlib/src/simlib3D.cc
    lib/simlib/src/algloop.cc
    lib/simlib/src/cond.cc
    lib/simlib/src/fun.cc
    lib/simlib/src/graph.cc
    lib/simlib/src/intg.cc
    lib/simlib/src/continuous.cc
    lib/simlib/src/ni_abm4.cc
    lib/simlib/src/ni_euler.cc
    lib/simlib/src/ni_fw.cc
    lib/simlib/src/ni_rke.cc
    lib/simlib/src/ni_rkf3.cc
    lib/simlib/src/ni_rkf5.cc
    lib/simlib/src/ni_rkf8.cc
    lib/simlib/src/numint.cc
    lib/simlib/src/output1.cc
    lib/simlib/src/stdblock.cc
)

set(DISCFILES
    lib/simlib/src/barrier.cc
    lib/simlib/src/facility.cc
    lib/simlib/src/histo.cc
    lib/simlib/src/output2.cc
    lib/simlib/src/process.cc
    lib/simlib/src/queue.cc
    lib/simlib/src/random1.cc
    lib/simlib/src/random2.cc
    lib/simlib/src/semaphor.cc
    lib/simlib/src/stat.cc
    lib/simlib/src/store.cc
    lib/simlib/src/tstat.cc
    lib/simlib/src/waitunti.cc
)

set(OPTFILES
    lib/simlib/src/opt-hooke.cc
    lib/simlib/src/opt-simann.cc
    lib/simlib/src/opt-param.cc
)

set(HEADERS
    lib/simlib/src/simlib.h
    lib/simlib/src/errors.h
    lib/simlib/src/internal.h
)

# headers for install
set(SIMLIB_HEADERS
    lib/simlib/src/simlib.h
    lib/simlib/src/delay.h
    lib/simlib/src/zdelay.h
    lib/simlib/src/simlib2D.h
    lib/simlib/src/simlib3D.h
    lib/simlib/src/optimize.h
        src/cricket.cpp src/cricket.h src/stats.cpp src/stats.h)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -O2)

add_executable(VUT_FIT_IMS main.cpp ${BASEFILES} ${CONTIFILES} ${DISCFILES} ${OPTFILES} ${HEADERS} ${SIMLIB_HEADERS} src/hatch_event.cpp src/hatch_event.h)