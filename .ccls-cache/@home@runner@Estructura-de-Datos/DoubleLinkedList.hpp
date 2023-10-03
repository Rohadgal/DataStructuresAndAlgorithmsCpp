#pragma once
#include <iostream>
#include <bits/stdc++.h>
// nested class

/**
*  
*
*/
template <class T>
class DoubleLinkedList {
  private:
    // Constructors
    class Node{
      private:
        T m_data;
        Node* m_pNext;
        Node* m_pPrevNode;
      friend class DoubleLinkedList;
    };
    Node* m_pRoot;
    Node* m_pLast;
    // Accesors
    size_t m_size;
    // Modifiers
    Node* generateNode(T t_data);
  public:
    // Constructors
    DoubleLinkedList();
    DoubleLinkedList(T t_data);
    DoubleLinkedList(T t_array[], size_t t_arraySize);
    // Modifiers
    void push_back(T t_data);
    void push_front(T t_data);
    void pop_front();
    void pop_back();
    void insert(T t_data, size_t t_index);
    void erase(size_t t_index); 
    void eraseAll(T t_data); 
    void clear(); // Libera toda la memoria usada por la lista ligada.
    void insertOrdered(T t_data);
    // Accesors
    size_t nodeData();
    bool empty();
    size_t rootData();
    Node* returnRoot();
    void printList();
};

/**
* @brief Default constructor, size = 0.  
*
*/
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  m_pRoot = nullptr;
  m_pLast = nullptr;
  m_size = 0;
}

/**
* @brief Constructor with one element.
* @param t_data is the data in the node.
*/
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
  m_pLast->m_pNext = m_pRoot;
  m_size = 1;
}

/**
*@brief Creates a Linked List class with the array given as parameter
*@param The array used to create the Linked List
*/
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(T t_array[], size_t t_arraySize){
  //m_pRoot = generateNode(t_array[0]);
  //m_pRoot = nullptr;
 // m_size = 0;
  //m_pLast = nullptr;

  for(size_t i = 0; i < t_arraySize; i++){
    push_back(t_array[i]);
  }
  //m_pLast->m_pNext = nullptr;
}

/**
* @brief Generates new nodes 
*
*/
template <class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data; 
  pNewNode->m_pNext = nullptr;
  pNewNode->m_pPrevNode = nullptr;
  return pNewNode;
}

/**
* @brief Adds a node to the end of the list
* @param The node has the data given
*/
template <class T>
void DoubleLinkedList<T>::push_back(T t_data){
  m_size++;
  if(!m_pRoot){
    //throw std::logic_error("UwUxecption");
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast->m_pNext->m_pPrevNode = m_pLast;
  m_pLast = m_pLast->m_pNext;
}

/**
* @brief Add a node to the beggining of the list
* @param t_data is the new data added to the node
*/
template<class T>
void DoubleLinkedList<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  Node* newNode = generateNode(t_data);
  m_pRoot->m_pPrevNode = newNode;
  newNode->m_pNext = m_pRoot;
  m_pRoot = newNode;
}
///////////////////////////////////
/**
* @brief Deletes the first node
* 
*/
template<class T>
void DoubleLinkedList<T>::pop_front(){
  // ELIMINAR UN PUNTERO
  if(!m_pRoot){
    return;
  }
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  m_pRoot = m_pRoot->m_pNext;
  m_pRoot->m_pPrevNode = nullptr;
  delete[] pTemp;
  pTemp = nullptr;
  m_size--;
}
/////////
/**
* @brief Pops out the last node
* 
*/
template<class T>
void DoubleLinkedList<T>::pop_back(){
  if(!m_pRoot){
    return;
  }
  if(!m_pRoot->m_pNext){
    //std::cout<<"this\n";
    delete[] m_pRoot;
    m_pRoot = nullptr;
    m_size = 0;
    return;
  }
  //std::cout<<"mpRoot data: "<<m_pRoot->m_data<<std::endl;
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  while (pTemp->m_pNext->m_pNext){
      pTemp = pTemp->m_pNext;
    //std::cout<<"pTemp data: "<<pTemp->m_data<<std::endl;  
  }
  //std::cout<<"this2\n";
  delete []pTemp->m_pNext;
  pTemp->m_pNext = nullptr; //este puntero causa muchos problemas !!!!!!!!!!!
  //std::cout<<"this3\n";
  m_pLast = pTemp;
  //std::cout<<"this4\n";
  m_size--;
}

