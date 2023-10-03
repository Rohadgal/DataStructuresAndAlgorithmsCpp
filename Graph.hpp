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
template<class T>
class Graph{
private:
  class Node{
  private:
    Node* parentNode;
    bool m_hasChildren;
    bool m_visited;
    T m_data;
    LinkedList<Node*> m_children;
    friend class Graph;
  };
  Node* m_pRoot = nullptr;
  // Accesors
  size_t m_size;
  Node* dataBFS(T t_data);
  Node* dataDFS(T t_data);
  // Modifieres
  Node* generateNode(T t_data);
public:
  // Constructor
  Graph();
  Graph(T t_data);
  Graph(T t_data, T t_children[], size_t t_sizeArray);

  // Accesors
  bool empty();
  bool BFS(T t_data);
  bool DFS(T t_data);
  void traverse();
  // Modifiers
  void add(T t_data, T t_parent);
  void clear();
};

/**
* @brief Default constructor that creates
* a Graph with nullptr in m_pRoot and m_pLast and m_size = 0;
*/
template<class T>
Graph<T>::Graph(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
* @brief Constructor that creates
* a Graph with size = 1
* @param t_data is the value stored in the Graph.
*/
template<class T>
Graph<T>::Graph(T t_data){
  m_pRoot = generateNode(t_data);
}

/**
* @brief Constructor that creates
* a Graph with copies of the array passed as a parameter
* @param t_array is the array used to create the graph with the given values
* @param t_capacity sets the capacity of the graph to match the array's parameter size
*/
template<class T>
Graph<T>::Graph(T t_data, T t_children[], size_t t_sizeArray){
  m_pRoot = generateNode(t_data);
  m_pRoot->m_hasChildren = true;

 // m_pRoot->m_children.push_back(generateNode(t_children[0]));
//  m_size = 2;
  for(size_t i = 0; i < t_sizeArray; i++){
    add(t_children[i], m_pRoot->m_data);
  }
}

/**
* @brief Generates a Node for new data.
* @param t_data is used to give value to the data in the new Node.
*/
template<class T>
typename Graph<T>::Node* 
Graph<T>::generateNode(T t_data){
  Node* newNode = new Node();
  newNode->m_data = t_data;
  m_size++;
  return newNode;
}

/*
* @brief Return true if the Tree is empty.
*
*/
template<class T>
bool Graph<T>::empty(){
  return !m_pRoot;
}



/*
* @brief Returns true if the data passed in is found in the graph using BFS.
* @param t_data is the data to look for in the graph.
*/
template<class T>
bool Graph<T>::BFS(T t_data){
  if(!m_pRoot){
    return false;
  }

  if(m_pRoot->m_data == t_data){
    return true;
  }
  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  LinkedList<Node*> visitedNodes;
  
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    pCurrent->m_visited = true;
    visitedNodes.push_back(pCurrent);
    if(pCurrent->m_data == t_data){
      for(size_t i = 0; i < visitedNodes.size(); i++){
       visitedNodes.at(i)->m_visited = false;
      }
      return true;
    }
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
      //pCurrent->m_children.at(i)->m_visited = true;
       if(!pCurrent->m_children.at(i)->m_visited){
          queue_Temp.enqueue(pCurrent->m_children.at(i));
        }
      }
      // check out the visited problem
    }
  }
   for(size_t i = 0; i < visitedNodes.size(); i++){
    visitedNodes.at(i)->m_visited = false;
  }
  return false;
}
  
/* 
* @brief Returns a Node pointer if the data passed in is found in the graph using BFS.
* @param t_data is the data to look for in the tree.
*/
template<class T>
typename Graph<T>::Node* 
Graph<T>::dataBFS(T t_data){
  if(!m_pRoot){
    return nullptr;
  }

  if(m_pRoot->m_data == t_data){
    return m_pRoot;
  }

  Queue<Node*> queue_Temp(m_pRoot);
  LinkedList<Node*> visitedNodes;
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    pCurrent->m_visited = true;
    visitedNodes.push_back(pCurrent);
    if(pCurrent->m_data == t_data){
      for(size_t i = 0; i < visitedNodes.size(); i++){
       visitedNodes.at(i)->m_visited = false;
      }
      return pCurrent;
    }
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        //pCurrent->m_children.at(i)->m_visited = true;
        if(!pCurrent->m_children.at(i)->m_visited){
          queue_Temp.enqueue(pCurrent->m_children.at(i));
        }
      }
    }
  }
  for(size_t i = 0; i < visitedNodes.size(); i++){
    visitedNodes.at(i)->m_visited = false;
  }
  return nullptr;
}

