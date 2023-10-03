#include "CircularLinkedListTest.h"

void testCircularLinkedList(){
  std::cout<<"Start Circular list\n";
  CircularLinkedList<int> circularList;
  circularList.push_back(4);
  circularList.push_back(50);
  circularList.printList();
  circularList.push_front(6);
  circularList.printList();
  circularList.empty();
  circularList.clear();
  circularList.printList();
  std::cout<<"finish Cicular list\n\n";
 // doubleLL.push_back(5);
}