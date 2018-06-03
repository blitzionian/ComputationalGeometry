#ifndef P3_EVENT_QUEUE_HPP
#define P3_EVENT_QUEUE_HPP

#include <vector>
#include <event.hpp>
#include <line.hpp>

namespace line_sweep {
	class Event_Queue {
	public:

		struct node {
			event_type event;
			Point * point;
			Line * line;
			bool operator==(const node & other) {
				return event == other.event && (*point) == (*other.point) && line->equals(*(other.line));
			}
		};

		Event_Queue();
		explicit Event_Queue(std::vector<Line*> & lines);
		virtual ~Event_Queue();
		void insert(event_type type, Point * point, Line * line);
		node erase(node & n);
		node pop();
		std::vector<node> next_neighbours(node & n);
		template<typename Func> std::vector<node> where(Func func);
		template<typename T, typename Func> std::vector<T> map(Func func);
		double max_x();
		double min_x();
		double max_y();
		double min_y();
		bool empty();

	private:

		std::vector<node> m_data;
		void sort();

	};
}

#endif //P3_EVENT_QUEUE_HPP
