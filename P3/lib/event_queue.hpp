//
// Created by mroeder on 18.05.18.
//

#ifndef P3_EVENT_QUEUE_HPP
#define P3_EVENT_QUEUE_HPP

#include <vector>
#include <event.hpp>
#include <line.hpp>

namespace line_sweep {
    class Event_Queue {
    public:
        struct node {
            EventType event;
            Point * point;
            bool operator==(const node & other) {
                return event == other.event && (*point) == (*other.point);
            }
        };
        Event_Queue();
        explicit Event_Queue(std::vector<Line*> & lines);
        virtual ~Event_Queue();
        void insert(EventType type, Point * point);
        node erase(node & n);
        std::vector<node> next_neighbours(node & n);


    private:

        std::vector<node> m_data;
        void sort();

    };
}

#endif //P3_EVENT_QUEUE_HPP
