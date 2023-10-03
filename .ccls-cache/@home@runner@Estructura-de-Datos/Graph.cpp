#include "Graph.h"

void testGraph(){
  int array[4] = {7, 5, 11, 14};
  std::cout<<"\n------GRAFO------\n";
  Graph<int> graph_0;
  Graph<int> graph_1(5);
  std::cout<<"todo biem\n";
  std::cout<<std::boolalpha<<graph_1.BFS(5)<<std::endl;
  std::cout<<graph_1.BFS(6)<<std::endl;
  graph_1.traverse();
  Graph<int> graph_2(4, array, 4);
  graph_2.add(17, 14);
  graph_2.add(11, 17);
  graph_2.add(8, 7);
  graph_2.add(12, 5);
  graph_2.add(22, 8);
  graph_2.add(22, 12);
  graph_2.add(5, 8);
  graph_2.traverse();
  std::cout<<graph_2.empty()<<"\n";
  graph_2.clear();
  std::cout<<graph_2.empty()<<"\n";
  std::cout<<graph_2.BFS(7)<<std::endl;
  graph_1.clear();
}
     