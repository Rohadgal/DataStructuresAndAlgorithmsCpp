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
class Tree{
private:
  class Node{
    private:
    Node* parentNode;
    bool m_hasChildren;
    T m_data;
    Vector<Node*> m_children;
    friend class Tree;
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
  Tree();
  Tree(T t_data);
  Tree(T t_data, T t_children[], size_t t_sizeArray);

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
*
*
*/
template<class T>
Tree<T>::Tree(){
  m_pRoot = nullptr;
  m_size = 0;
}

/*
*
*
*/
template<class T>
Tree<T>::Tree(T t_data){
  m_pRoot = generateNode(t_data);
}

/*
*
*
*/
template<class T>
Tree<T>::Tree(T t_data, T t_children[], size_t t_sizeArray){
  m_pRoot = generateNode(t_data);
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
*
*
*/
template<class T>
typename Tree<T>::Node* 
Tree<T>::generateNode(T t_data){
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
bool Tree<T>::empty(){
  return !m_pRoot;
}

/*
* @brief R
*/
template<class T>
bool Tree<T>::BFS(T t_data){
  if(!m_pRoot){
    return false;
  }

  if(m_pRoot->m_data == t_data){
    return true;
  }

  Node* pTemp = m_pRoot;
  Queue<Node*> queue_Temp(pTemp);
  while(!queue_Temp.empty()){
    Node* pCurrent = queue_Temp.dequeue();
    if(pCurrent->m_data == t_data){
      return true;
    }
    if(pCurrent->m_hasChildren){
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        queue_Temp.enqueue(pCurrent->m_children[i]);
      }
    }
  }
  return false;
}

/*
* @brief R
*/
template<class T>
typename Tree<T>::Node* 
Tree<T>::dataBFS(T t_data){
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
        queue_Temp.enqueue(pCurrent->m_children[i]);
      }
    }
  }
  return nullptr;
}

/*
* @brief Return true if t_data is in the Tree.
* @param t_data is the value fo be found in the true.
*/
template<class T>
bool Tree<T>::DFS(T t_data){
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
      for(size_t i = 0; i < pCurrent->m_children.size(); i++){
        stack_Temp.push_front(pCurrent->m_children[i]);
      }
    }
  }
  return false;
}

/*
* @brief Return true if t_data is in the Tree.
* @param t_data is the value fo be found in the true.
*/
template<class T>
typename Tree<T>::Node*
Tree<T>::dataDFS(T t_data){
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
        stack_Temp.push_front(pCurrent->m_children[i]);
      }
    }
  }
  return nullptr;
}

/*
* @brief 
*/
template<class T>
void Tree<T>::traverse(){ 
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
        queue_Temp.enqueue(pCurrent->m_children[i]);
        std::cout<<pCurrent->m_children[i]->m_data<<",";
      }
    }
    std::cout<<"}\n";
  }
}
 
/*
* @brief 
*/
template<class T>
void Tree<T>::add(T t_data, T t_parent){ 
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
* @brief 
*/
template<class T>
void Tree<T>::clear(){
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
        stack_Temp.push_front(deleteNode->m_children[i]);
      }
      //deleteNode->m_children.clear();
      //delete [] deleteNode->m_children;
    }
    delete [] deleteNode;
    deleteNode = nullptr;
  }
  m_pRoot->parentNode = nullptr;
  m_pRoot->m_hasChildren = false;
  m_size = 0;
  m_pRoot = nullptr;
}