#pragma once
#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
#include "LinkedList.hpp"
#include "Vector.hpp"

/**
*
*
*/
template <class T>
class TreeList{
private:
  class Node{
    private:
    Node* parentNode;
    bool m_hasChildren;
    T m_data;
    //Vector<Node*> m_children;
    LinkedList<Node*> m_children;
    friend class TreeList;
  };
  Node* m_pRoot = nullptr;
  // Accesors
  size_t m_size;
  Node* dataBFS(T t_data);
  Node* dataDFS(T t_data);
  // Modifiers
  Node* generateNode(T t_data);
public:
  // Constructor
  TreeList();
  TreeList(T t_data);
  TreeList(T t_data, T t_children[], size_t t_sizeArray);


  // Accesors
  bool empty();
  bool BFS(T t_data);
  bool DFS(T t_data);
  void traverse();
  // Modifiers
  void add(T t_data, T t_parent);
  void clear();
};



/*
* @brief Default constructor that creates
* a Tree with nullptr in m_pRoot and m_pLast and m_size = 0;
*/
template<class T>
TreeList<T>::TreeList(){
  m_pRoot = nullptr;
  m_size = 0;
}

/*
* @brief Constructor that creates
* a Tree with size = 1
* @param t_data is the value stored in the Tree
*/
template<class T>
TreeList<T>::TreeList(T t_data){
  m_pRoot = generateNode(t_data);
}

/*
* @brief Constructor that creates
* a Tree with copies of the array passed as a parameter
* @param t_array is the array used to create the tree with the given values
* @param t_capacity sets the capacity of the tree to match the array's parameter size
*/
template<class T>
TreeList<T>::TreeList(T t_data, T t_children[], size_t t_sizeArray){
  m_pRoot = generateNode(t_data);
  m_pRoot->m_hasChildren = true;
  //size_t index = 0;
  //size_t size = *(&t_children + 1) - t_children;
  //while(t_children[index]){
  //add(t_children[index], m_pRoot->m_data);
//  }
  for(size_t i = 0; i < t_sizeArray; i++){
    add(t_children[i], m_pRoot->m_data);
  }
}

/**
* @brief Generates a Node for new data.
* @param t_data is used to give value to the data in the new Node.
*/
template<class T>
typename TreeList<T>::Node* 
TreeList<T>::generateNode(T t_data){
  Node* newNode = new Node();
  newNode->m_data = t_data;
  m_size++;
  return newNode;
}

/*
* @brief Return true if the TreeList is empty.
*
*/
template<class T>
bool TreeList<T>::empty(){
  return !m_pRoot;
}

/*
* @brief Returns true if the data passed in is found in the tree using BFS.
* @param t_data is the data to look for in the tree.
*/
template<class T>
bool TreeList<T>::BFS(T t_data){
   if(!m_pRoot){
    return false;
  }

  if(m_pRoot->m_data == t_data){
    return true;
  }
  /*
  bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; ++i) {
      visited[i] = false;
    }
  visited[0] = true;*/

  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    if(pCurrent->m_data == t_data){
      return true;
    }
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        queue_Temp.enqueue(pCurrent->m_children.at(i));
      }
    }
  }
  return false;
}

/*
* @brief Returns a Node pointer if the data passed in is found in the tree using BFS.
* @param t_data is the data to look for in the tree.
*/
template<class T>
typename TreeList<T>::Node* 
TreeList<T>::dataBFS(T t_data){
  if(!m_pRoot){
    return nullptr;
  }

  if(m_pRoot->m_data == t_data){
    return m_pRoot;
  }

  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    if(pCurrent->m_data == t_data){
      return pCurrent;
    }
    if(pCurrent->m_hasChildren){
       for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        queue_Temp.enqueue(pCurrent->m_children.at(i));
      }
    }
  }
  return nullptr;
}

/*
* @brief Return true if t_data is found in the TreeList using DFS.
* @param t_data is the value fo be found in the true.
*/
template<class T>
bool TreeList<T>::DFS(T t_data){
  if(!m_pRoot){
    return false;
  }

  if(m_pRoot->m_data == t_data){
    return true;
  }

  Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp(pTemp);
  //stack_Temp.printList();
  while(!stack_Temp.empty()){
    Node* pCurrent = stack_Temp.pop_front();
    if(pCurrent->m_data == t_data){
      return true;
    }
    if(pCurrent->m_hasChildren){ // or ->m_children[0]
       //LinkedList<Node*> tempList = pCurrent->m_children;
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        stack_Temp.push_front(pCurrent->m_children.at(i));
      }
     // while(tempList.returnRoot()){ // alguna forma de ver toda la lista
      //  stack_Temp.push_front(pCurrent->m_children.nodeData());
        
      //  tempList.pop_front();
      
    }
  }
  return false;
}

/*
* @brief Return a the Node pointer if t_data is found in the TreeList using DFS.
* @param t_data is the value fo be found in the true.
*/
template<class T>
typename TreeList<T>::Node*
TreeList<T>::dataDFS(T t_data){
  if(!m_pRoot){
    return nullptr;
  }

  if(m_pRoot->m_data == t_data){
    return m_pRoot;
  }

  Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp(pTemp);
  //stack_Temp.printList();
  while(!stack_Temp.empty()){
    Node* pCurrent = stack_Temp.pop_front();
    if(pCurrent->m_data == t_data){
      return pCurrent;
    }
    if(pCurrent->m_hasChildren){ // or ->m_children[0]
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        stack_Temp.push_front(pCurrent->m_children.at(i));
      }
    }
  }
  return nullptr;
}

/*
* @brief Prints all the values in the tree.
*/
template<class T>
void TreeList<T>::traverse(){ 
  if(!m_pRoot){
      return nullptr;
  }
  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    std::cout<<pCurrent->m_data<<"{";
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        std::cout<<pCurrent->m_children.at(i)->m_data<<",";
        queue_Temp.enqueue(pCurrent->m_children.at(i));
         }
      }
      std::cout<<"}\n";
    }
}
 
/*
* @brief Adds new data to the tree.
* @param t_data is the number to be added to the tree.
* @param t_parent is the parent Data of the t_data to be added.
*/
template<class T>
void TreeList<T>::add(T t_data, T t_parent){ 

  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    return;
  }
  
  if(DFS(t_data)){
    return;
  }

  Node* pTemp = dataBFS(t_parent);
  if(!pTemp){
    return;
  }
  //std::cout<<pTemp->m_children.empty()<<std::endl;
  Node* newNode = generateNode(t_data);
  newNode->parentNode = pTemp;
  pTemp->m_children.push_back(newNode);
  pTemp->m_hasChildren = true;
}  

/*
* @brief Deletes all the nodes and clears the tree.
*/
template<class T>
void TreeList<T>::clear(){
  if(!m_pRoot){
    return;
  }
  Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp;
  stack_Temp.push_front(pTemp);
  Node* deleteNode = nullptr;
  while(!stack_Temp.empty()){
    deleteNode = stack_Temp.pop_front();  
    if(deleteNode->m_hasChildren){
      for(size_t i = 0; i < deleteNode->m_children.size(); i++){
        stack_Temp.push_front(deleteNode->m_children.at(i));
      }
      //deleteNode->m_children.clear();
    }
    delete [] deleteNode;
    deleteNode = nullptr;
  }
  m_pRoot->parentNode = nullptr;
  m_pRoot->m_hasChildren = false;
  m_size = 0;
  m_pRoot = nullptr;
}