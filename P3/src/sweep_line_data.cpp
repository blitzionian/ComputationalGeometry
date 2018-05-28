//
// Created by mroeder on 22.05.18.
//

#include <sweep_line_data.hpp>
#include <algorithm>

line_sweep::SweepLineData::SweepLineData(
        unsigned long size,
        bool (*comparator)(
                line_sweep::SweepLineData::node & first,
                line_sweep::SweepLineData::node & second
        )
) {
    m_data = std::vector<node>(size);
    m_comparator = comparator;
}

line_sweep::SweepLineData::SweepLineData(
        std::vector<Line*> & in,
        bool (*comparator)(
                line_sweep::SweepLineData::node & first,
                line_sweep::SweepLineData::node & second
        )
) {
    m_data = std::vector<node>(in.size());
    m_comparator = comparator;
    for(Line * line : in) {
        m_data.push_back(node {event_type::SEGMENT_START,line->getStartPoint(),line});
        m_data.push_back(node {event_type::SEGMENT_END,line->getEndPoint(),line});
    }
    std::sort(m_data.begin(),m_data.end(),m_comparator);
}

line_sweep::SweepLineData::iterator line_sweep::SweepLineData::insert(line_sweep::event_type type, Point * point, Line * line) {
    node result {type,point,line};
    auto next = std::find_if(m_data.begin(),m_data.end(),[this,&result](node & n){
        return !(m_comparator(n,result));
    });
    iterator retval = m_data.insert(next,result);
    return retval;
}

line_sweep::SweepLineData::node line_sweep::SweepLineData::front() {
    return m_data.front();
}

void line_sweep::SweepLineData::pop() {
    m_data.erase(m_data.begin());
}

line_sweep::SweepLineData::neighbours line_sweep::SweepLineData::next_neighbours(line_sweep::SweepLineData::iterator & at) {
    neighbours result{m_data.end(), m_data.end()};
    if(at != m_data.end()) {
        if(at != m_data.begin()) {
            result.first = --iterator(at);
        }
        result.second = ++iterator(at);
    }
    return result;
}

bool line_sweep::SweepLineData::empty() {
    return m_data.empty();
}

line_sweep::SweepLineData::iterator line_sweep::SweepLineData::begin() {
    return m_data.begin();
}

line_sweep::SweepLineData::iterator line_sweep::SweepLineData::end() {
    return m_data.begin();
}

void line_sweep::SweepLineData::remove(Line *segment) {
    auto it = std::find_if(m_data.begin(),m_data.end(),[segment](node & n) {
        return n.line == segment;
    });
    while(it != m_data.end()) {
        m_data.erase(it);
        it = std::find_if(m_data.begin(),m_data.end(),[segment](node & n) {
            return n.line == segment;
        });
    }
}

bool line_sweep::SweepLineData::contains(Point *point) {
    auto it = std::find_if(m_data.begin(),m_data.end(),[point](node & n){
       return n.point == point;
    });
    return it != m_data.end();
}

void line_sweep::SweepLineData::swap(line_sweep::SweepLineData::iterator first, line_sweep::SweepLineData::iterator second) {
    std::iter_swap(first,second);
}

line_sweep::SweepLineData::iterator line_sweep::SweepLineData::find_by_line(Line *line) {
    return std::find_if(m_data.begin(),m_data.end(),[line] (node & n) {
       return n.line == line;
    });
}