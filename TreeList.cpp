#include "TreeList.h"

void testTreeList(){
  int arr[4] = {6, 7, 9, 3};
  std::cout<<"\n-----Tree with LinkedList------\n";
  TreeList<int> treeList_1(4);
  std::cout<<std::boolalpha<<treeList_1.empty()<<std::endl;
  treeList_1.add(7, 4);
  std::cout<<treeList_1.DFS(7)<<std::endl;
  std::cout<<"esto\n";
  std::cout<<treeList_1.empty()<<"\n";
  treeList_1.add(5, 4);
  treeList_1.add(9, 5);
  treeList_1.add(9, 4);
  std::cout<<"aqui\n";
  treeList_1.traverse();
  std::cout<<"aca\n\n";
  TreeList<int> treeList_2(2, arr, 4);
  treeList_2.add(8, 3);
  treeList_2.add(11, 8);
  treeList_2.traverse();
  std::cout<<"\n";
  TreeList<int> treeList_0;
  std::cout<<treeList_0.empty();
  treeList_2.clear();
  std::cout<<"\n"<<treeList_2.empty();
}