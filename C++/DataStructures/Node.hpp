#pragma once

template<typename T>
struct Node {
   // The content of the node
   T m_value;
   // Pointer to a next element
   Node *m_next;
   // Default constructor
   Node() : m_value{0}, m_next{nullptr} {}
   // Constructor that receives the value for the node
   explicit Node(T value) : m_value{value}, m_next{nullptr} {}
};
