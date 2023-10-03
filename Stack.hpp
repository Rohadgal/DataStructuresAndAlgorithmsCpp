#pragma once
#include "LinkedList.hpp"

template<class T>
class Stack{
private:
  class Node{
  private:
      T m_data;
      Node* m_pNext;
      friend class Stack;
  };
  Node* m_pRoot;
  Node* m_pLast;
  // Accesors
  size_t m_size;
  // Modifiers
  Node*generateNode(T t_data);
public:
  // Constructors
  Stack();
  Stack(T t_data);
  Stack(T t_array[], size_t t_size);
 // Modifiers
  void push_front(T t_data);
  T pop_front();
  void clear();
  LinkedList<T> sort();
 // Accesors 
  T lastData();
  T at(size_t t_index);
  bool empty();
  void printList();
  T top();
  T peek();
  size_t size();
};

/** 
* @brief Creates a default Stack class.
*
*/
template<class T>
Stack<T>::Stack(){
  m_pRoot = nullptr;
  m_pLast = nullptr;
  m_size = 0;
}

/**
* @brief Creates a Stack class with element given as parameter.
* @param t_data is the value passed through to the data in the stack.
*/
template<class T>
Stack<T>::Stack(T t_data){
  m_pRoot = generateNode(t_data);
  m_pRoot->m_pNext = nullptr;
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
* @brief Creates a Stack class with all the elements from the array given.
* @param t_array passes an array to build a stack.
* @param t_arraySize is the size of the Stack List about to be built.
*/
template<class T>
Stack<T>::Stack(T t_array[], size_t t_sizeArray){
  if(t_array == NULL){
    for(size_t i = 0; i < t_sizeArray; i++){
      push_front(0);
    }
  }

  for(size_t i = 0; i < t_sizeArray; i++){
    push_front(t_array[i]);
  }
}

/**
* @brief Generates a Node with new data.
* @param t_data is the value passed through to the data in the stack.
*/
template<class T>
typename Stack<T>::Node* 
Stack<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
* @brief Pushes data at the stack.
* @param t_data is the value passed through to the data in the stack.
*/
template<class T>
void Stack<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  Node* newNode = new Node();
  newNode = generateNode(t_data);
  newNode->m_pNext = m_pRoot;
  m_pRoot = newNode;
}
   
/**
* @brief Pops out the first value from the stack and returns the value removed.
* 
*/
template<class T>
T Stack<T>::pop_front(){
  if(!m_pRoot){
     throw std::length_error("Stack is empty");
  }

   if(!m_pRoot->m_pNext){
    Node* pTmp = m_pRoot;
    T data = pTmp->m_data;
    delete[] m_pRoot;
    m_pRoot = nullptr;
    m_pLast = nullptr;
    //delete[] pTmp;
    m_size--;
    return data;
  }
  Node* pTmp = m_pRoot;
  T data = pTmp->m_data;
  m_pRoot = m_pRoot->m_pNext;
  delete[] pTmp;
  m_size--;
  return data;



  /*
  T returnValue = m_pRoot->m_data;
  Node* deleteNode = m_pRoot;
  if(m_pRoot->m_pNext){
    m_pRoot = m_pRoot->m_pNext;
  }
  delete [] deleteNode;
  deleteNode = nullptr;
  
  return returnValue;*/
}

/**
* @brief Deletes all the queue.
*/ 
template<class T>
void Stack<T>::clear(){
  if(!m_pRoot){
    return;
  }
  Node* deleteNode = new Node();
  deleteNode = nullptr;
  while(m_pRoot){
    m_pRoot->m_data = 0;
    deleteNode = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    delete [] deleteNode;
    deleteNode = nullptr;
    m_size--;
  }
  m_pLast->m_pNext = nullptr;
  m_pLast = nullptr;
}

/**
* @brief Returns a LinkedList with the elements of the Stack sorted out. Uses Bubble Sort, time complexity: O(n^2).
*/ 
template<class T>
LinkedList<T> Stack<T>::sort(){  
  if(!m_pRoot){
    return;
  }
  int tempArray[m_size];
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  for(size_t i = 0; i < m_size; i++){
    tempArray[i] = pTemp->m_data;
    pTemp = pTemp->m_pNext;
  }
  pTemp = nullptr;
  int it = 0;
  while(it < m_size-1){
    for(size_t i = 0; i < m_size-1; i++){
      if(tempArray[i] > tempArray[i+1]){
        int temp = tempArray[i+1];
        tempArray[i+1] = tempArray[i];
        tempArray[i] = temp;
      }
    }
    it++;
  }
  it = 0;
  LinkedList<T> newLList(tempArray, m_size);
  return newLList;      
}

/**
* @brief Returns the last element of the stack
* 
*/ 
template <class T>
T Stack<T>::lastData(){
  if(!m_pRoot) {
    return;
  }
  return m_pRoot->m_data;
}


/**
* @brief Returns the value at a specified location in the Stack
* @param t_index is the position of the data in the stack.
*/ 
template<class T>
T Stack<T>::at(size_t t_index){
  if(t_index >= m_size) {
    throw std::out_of_range("Invalid Index. Code: uwu");
  }
  Node* tempData = new Node();
  tempData = m_pRoot;
  for(size_t i = 0; i < t_index; i++){
    tempData = tempData->m_pNext;
  }
  return tempData->m_data;
}

/**
*@brief Returns true if the queue is empty.
*/
template<class T>
bool Stack<T>::empty(){
  return !m_pRoot;
}
      
/**
*@brief Prints content of the queue in order from first to last.
* Returns "Stack is empty" when the stack is empty.
*/
template <class T>
void Stack<T>::printList(){
  if(!m_pRoot){
    throw std::length_error("stack is empty");
    return;
  }
  Node* temp = m_pRoot;
  while(temp){
    std::cout<<temp->m_data<<" ";
    temp = temp->m_pNext;
  }
  std::cout<<std::endl;
}


template<class T>
T Stack<T>::top(){
  if(!m_pRoot){
    throw std::length_error("stack is empty");
  }
  if(!m_pRoot->m_pNext){
    return m_pRoot->m_data;
  }
  return m_pLast->m_data;
}
// https://www.youtube.com/watch?v=xli_FI7CuzA   FOR BUBBLE SORT

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
size_t Stack<T>::size(){
  return m_size;
}