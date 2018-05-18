//
// Created by mroeder on 18.05.18.
//

#include <event_queue.hpp>
#include <algorithm>

line_sweep::Event_Queue::Event_Queue() = default;

line_sweep::Event_Queue::Event_Queue(std::vector<Line *> & lines) {
    for(auto & line : lines) {
        m_data.push_back(node {EventType::SEGMENT_END, line -> getEndPoint()});
    }
    sort();
}

line_sweep::Event_Queue::~Event_Queue() {
    m_data.clear();
}

void line_sweep::Event_Queue::insert(EventType type, Point *point) {
    m_data.push_back(node {type, point});
    sort();
}

line_sweep::Event_Queue::node line_sweep::Event_Queue::erase(line_sweep::Event_Queue::node &n) {
    m_data.erase(find(m_data.begin(),m_data.end(),n));
    return n;
}

std::vector<line_sweep::Event_Queue::node> line_sweep::Event_Queue::next_neighbours(line_sweep::Event_Queue::node &n) {
    node next = *(++find(m_data.begin(),m_data.end(),n));
    return where([&next](node other){
        return other.point->getX() == next.point->getX();
    });
}

template<typename Func> std::vector<line_sweep::Event_Queue::node> line_sweep::Event_Queue::where(Func func) {
    std::vector<node> result;
    for(auto & node : m_data) {
        if(func(node)) {
            result.push_back(node);
        }
    }
    return result;
}

void line_sweep::Event_Queue::sort() {
    std::sort(m_data.begin(),m_data.end(),[](node & left, node & right){
        return left.point -> getX() < right.point -> getX();
    });
}


