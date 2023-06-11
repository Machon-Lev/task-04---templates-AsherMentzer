#pragma once

#include <iostream>
#include <list>
#include <exception>


template <class T>
struct MyComparator{
	/**
	 * @brief Functor to compare two objects of type T.
	 * @param a The first object to compare.
	 * @param b The second object to compare.
	 * @return true if a is less than b, false otherwise.
	 */
	bool operator()(const T& a, const T& b) const {
		return a < b;
	}
};

template <class T>
class PriorityQueue {
   
public:
	/**
	 * @brief Inserts an element into the priority queue.
	 * @param t The element to insert.
	 */
	void push(const T& t);
		

	/**
	 * @brief Removes and returns the element with the highest priority from the priority queue.
	 * @return The element with the highest priority.
	 * @throws std::exception if the priority queue is empty.
	 */
	T poll();

private:
	std::list<T> elements;
	MyComparator<T> comp;
};

template <class T>
void PriorityQueue<T>::push(const T& item)
{
	typename std::list<T>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		if (comp(item, *it) == 1) {
			elements.insert(it, item);
			return;
		}
	}
	elements.push_back(item);
}

template <class T>
T PriorityQueue<T>::poll()
{
	if (!elements.empty()) {

		T t = elements.front();
		elements.pop_front();
		return t;

	}
	else {
		throw std::out_of_range("PriorityQueue empty !");
	}
}
