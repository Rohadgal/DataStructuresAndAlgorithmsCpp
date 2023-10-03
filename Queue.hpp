#pragma once
#include <iostream>
#include <array>
#include "LinkedList.hpp"


template <class T>
class Queue{
  private:
  // Constructors
  class Node{
    private:
      T m_data;
      Node* m_pNext;
    friend class Queue;
  };
  Node* m_pRoot;
  Node* m_pLast;
// Accesors
  size_t m_size;
// Modifiers
  Node* generateNode(T t_data);
  public:
// Constructors
  Queue();
  Queue(T t_data);
  Queue(T t_array[], size_t t_arraySize);
// Modifiers
  void enqueue(T t_data);
  T dequeue();
  void clear();
  void eraseAll(T t_data);
  LinkedList<T> sort();
  //void merge(int leftArray[], int rightArray[], int array[]);
// Accesors
  T firstElement();
  T at(size_t t_index);
  bool empty();
  void printList();
  size_t size();
};

/**
* @brief Default constructor that creates
* a Queue with nullptr in m_pRoot and m_pLast and m_size = 0;
*/
template<class T>
Queue<T>::Queue(){
  m_pRoot = nullptr;
  m_pLast = nullptr;
  m_size = 0;
}

/**
* @brief Constructor that creates
* a Queue with size = 1
* @param t_data is the value stored in the Queue
*/ 
template<class T>
Queue<T>::Queue(T t_data){
  m_pRoot = generateNode(t_data);
  m_pRoot->m_pNext = nullptr;
  m_pLast = m_pRoot;
  m_size = 1;
  
}

/**
* @brief Constructor that creates
* a Queue with copies of the array passed as a parameter
* @param t_array is the array used to create the queue with the given values
* @param t_capacity sets the capacity of the queue to match the array's parameter size
*/ 
template<class T>
Queue<T>::Queue(T t_array[], size_t t_arraySize){
  if(t_array[0] == NULL){
    for(size_t i = 0; i < t_arraySize; i++){
      enqueue(0);
    }
  }

  for(size_t i = 0; i < t_arraySize; i++){
    enqueue(t_array[i]); 
  }
  /*
  Node* tempLast = m_pRoot;
  while(tempLast->m_pNext){
    tempLast = tempLast->m_pNext;
  }
  m_pLast = tempLast;
  m_pLast->m_pNext = nullptr;
  Node* pTempLast = new Node();
  */
  
}

/**
* @brief Generates a Node for new data.
* @param t_data is used to give value to the data in the new Node.
*/
template <class T>
typename Queue<T>::Node* Queue<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
* @brief Inserts an element to the Queue.
* @param t_data pushes a value to the Queue.
*/
template <class T>
void Queue<T>::enqueue(T t_data){
    m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  //m_pLast->m_pNext->m_pNext = nullptr;
  m_pLast = m_pLast->m_pNext;
}

/**
* @brief Deletes the oldest element of the Queue.
*/
template <class T>
T Queue<T>::dequeue(){
  if(!m_pRoot){
    return;
  }
  Node* pTemp = new Node;
  pTemp = m_pRoot;
  m_pRoot = m_pRoot->m_pNext;
  T returnValue = pTemp->m_data;
  delete []pTemp;
  pTemp = nullptr;
  m_size--;
  return returnValue;
}

