#include "DoubleLinkedListTest.h"

void testDoubleLinkedList(){
  std::cout<<"Start Double L list\n";
  DoubleLinkedList<int> doubleLL;
  doubleLL.push_back(5);
  doubleLL.push_back(34);
  doubleLL.push_back(77);
  doubleLL.printList();
  doubleLL.push_front(2);
  doubleLL.printList();
  doubleLL.insert(11, 2);
  doubleLL.printList();
  doubleLL.insertOrdered(50);
  doubleLL.printList();
  doubleLL.insertOrdered(60);
  doubleLL.printList();
 //doubleLL.insertOrdered(20);
  //doubleLL.printList();
 /* doubleLL.insertOrdered(1);
  doubleLL.printList();*/
  std::cout<<"Finish Double L list\n\n";
 // doubleLL.push_back(5);
}