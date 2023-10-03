#include "QueueTest.h"

void testQueue(){
  Queue<int> que_1;
  Queue<int> que_2(1);
  que_1.printList();
  que_2.printList();
  que_2.enqueue(15);
  que_2.printList();
  que_2.enqueue(4);
  que_2.printList();
  que_2.enqueue(9);
  que_2.printList();
  std::cout<<que_2.at(0)<<std::endl;
  std::cout<<"first: "<<que_2.firstElement()<<std::endl;
  std::cout<<"dequeue: "<<que_2.dequeue()<<std::endl;
  std::cout<<"dequeue: "<<que_2.dequeue()<<std::endl;
  std::cout<<"first: "<<que_2.firstElement()<<std::endl;
  que_2.printList();
  que_2.enqueue(13);
  que_2.printList();
  std::cout<<"clear\n";
  que_2.clear();
  que_2.printList();
  std::cout<<"empty: "<<que_2.empty()<<std::endl;
  que_2.enqueue(15);
  que_2.printList();
  que_2.enqueue(113); 
  que_2.printList();
  std::cout<<"empty: "<<que_2.empty()<<std::endl;
  LinkedList<int> lList = que_2.sort();
  lList.printList();
  que_2.printList();
  std::cout<<"clear\n";
  lList.clear();
  std::cout<<"Queue Finished \n";
}