/**
* @brief Inserts a Node with the data given at the index passed through
* @parama The data to give to the node, and the index position
*/
template<class T>
void DoubleLinkedList<T>::insert(T t_data, size_t t_index){ // Agrega un nodo con el t_data en el índice t_index.
  if(t_index > m_size){
    throw std::out_of_range("Invalid Index. Code: uwu");
     return; 
  } 
  //Node* previousPointer = new Node();
  Node* newNode = generateNode(t_data);
  if(t_index == 0){
    push_front(t_data);
    return;
  }
  if(!m_pRoot->m_pNext){
      push_back(t_data);
      return;
  }

  Node* tempNode = m_pRoot;
    
    if(t_index < m_size/2){
      for(size_t i = 0; i < t_index - 1; ++i){
        //prevNode = prevNode->m_pNext;
        tempNode = tempNode->m_pNext;
      }
    } else {
      tempNode = m_pLast;
      for(size_t i = m_size; i > t_index; i--){
        tempNode = tempNode->m_pPrevNode;
      }
    }
  m_size++;
  newNode->m_pNext = tempNode->m_pNext;
  newNode->m_pNext->m_pPrevNode = newNode;
  newNode->m_pPrevNode = tempNode;
  tempNode->m_pNext = newNode;
}

/**
* @brief Deletes a node at the index given 
* @param Index for the node to delete
*/
template<class T>
void DoubleLinkedList<T>::erase(size_t t_index){
  if(t_index >= m_size||!m_pRoot){
    return;
  }
  if(t_index==0){
    // Erase the first node
    pop_front();
    return;
  }else{
    // Find the node at t_index -1
    Node* prevNode = m_pRoot;
    for(size_t i=0; i<t_index-1; i++){
        prevNode = prevNode->m_pNext;
    }
    Node* nodeToDelete = prevNode->m_pNext;
    prevNode->m_pNext = nodeToDelete->m_pNext;
    nodeToDelete->m_pNext->m_pPrevNode = prevNode;
    delete []nodeToDelete;
  }
  --m_size;
}

/**
* @brief Deletes all the nodes with the same value as t_data
* @param All the nodes with the same data will be deleted
*/
template<class T>
void DoubleLinkedList<T>::eraseAll(T t_data){
  if(!m_pRoot){
    return;
  }

  while(m_pRoot && m_pRoot->m_data == t_data){
     /* Node* deleteNode = m_pRoot;
      m_pRoot = m_pRoot->m_pNext;
      delete [] deleteNode;
      m_size--;*/
      pop_front();
  }
  
  Node* temp = m_pRoot;
  //Node* prevNode = new Node();
  while(temp && temp->m_pNext){
    if(temp->m_pNext->m_data == t_data){
      //std::cout<<"this\n";
      Node* deleteNode = temp->m_pNext;
      deleteNode->m_pNext->m_pPrevNode = temp;
      if(temp->m_pNext->m_pNext){
        temp->m_pNext = temp->m_pNext->m_pNext;
      }
      else{
        temp->m_pNext = nullptr; // ESTE PUNTERO TAMBIÉN DA PROBLEMAS!!!!!
        //temp->m_pPrevNode = nullptr;
      }
      delete [] deleteNode;
      m_size--;
      
    } else {
      temp = temp->m_pNext;
    }
    //m_pLast = temp;
  }
  m_pLast = temp;
}
  
