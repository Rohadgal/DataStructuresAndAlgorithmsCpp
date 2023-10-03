#include "Tree.h"

int valuesArray[4] = {3, 6, 8, 9};

void testTree(){
  Tree<int> tree_1(4);
  std::cout<<std::boolalpha<<tree_1.empty()<<std::endl;
  std::cout<<tree_1.DFS(7)<<std::endl;
  tree_1.add(5, 4);
  tree_1.traverse();
  tree_1.add(7, 4);
  tree_1.add(9, 4);
  tree_1.traverse();
  std::cout<<"\n";
  Tree<int> tree_2(2, valuesArray, 4);
  tree_2.traverse();
  tree_2.add(11, 8);
  tree_2.add(13, 8);
  tree_2.add(34, 13);
  tree_2.traverse();
  std::cout<<"\n";
  Tree<int> tree_0;
  std::cout<<tree_0.empty();
  tree_2.clear();
  std::cout<<"\n"<<tree_2.empty();
}