/* 
* @brief Return true if t_data is found in the Graph using DFS.
* @param t_data is the value fo be found in the true.
*/
template<class T>
bool Graph<T>::DFS(T t_data){
  if(!m_pRoot){
    return false;
  }

  if(m_pRoot->m_data == t_data){
    return true;
  }

  Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp(pTemp);
  LinkedList<Node*> visitedNodes;
  //stack_Temp.printList();
  while(!stack_Temp.empty()){
    Node* pCurrent = stack_Temp.pop_front();
    pCurrent->m_visited = true;
    visitedNodes.push_back(pCurrent);
    if(pCurrent->m_data == t_data){
      for(size_t i = 0; i < visitedNodes.size(); i++){
       visitedNodes.at(i)->m_visited = false;
      }
      return true;
    }
    if(pCurrent->m_hasChildren){ //
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
       // pCurrent->m_children.at(i)->m_visited = true;
        if(!pCurrent->m_children.at(i)->m_visited){
          stack_Temp.push_front(pCurrent->m_children.at(i));
        }
      }
    }
  }

  for(size_t i = 0; i < visitedNodes.size(); i++){
    visitedNodes.at(i)->m_visited = false;
  }
  //pTemp->m_visited = false;
  return false;
}

/*
* @brief Return a the Node pointer if t_data is found in the Graph using DFS.
* @param t_data is the value fo be found in the true.
*/
template<class T>
typename Graph<T>::Node*
Graph<T>::dataDFS(T t_data){
  if(!m_pRoot){
    return nullptr;
  }

  if(m_pRoot->m_data == t_data){
    return m_pRoot;
  }

  Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp(pTemp);
  LinkedList<Node*> visitedNodes;
  //stack_Temp.printList();
  while(!stack_Temp.empty()){
    Node* pCurrent = stack_Temp.pop_front();
    pCurrent->m_visited = true;
    visitedNodes.push_back(pCurrent);
    if(pCurrent->m_data == t_data){
      for(size_t i = 0; i < visitedNodes.size(); i++){
       visitedNodes.at(i)->m_visited = false;
      }
      return pCurrent;
    }
    if(pCurrent->m_hasChildren){ // or ->m_children[0]
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        if(!pCurrent->m_children.at(i)->m_visited){
          stack_Temp.push_front(pCurrent->m_children.at(i));
        }
      }
    }
  }
  for(size_t i = 0; i < visitedNodes.size(); i++){
    visitedNodes.at(i)->m_visited = false;
  }
  return nullptr;
}

/*
* @brief Prints all the values in the graph.
*/
template<class T>
void Graph<T>::traverse(){ 
  if(!m_pRoot){
    return nullptr;
  }
  
  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  LinkedList<Node*> visitedNodes;
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    pCurrent->m_visited = true;
    visitedNodes.push_back(pCurrent);
    std::cout<<pCurrent->m_data<<"{";
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        if(!pCurrent->m_children.at(i)->m_visited){
          //std::cout<<"ssss ";
          //pCurrent->m_children.at(i)->m_visited = true;
          queue_Temp.enqueue(pCurrent->m_children.at(i)); 
        }
        std::cout<<pCurrent->m_children.at(i)->m_data<<",";
      }
    }
    std::cout<<"}\n";
  }
  for(size_t i = 0; i < visitedNodes.size(); i++){
    visitedNodes.at(i)->m_visited = false;
  }
  //pTemp->m_visited = false;
}

/*
* @brief Adds new data to the graph.
* @param t_data is the number to be added to the graph.
* @param t_parent is the parent Data of the t_data to be added.
*/
template<class T>
void Graph<T>::add(T t_data, T t_parent){ 

  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    return;
  }
  
  if(t_data == t_parent){
    return;
  }
  
  if(DFS(t_parent)){
    Node* pTempParent = dataDFS(t_parent);
    pTempParent->m_hasChildren = true;
    if(BFS(t_data)){
      pTempParent->m_children.push_back(dataBFS(t_data));
      return;
    }
    pTempParent->m_children.push_back(generateNode(t_data));
  }
} 

/*
* @brief Deletes all the nodes and clears the graph.
*/
template<class T>
void Graph<T>::clear(){
  if(!m_pRoot){
    return;
  }
  //Node* pTemp = m_pRoot;
  Stack<Node*> stack_Temp(m_pRoot);
  //stack_Temp.push_front(m_pRoot);
  Node* deleteNode = nullptr;
  while(!stack_Temp.empty()){
    deleteNode = stack_Temp.pop_front(); 
    deleteNode->m_visited = true;
    if(deleteNode->m_hasChildren){
      for(size_t i = 0; i < deleteNode->m_children.size(); i++){
        if(!deleteNode->m_children.at(i)->m_visited){
        stack_Temp.push_front(deleteNode->m_children.at(i));
        }
      }
      //deleteNode->m_children.clear();
    }
    deleteNode->m_visited = false;
    delete [] deleteNode;
    deleteNode = nullptr;
  }
  m_pRoot->parentNode = nullptr;
  m_pRoot->m_hasChildren = false;
  m_size = 0;
  m_pRoot = nullptr;
}