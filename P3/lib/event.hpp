#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <point.hpp>

namespace line_sweep {
    enum event_type {
        SEGMENT_START, SEGMENT_END, INTERSECTION
    };

    struct event {
        event_type type;
        Point * point;
    };
}

#endif /* EVENT_HPP_ */
