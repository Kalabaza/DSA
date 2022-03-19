#include <SinglyLinkedList.hpp>

int main(int argc, int** argv)
{
   {
      SinglyLinkedList<> singly_linked_list;
      singly_linked_list.add(1);
      singly_linked_list.add(45);
      singly_linked_list.add(60);
      singly_linked_list.add(12);
      singly_linked_list.traverse();
      singly_linked_list.reverseTraversal();
      singly_linked_list.remove(45);
      singly_linked_list.traverse();
      singly_linked_list.reverseTraversal();
      return 0;
   }

}
