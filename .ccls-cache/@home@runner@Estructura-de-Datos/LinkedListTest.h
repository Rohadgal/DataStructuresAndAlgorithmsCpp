#pragma once
#include "LinkedList.hpp"
#include <iostream>

void testLinkedList(){
  
  int arr[6] = {3,4,6,6,7,6};
  LinkedList<int> ll_1(arr, 6);  
  ll_1.printList();
  
  ll_1.pop_back();
  ll_1.printList();
  
  ll_1.insert(8,1);  
  ll_1.printList();

  LinkedList<int> ll_3;
  std::cout<<ll_1.empty()<<"\n";
  ll_1.erase(2);   
  ll_1.printList();    
  
  ll_1.eraseAll(7);         
  ll_1.printList();   

  ll_1.push_back(13);
  ll_1.printList();  

  
  ll_1.push_front(1);
  ll_1.printList(); 
  
  ll_1.pop_front();
  ll_1.printList(); 
  
  ll_1.eraseAll(6);              
  ll_1.printList();  

  ll_1.clear();
  ll_1.printList();
  std::cout<<ll_1.empty()<<"\n";

  ll_1.push_back(13);
  ll_1.printList();  
  ll_1.push_back(11);
  ll_1.printList();  
  ll_1.push_back(103);
  ll_1.printList();  
}