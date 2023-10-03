#include "BinaryTreeTest.h"

int arr[5] = {10, 20, 30, 40, 50}; 

void testBinaryTree(){
  BinaryTree<int> bT(arr, 5);
  std::cout << std::boolalpha << bT.empty() << std::endl;
  std::cout<<bT.find(20)<<std::endl;
  std::cout<<bT.find(35)<<std::endl;
  bT.clear();
  std::cout<<bT.empty()<<std::endl;
  BinaryTree<int> bT2;
  bT2.add(45);
  std::cout<<bT2.empty()<<std::endl;
  
}