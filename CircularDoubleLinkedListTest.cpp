#include "CircularDoubleLinkedListTest.h"

void testCircularDoubleLinkedList(){
  std::cout<<"Start Circular Double list\n";
  CircularDoubleLinkedList<int> doubleCircularList;
  doubleCircularList.push_back(9);
  doubleCircularList.push_back(45);
  //circularList.printList();
  doubleCircularList.push_front(66);
  doubleCircularList.printList();
  doubleCircularList.pop_front();
  doubleCircularList.clear();
  doubleCircularList.printList();
  std::cout<<"finish Cicular Double list\n\n";
 // doubleLL.push_back(5);
}