/**
* @brief Deletes all the queue.
*/
template<class T>
void Queue<T>::clear(){
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
* @brief Returns a LinkedList with the elements of the Queue sorted out
*/ 
template <class T>
LinkedList<T> Queue<T>::sort(){
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

 /* T prevData = tempArray[0];

  for(size_t i = 0; i < m_size; i++){
    if(tempArray[i] > tempArray[i+1] && i+1 < m_size){
      tempData = tempArray[i];
      tempArray[i] = tempArray[i+1];
      tempArray[i+1] = tempData;
    }
    if(i-1 >= 0 && tempArray[i-1] > tempArray[i]){
      tempData = tempArray[i-1];
      tempArray[i-1] = tempArray[i];
      tempArray[i] = tempData;
      }
    */

  /*
   size_t j = 0;
   for(size_t i = 0; i < m_size; i++){
     for( size_t j = 0; j < m_size; j++){
        if(tempArray[i] > tempArray[j]){
          tempData = tempArray[i];
          tempArray[i] = tempArray[j];
          tempArray[j] = tempData;
        }
     }*/
   

  //for(size_t i = 0; i < m_size; i++){
  //  std::cout<<"new array: "<<tempArray[i]<<std::endl;
  //}
  
  


 /**
* @brief 
*/ 

/*
template <class T> 
void Queue<T>::merge(int leftArray[], int rightArray[], int array[]){
   int leftSize = m_size / 2;
   int rightSize = m_size - leftSize;
   int i = 0, l = 0, r = 0;

  while(l < leftSize && r < rightSize) {
    if(leftArray[l] < rightArray[r]){
      array[i] = leftArray[l];
      i++;
      l++;
    }
    else{
      array[i] = rightArray[r];
      i++;
      r++;
    }
  }
  while (l < leftSize){
    array[i] = leftArray[l];
    i++;
    l++;
  }
  while(r < rightSize){
    array[i] = rightArray[r];
    i++;
    r++;
  }
    
}/*

/**
* @brief Returns the value of the first element to go out
* 
*/ 
template <class T>
T Queue<T>::firstElement(){
  if(!m_pRoot) {
    return;
  }
  return m_pRoot->m_data;
}

/**
* @brief Returns the value at a specified location in the array
* @param t_index returns the data in the queue that matches index position
*/ 
template <class T>
T Queue<T>::at(size_t t_index){
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
bool Queue<T>::empty(){
  return !m_pRoot;
}

/**
*@brief Prints content of the queue in order from first to last.
* Returns "Queue is empty" when the queue is empty.
*/
template <class T>
void Queue<T>::printList(){
  if(!m_pRoot){
    std::cout<<"Queue is empty\n";
    return;
  }
  Node* temp = new Node();
  temp = m_pRoot;
  while(temp){
    std::cout<<temp->m_data<<" ";
    temp = temp->m_pNext;
  }
  std::cout<<std::endl;
}

/**
*@brief Deletes all the data in the queue that matches the parameter.
@param t_data is the value that will be deleted anywhere in the queue.
*
*/
template<class T>
void Queue<T>::eraseAll(T t_data){
  if(!m_pRoot){
  return;
  }
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  Node* deleteNode = new Node();
  deleteNode = nullptr;

  while(m_pRoot->m_data == t_data){
    deleteNode = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    pTemp = m_pRoot;
    delete [] deleteNode;
    deleteNode = nullptr;
    m_size--;
  }
  
  while(pTemp->m_pNext){
    if(pTemp->m_pNext->m_data == t_data){
      deleteNode = pTemp->m_pNext;
      pTemp->m_pNext = (pTemp->m_pNext->m_pNext) // ternary operator
      ? pTemp->m_pNext = pTemp->m_pNext->m_pNext 
      : pTemp->m_pNext = nullptr;
      delete [] deleteNode;
      deleteNode = nullptr;
      m_size--;
    }
  }
  m_pLast = pTemp;
  m_pLast->m_pNext = nullptr;
  //delete [] pTemp; //Borrar este puntero borra la referencia al root
  pTemp = nullptr; // se puede hacer nulo el puntero por eliminar pero no se puede eliminar su contenido o se pierde la referencia de la lista. En este punto, hacer que sea nulo es mera medida de seguridad
}

/**
*@brief Prints content of the queue in order from first to last.
* Returns "Queue is empty" when the queue is empty.
*/
template <class T>
size_t Queue<T>::size(){
  return m_size;
}