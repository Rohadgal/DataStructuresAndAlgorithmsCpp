#include "StackTest.h"

void testStack(){
  std::cout<<std::endl;
  Stack<int> sta_1;
  Stack<int> sta_2(1);
  sta_2.printList();
  sta_2.push_front(34);
  sta_2.printList();
  std::cout<<"last: "<<sta_2.lastData()<<std::endl;
  sta_2.push_front(3);
  sta_2.printList();
  sta_2.push_front(52);
  sta_2.printList();
  std::cout<<"last: "<<sta_2.lastData()<<std::endl;
  LinkedList<int> lList = sta_2.sort();
  lList.printList();
  std::cout<<"empty: "<<sta_2.empty()<<std::endl;
  std::cout<<sta_2.at(3)<<std::endl;
  std::cout<<"pop front: "<<sta_2.pop_front()<<std::endl;
  sta_2.printList();
  std::cout<<"pop front: "<<sta_2.pop_front()<<std::endl;
  sta_2.printList();
  std::cout<<"clear\n";
  sta_2.clear();
  sta_2.printList();
  std::cout<<"empty: "<<sta_2.empty()<<std::endl;
}