//#include "Vector.hpp"
//#include "LinkedList.hpp"
#include <iostream> 
#include "Graph.h"
#include "TreeList.h"
#include "Interface.h"
//#include "LinkedListTest.h"
//#include "QueueTest.h"  
//#include "StackTest.h"
//#include "CircularLinkedListTest.h"
//#include "DoubleLinkedListTest.h"
//#include "CircularDoubleLinkedListTest.h"
//#include "BinaryTreeTest.h"      
//#include "Tree.h"       
                                             
// template <class T, class R> inline bool compare(const T &a, const R &b) {
// return a > b;           
//}              
// void getAndPrintNum(int* t_num);          
                                            
int main() {                               
  try{                   
    //testLinkedList();                                         
    //testQueue();                   
    //testStack();         
    // Vector<int> v2(arr, 5);
    //for (size_t i = 0; i < v2.size(); i++) {
    //std::cout << v2.at(i) << "\n";
    // }   
           
     //testCircularLinkedList();     
     // testDoubleLinkedList();  
    //testCircularDoubleLinkedList();
     //testBinaryTree();
    //testDoubleLinkedList();       
    // testTree(); 
    //testTreeList();           
    //testGraph();                    
    beginInterface();     
  }                        
  catch(std::out_of_range e) {
    std::cout << e.what() << "\n ";
  }                            
}                                                         
                   
  /*  
  int arr[5] = {10, 20, 30, 40, 50};
  Vector<int> v1(10);
  Vector<int> v2(arr, 5);
  Vector<int> v3;  
  int* ptrArray;
               
  try {      
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);   
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(11);
     
    ptrArray = v1.data();
         
    v1.empty();   
             
    v1.capacity(); 
    v1.shrink_To_Fit();
    v1.capacity();  
    v1.back();
    v1.reserve(8);
    v1.capacity();
    v1.pop_Back();
    v1.front();   
    v1.back();
    v1.pop_Back();   
    v1.back(); 
      
    v1.clear();  
    v2.capacity(); 
    v2.size();
    v1.empty(); 
    v3.empty();    
           
    //for (size_t i = 0; i < v2.size(); i++) {
    // std::cout << v2.at(i) << "\n";
    //}
                              
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  } catch (...) {
    std::cout << "   eje je je je \n";
  }
  */  
                                 
/*std::cout << "Helo World!\n";
int i = 6;
int *ptr;
// ptr **ptr_c;
//  la dirección se llama referencia

std::cout << compare<int, int>(2, 5) << "\n";
std::cout << i << "\n";
std::cout << &i << "\n";
std::cout << ptr << "\n";
ptr = &i;
std::cout << ptr << "\n";     
std::cout << *ptr << "\n";

ptr = new int(9);
std::cout << *ptr << "\n";                
ptr = new int[3];
std::cout << *ptr << "\n";
int arr[3] = {5, 6, 7};
std::cout << arr << "\n";
std::cout << arr[0] << "\n";
std::cout << (arr + 2) << "\n";
std::cout << *(arr + 2) << "\n";*/
/*
  int valorNum = 5;         
  int* pValorNum = nullptr;     

  cout<<pValorNum<<endl;
  cout<<"Print num in main: "<<valorNum<<endl;

  getAndPrintNum(&valorNum);

  cout<<"Print num in main: "<<valorNum<<endl;*/
/*
void getAndPrintNum(int* t_num){
  //t_num++;
  cout<<"num: " <<t_num<<endl;
}; 
*/                                           