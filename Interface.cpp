#include "Interface.h"

void beginInterface(){

  bool programFinished = false;
  
  size_t choice;

  while(!programFinished){
    std::cout<<"\nWelcome..\n";
    std::cout<<"Do you want to make a tree or a graph?\n";
    std::cout<<"If you want to make a tree you need to type in 1.\n";
    std::cout<<"If you want to make a graph you need to type in 2.\n";
    std::cout<<"1) tree\n";
    std::cout<<"2) graph\n";
    std::cout<<"3) quit\n";
    std::cin>>choice;

    switch(choice){
      case 1:{
        bool treeIsFinished = false;
        while(!treeIsFinished){
          size_t treeChoice;
          std::cout<<"\nWhat type of tree do you want to create?\n";
          std::cout<<"1) Empty tree.\n";
          std::cout<<"2) Tree with root.\n";
          std::cout<<"3) Tree with leaves.\n";
          std::cout<<"4) Exit.\n";
          std::cin>>treeChoice;
          
          switch(treeChoice){
            case 1:{
              TreeList<int> tree_0;
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"\nWhat would you like to do?\n";
                std::cout<<"1) Add node to the tree.\n";
                std::cout<<"2) Delete all nodes from the Tree.\n";
                std::cout<<"3) Check if a number exists in the Tree using BFS.\n";
                std::cout<<"4) Check if a number exists in the Tree using DFS.\n";
                std::cout<<"5) Check if the tree is empty.\n";
                std::cout<<"6) Print the tree.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                std::cout<<"\n";
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the tree?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the tree).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the tree).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    tree_0.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    tree_0.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_0.BFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_0.DFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 5:{
                    if(tree_0.empty()){
                      std::cout<<"The tree is empty.\n";
                      break;
                    }
                    std::cout<<"The tree is not empty.\n";
                    break;
                  }
                  case 6:{
                    tree_0.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    tree_0.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 2:{
              int rootData;
              std::cout<<"\nPlease type the integer value you want for the root:\n";
              std::cin>>rootData;
              TreeList<int> tree_1(rootData);
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"What would you like to do?\n";
                std::cout<<"1) Add node to the tree.\n";
                std::cout<<"2) Delete all nodes from the Tree.\n";
                std::cout<<"3) Check if a number exists in the Tree using BFS.\n";
                std::cout<<"4) Check if a number exists in the Tree using DFS.\n";
                std::cout<<"5) Check if the tree is empty.\n";
                std::cout<<"6) Print the tree.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                std::cout<<"\n";
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the tree?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the tree).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the tree).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    tree_1.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    tree_1.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_1.BFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_1.DFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 5:{
                    if(tree_1.empty()){
                      std::cout<<"The tree is empty.\n";
                      break;
                    }
                    std::cout<<"The tree is not empty.\n";
                    break;
                  }
                  case 6:{
                    tree_1.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    tree_1.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 3:{
              int rootData;
              size_t arraySize;
              
              std::cout<<"\nPlease type the integer value you want for the root:\n";
              std::cin>>rootData;
              std::cout<<"Please enter the size of the array and the values:\n";
              std::cout<<"size: ";
              std::cin>>arraySize;
              int arrayValues[arraySize];
              for(size_t i = 0; i < arraySize; i++){
                std::cout<<"Write an integer value: ";
                std::cin>>arrayValues[i];
                std::cout<<"\n";
              }
              std::cout<<"\n";
              TreeList<int> tree_2(rootData, arrayValues, arraySize);
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"\nWhat would you like to do?\n";
                std::cout<<"1) Add node to the tree.\n";
                std::cout<<"2) Delete all nodes from the Tree.\n";
                std::cout<<"3) Check if a number exists in the Tree using BFS.\n";
                std::cout<<"4) Check if a number exists in the Tree using DFS.\n";
                std::cout<<"5) Check if the tree is empty.\n";
                std::cout<<"6) Print the tree.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the tree?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the tree).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the tree).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    tree_2.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    tree_2.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_2.BFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the tree: \n";
                    std::cin>>searchNum;
                    
                    if(tree_2.DFS(searchNum)){
                      std::cout<<"The number exists in the tree.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the tree.\n";
                    break;
                  }
                  case 5:{
                    if(tree_2.empty()){
                      std::cout<<"The tree is empty.\n";
                      break;
                    }
                    std::cout<<"The tree is not empty.\n";
                    break;
                  }
                  case 6:{
                    tree_2.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    tree_2.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 4:{
              treeIsFinished = true;
              break;
            }
            default: std::cout<<"Esta entrada no es válida. Intente de nuevo.\n";
          } 
        }
        break;
      }
      case 2:{  
        bool graphIsFinished = false;
        while(!graphIsFinished){
          size_t graphChoice;
          std::cout<<"\nWhat type of graph do you want to create?\n";
          std::cout<<"1) Empty graph.\n";
          std::cout<<"2) Graph with root.\n";
          std::cout<<"3) Graph with leaves.\n";
          std::cout<<"4) Exit.\n";
          std::cin>>graphChoice;

          switch(graphChoice){
            case 1:{
              Graph<int> graph_0;
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"\nWhat would you like to do?\n";
                std::cout<<"1) Add node to the graph.\n";
                std::cout<<"2) Delete all nodes from the graph.\n";
                std::cout<<"3) Check if a number exists in the graph using BFS.\n";
                std::cout<<"4) Check if a number exists in the graph using DFS.\n";
                std::cout<<"5) Check if the graph is empty.\n";
                std::cout<<"6) Print the graph.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                std::cout<<"\n";
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the graph?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the tree).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the tree).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    graph_0.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    graph_0.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_0.BFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_0.DFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 5:{
                    if(graph_0.empty()){
                      std::cout<<"The graph is empty.\n";
                      break;
                    }
                    std::cout<<"The graph is not empty.\n";
                    break;
                  }
                  case 6:{
                    graph_0.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    graph_0.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 2:{
              int rootData;
              std::cout<<"\nPlease type the integer value you want for the root:\n";
              std::cin>>rootData;
              Graph<int> graph_1(rootData);
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"\nWhat would you like to do?\n";
                std::cout<<"1) Add node to the graph.\n";
                std::cout<<"2) Delete all nodes from the graph.\n";
                std::cout<<"3) Check if a number exists in the graph using BFS.\n";
                std::cout<<"4) Check if a number exists in the graph using DFS.\n";
                std::cout<<"5) Check if the graph is empty.\n";
                std::cout<<"6) Print the graph.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                std::cout<<"\n";
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the graph?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the graph).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the graph).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    graph_1.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    graph_1.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_1.BFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_1.DFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 5:{
                    if(graph_1.empty()){
                      std::cout<<"The graph is empty.\n";
                      break;
                    }
                    std::cout<<"The graph is not empty.\n";
                    break;
                  }
                  case 6:{
                    graph_1.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    graph_1.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 3:{
              int rootData;
              size_t arraySize;
              
              std::cout<<"\nPlease type the integer value you want for the root:\n";
              std::cin>>rootData;
              std::cout<<"Please enter the size of the array and the values:\n";
              std::cout<<"size: ";
              std::cin>>arraySize;
              int arrayValues[arraySize];
              for(size_t i = 0; i < arraySize; i++){
                std::cout<<"Write an integer value: ";
                std::cin>>arrayValues[i];
                std::cout<<"\n";
              }
              Graph<int> graph_2(rootData, arrayValues, arraySize);
              size_t action;
              bool finished = false;
              while(!finished){
                std::cout<<"\nWhat would you like to do?\n";
                std::cout<<"1) Add node to the graph.\n";
                std::cout<<"2) Delete all nodes from the graph.\n";
                std::cout<<"3) Check if a number exists in the graph using BFS.\n";
                std::cout<<"4) Check if a number exists in the graph using DFS.\n";
                std::cout<<"5) Check if the graph is empty.\n";
                std::cout<<"6) Print the graph.\n";
                std::cout<<"7) Exit.\n";
                std::cin>>action;
                std::cout<<"\n";
                //Interface<TreeList<int>> interfaceTree;
                //interfaceTree.begin();
                switch(action){
                  case 1:{
                    int m_data;
                    int m_parent;
                    std::cout<<"\nWhat integer value do you want to add to the graph?\n";
                    std::cout<<"You have to pass in two different parameters: \n";
                    std::cout<<"Data: (Interger number you to pass into the graph).\n";
                    std::cout<<"Parent: (Integer number that will be the parent of the data you are pushing into the graph).\n";
                    std::cout<<"Data: ";
                    std::cin>>m_data;
                    std::cout<<"\n";
                    std::cout<<"Parent: ";
                    std::cin>>m_parent;
                    graph_2.add(m_data, m_parent);
                    break;
                  }
                  case 2:{
                    graph_2.clear();
                    std::cout<<"All nodes were deleted.\n";
                    break;
                  }
                  case 3:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_2.BFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 4:{
                    int searchNum;
                    std::cout<<"\nWhich number do you want to find in the graph: \n";
                    std::cin>>searchNum;
                    
                    if(graph_2.DFS(searchNum)){
                      std::cout<<"The number exists in the graph.\n";
                      break;
                    }
                    std::cout<<"The number doesn't exist in the graph.\n";
                    break;
                  }
                  case 5:{
                    if(graph_2.empty()){
                      std::cout<<"The graph is empty.\n";
                      break;
                    }
                    std::cout<<"The graph is not empty.\n";
                    break;
                  }
                  case 6:{
                    graph_2.traverse();
                    std::cout<<"\n";
                    break;
                  }
                  case 7:{
                    graph_2.clear();
                    finished = true;
                    break;
                  }
                  default: std::cout<<"Incorrect Input. Try Again.\n";
                }
              }
              break;
            }
            case 4:{
              graphIsFinished = true;
              break;
            }
          }
        }
        break;
      }
      case 3:{
        programFinished = true;
        break;
      }
      default: std::cout<<"Esta entrada no es válida. Intente de nuevo.\n";
    }
  }
  std::cout<<"Good bye.\n";
}