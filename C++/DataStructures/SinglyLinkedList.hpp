#pragma once

#include <Node.hpp>

#include <iostream>

template<typename T = int>
class SinglyLinkedList
{
   // Pointers to the head and tail of the linked list
   Node<T> *m_head;
   Node<T> *m_tail;

public:
   // The default constructor simply sets the pointers to null
   SinglyLinkedList() : m_head{nullptr}, m_tail{nullptr} {
      std::cout << "SinglyLinkedList created" << std::endl;
   }
   // Delete the copy constructor, copy assignment constructor,
   // copy operator, copy assignment operator
   SinglyLinkedList(const SinglyLinkedList&) = delete;
   SinglyLinkedList(SinglyLinkedList&&) = delete;
   SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
   SinglyLinkedList& operator=(SinglyLinkedList&&) = delete;

   // Define a custom destructor
   ~SinglyLinkedList() {
      // Remove all the elements from the list and free the
      // memory of each node
      while(nullptr != m_head) {
         Node<T> *tmp = m_head;
         m_head = m_head->m_next;
         delete(tmp);
      }
      std::cout << "SinglyLinkedList destroyed" << std::endl;
   }

   // Method to insert and element to the linked list
   void add(T t_value) {
      // Create a new node for the linked list
      auto node = new Node<T>(t_value);
      // If the linked list is empty, the head and tail will
      // point to it
      if (nullptr == m_head) {
         m_head = node;
         m_tail = node;
      }
      // If there are already some elements, add the new
      // element to the tail
      else {
         m_tail->m_next = node;
         m_tail = node;
      }
   }

   // Traverse a linked list searching for an element
   bool contains(T value) {
      // Start searching from the head
      auto node = m_head;
      // Check if the linked list is still not over or if the
      // element was found
      while(nullptr != node && node->m_value != value) {
         node = node->m_next;
      }
      return (nullptr != node) ? true : false;
   }

   // Remove an element from the linked list
   bool remove(T value) {
      // The list is empty
      if(nullptr == m_head) {
         return false;
      }
      auto node = m_head;
      if(node->m_value == value) {
         // There is only one element in the linked list
         if(m_head == m_tail) {
            m_head = m_tail = nullptr;
         }
         // The element to remove is the head of the linked list
         else {
            m_head = m_head->m_next;
         }
         delete(node);
         return true;
      }
      while(nullptr != node->m_next && node->m_next->m_value != value) {
         node = node->m_next;
      }
      if(nullptr != node->m_next) {
         if(node->m_next == m_tail) {
            // The tail will be removed
            m_tail = node;
         }
         // Removing a node that is between the head and tail
         auto tmp = node->m_next;
         node->m_next = node->m_next->m_next;
         delete(tmp);
         return true;
      }
      // If the value was not found in the list
      return false;
   }

   // Method to traverse the elements of the linked list
   void traverse() const {
      // Start from the head of the linked list
      auto node = m_head;
      while(nullptr != node) {
         // Print the value of the node and go to the next node
         std::cout << node->m_value << " -> ";
         node = node->m_next;
      }
      std::cout << "NULL" << std::endl;
   }

   // Method to traverse in reversal a linked list
   void reverseTraversal() {
      if(nullptr != m_tail) {
         auto current = m_tail;
         std::cout << "NULL -> ";
         while(current != m_head) {
            auto previous = m_head;
            while(previous->m_next != current) {
               previous = previous->m_next;
            }
            std::cout << current->m_value << " -> ";
            current = previous;
         }
         std::cout << current->m_value << std::endl;
      }
   }
};
