#pragma once

#include <Node.hpp>

template<typename T>
class SinglyLinkedList
{
private:
	Node* m_head;
	Node* m_tail;

public:
	void Add(T value) {
		Node* node = new Node(value);
		if (nullptr == m_head) {
			m_head = node;
			m_tail = node;
		}
		else {
			m_tail->m_next = node;
			tail = node;
		}
	}
};