/**
*@brief Deletes all nodes all clear the memory
*
*/
template<class T>
void DoubleLinkedList<T>::clear(){
  if(!m_pRoot){
    return;
  }
  while(m_pRoot->m_pNext){
    pop_front();
    //Node* deleteNode = m_pRoot;
    //m_pRoot = m_pRoot->m_pNext;
    //delete [] deleteNode;
  }
  m_pRoot = nullptr;
}

/**
*@brief Deletes all nodes all clear the memory
*
*/
template<class T>
void DoubleLinkedList<T>::insertOrdered(T t_data){
  if(!m_pRoot){
    push_back(t_data);    
    return;
  }
  Node* pNewNode = generateNode(t_data);
  size_t leftSide = 0;
  size_t rightSide = m_size-1;
  Node* pTempMid = m_pRoot;
  Node* pPrevMid = nullptr;
  size_t counter = 0;

  while(leftSide <= rightSide){
    size_t middle = (leftSide + rightSide) / 2; //#### cambios
    while(counter < middle){
      pPrevMid = pTempMid;
      pTempMid = pTempMid->m_pNext;
      counter++;
    }
    //counter = 0;
    /*
    if(leftSide == rightSide){
      for(size_t i = 0; i < middle; i++){
        pPrevMid = pTempMid;
        pTempMid = pTempMid->m_pNext; 
      }
    }*/
            /*  

    if(counter == middle)
    {
      counter = 0;
      while(counter < middle){
      pPrevMid = pTempMid;
      pTempMid = pTempMid->m_pNext;
      counter++;
    }*/
    //counter = 0;
    if(pTempMid->m_data == t_data) {
      std::cout<<"El número ya existe en la lista\n";
      return; // en el caso de que el número ya existe, cómo tratarlo?
    } else if (pTempMid->m_data > t_data){
      rightSide = middle-1;
    } else {
      leftSide = middle+1;
    }
    
  }

  m_size++;
  
  if(pTempMid->m_data >= t_data){
    std::cout<<"here\n";
    pPrevMid->m_pNext = pNewNode;
    pNewNode->m_pNext = pTempMid;
    pNewNode->m_pPrevNode = pPrevMid;
    pTempMid->m_pPrevNode = pNewNode;
    return;
  }
  std::cout<<"hon\n";
  pNewNode->m_pNext = pTempMid->m_pNext;
  pTempMid->m_pNext->m_pPrevNode = pNewNode;
  pNewNode->m_pPrevNode = pTempMid;
  pTempMid->m_pNext = pNewNode;
}

/**
* Returns true if the Linked List is empty
*/
template <class T>
bool DoubleLinkedList<T>::empty(){
  return !m_pRoot;
}

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
void DoubleLinkedList<T>::printList(){
Node* temp = new Node();
  temp = m_pRoot;
  //temp->m_pNext = m_pRoot->m_pNext;
  if(m_pRoot) {
    std::cout<<"The list contains: ";
    while(temp) {
      std::cout<<temp->m_data<<" ";
      temp = temp->m_pNext;
    }
    std::cout<<std::endl;
    return;
  } 
  std::cout<<"The list is empty.\n";
  
}

// ```cpp
// ```


/*
Node* pCurrent = m_pRoot;
  Node* pPrev = nullptr;

  while (pCurrent && pCurrent->m_data < t_data){
    pPrev = pCurrent;
    pCurrent = pCurrent->m_pNext;
  }
  if(!pPrev){
    pNewNode->m_pNext = m_pRoot;
    m_pRoot->m_pPrevNode = pNewNode;
    m_pRoot = pNewNode;
  } else {
    pNewNode->m_pNext = pCurrent;
    pNewNode->m_pPrevNode = pPrev;
    if(pCurrent){
      pCurrent->m_pPrevNode = pNewNode;
    }
    pPrev->m_pNext = pNewNode;
  }
  m_size++;
*/