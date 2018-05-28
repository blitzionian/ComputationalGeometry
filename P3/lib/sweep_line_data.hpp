//
// Created by mroeder on 22.05.18.
//

#ifndef P3_SWEEP_LINE_DATA_HPP
#define P3_SWEEP_LINE_DATA_HPP

#include <vector>
#include <line.hpp>
#include <event.hpp>

namespace line_sweep {
    class SweepLineData {
    public:
        struct node {
            event_type event;
            Point * point;
            Line * line;
            Line * top;
            Line * bottom;
        };
        typedef std::vector<node>::iterator iterator;
        struct neighbours {
            iterator first;
            iterator second;
        };
        SweepLineData(unsigned long size, bool (*comparator)(node & first, node & second));
        SweepLineData(std::vector<Line*> & in, bool (*comparator)(node & first, node & second));
        virtual ~SweepLineData() = default;
        iterator insert(event_type type, Point * point, Line * line);
        node front();
        void pop();
        neighbours next_neighbours(iterator & n);
        bool empty();
        iterator begin();
        iterator end();
        void remove(Line * segment);
        bool contains(Point * point);
        void swap(iterator first, iterator second);
        iterator find_by_line(Line * line);

    private:
        std::vector<node> m_data;
        bool (*m_comparator)(node & first, node & second);
    };
}


#endif //P3_SWEEP_LINE_DATA_HPP
