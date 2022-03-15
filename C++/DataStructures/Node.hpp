#pragma once

template<typename T>
struct Node {
	T m_value;
	Node* m_next;
	Node(T value) : m_value{ value }, m_next{ nullptr } {}
};