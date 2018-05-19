//
// Created by mroeder on 18.05.18.
//

#include <event_queue.hpp>
#include <algorithm>

line_sweep::Event_Queue::Event_Queue() = default;

line_sweep::Event_Queue::Event_Queue(std::vector<Line *> & lines) {
    for(auto & line : lines) {
        m_data.push_back(node {event_type::SEGMENT_START, line -> getStartPoint(), line});
    }
    for(auto & line : lines) {
        m_data.push_back(node {event_type::SEGMENT_END, line -> getEndPoint(), line});
    }
    sort();
}

line_sweep::Event_Queue::~Event_Queue() {
    m_data.clear();
}

void line_sweep::Event_Queue::insert(line_sweep::event_type type, Point *point, Line * line) {
    m_data.push_back(node {type, point, line});
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

template<typename T, typename Func> std::vector<T> line_sweep::Event_Queue::map(Func func) {
    std::vector<T> result;
    std::transform(m_data.begin(),m_data.end(),result.begin(),[&func](node & n) { return func(n); });
    return result;
}

line_sweep::Event_Queue::node line_sweep::Event_Queue::pop() {
    node result = m_data.front();
    m_data.erase(m_data.begin());
    return result;
}

double line_sweep::Event_Queue::max_x() {
    std::vector<double> x = map<double>([](node & n) {return n.point->getX();});
    return *std::max_element(x.begin(),x.end());
}

double line_sweep::Event_Queue::min_x() {
    std::vector<double> x = map<double>([](node & n) {return n.point->getX();});
    return *std::min_element(x.begin(),x.end());
}

double line_sweep::Event_Queue::max_y() {
    std::vector<double> y = map<double>([](node & n) {return n.point->getY();});
    return *std::max_element(y.begin(),y.end());
}

double line_sweep::Event_Queue::min_y() {
    std::vector<double> y = map<double>([](node & n) {return n.point->getY();});
    return *std::min_element(y.begin(),y.end());
}

bool line_sweep::Event_Queue::empty() {
    return m_data.size() == 0;
}

void line_sweep::Event_Queue::sort() {
    std::sort(m_data.begin(),m_data.end(),[](node & left, node & right){
        if(left.point -> getX() == right.point -> getX()) {
            return left.point -> getY() < right.point -> getY();
        }
        return left.point -> getX() < right.point -> getX();
    });
}


