#pragma once
#include <iostream>
#include "TreeList.h"
#include "Graph.h"

enum flow{none, starting, operating, done};

template<class T> 
class Interface{
private:
  class Node{
  private:
    T m_data;
    friend class Interface;
  };
  Node* m_pRoot = nullptr;
  flow state = none;
  // public
public:
  Interface();
  Interface(T t_data);
  T select(size_t t_choice);
  T returnData();
  //void state(flow t_state);
  void changeState(flow t_state);
};

/**
  *
  *
  */
template<class T>
Interface<T>::Interface(){
  //m_data;
}

/**
  *
  *
  */
template<class T>
Interface<T>::Interface(T t_data){
  //m_data;
}

/**
  *
  *
  */
template<class T>
void Interface<T>::changeState(flow t_state){
  
  switch(t_state){
    case 0:{
      break;
    }
    case 1:{
      
    }
  }
}




/*
template<class T>
T Interface<T>::select(size_t t_choide){
  switch(t_choice){
    case 1:
      size_t treeChoice;
        std::cout<<"What type of tree do you want to create?\n";
        std::cout<<"1) Empty tree\n";
        std::cout<<"2) Tree with root\n";
        std::cout<<"3) Tree with leaves\n";
        std::cin>>treeChoice;

      switch(treeChoice){
        case 1:
        TreeList<int> tree_0;
        return tree_0;
        break;
        case 2: 
        size_t rootData;
        std::cout<<"Please type the integer value you want for the root:\n";
        std::cin>>rootData;
        TreeList<int> tree_1(rootData);
        return tree_1;
        break;
      }
    break;
    case 2:
    break;
  }

  return T data = 0;
}
*/

  