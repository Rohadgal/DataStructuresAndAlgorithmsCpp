#pragma once
#include <iostream>
// nested class

/**
*  
*
*/
template <class T>
class CircularDoubleLinkedList {
  private:
    // Constructors
    class Node{
      private:
        T m_data;
        Node* m_pNext;
        Node* m_pPrevNode;
      friend class CircularDoubleLinkedList;
    };
    Node* m_pRoot;
    Node* m_pLast;
    // Accesors
    size_t m_size;
    // Modifiers
    Node* generateNode(T t_data);
  public:
    // Constructors
    CircularDoubleLinkedList();    // ###
    CircularDoubleLinkedList(T t_data);  // ###
    CircularDoubleLinkedList(T t_array[], size_t t_arraySize);  // ###
    // Modifiers
    void push_back(T t_data);     // ###
    void push_front(T t_data);    // ###
    void pop_front();     // ###
    void pop_back();    // ###
    void insert(T t_data, size_t t_index); // ###
    void erase(size_t t_index);  // ###
    void eraseAll(T t_data);  // ###
    void clear(); // Libera toda la memoria usada por la lista ligada.   // ###
    // Accesors
    bool empty();    // ###
    void printList();     // ###
};

/**
*  @ brief Default Constructor, size = 0.
*
*/
template <class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList(){
  m_pRoot = nullptr;
  m_pLast = nullptr;
  m_size = 0;
}

/**
* @brief Constructor with one element.
* @param t_data is the data in the node.
*/
template <class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_pLast->m_pNext = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
  m_size = 1;
}

/**
*@brief Creates a Linked List class with the array given as parameter
*@param The array used to create the Linked List
*/
template <class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList(T t_array[], size_t t_arraySize){
  //m_pRoot = nullptr;
  //m_size = 0;
  //m_pLast = nullptr;

  for(size_t i = 0; i < t_arraySize; i++){
    push_back(t_array[i]);
  }
  //m_pLast->m_pNext = m_pRoot;
  //m_pRoot->m_pPrevNode = m_pLast;
}

/**
* @brief Generates new nodes 
*
*/
template <class T>
typename CircularDoubleLinkedList<T>::Node* CircularDoubleLinkedList<T>::generateNode(T t_data){
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
void CircularDoubleLinkedList<T>::push_back(T t_data){
  m_size++;
  if(!m_pRoot){
    //throw std::logic_error("UwUxecption");
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    m_pRoot->m_pPrevNode = m_pLast;
    m_pLast->m_pNext = m_pRoot;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast->m_pNext->m_pPrevNode = m_pLast;
  m_pLast = m_pLast->m_pNext;
  m_pLast->m_pNext = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
}

/**
* @brief Add a node to the beggining of the list
* @param t_data is the new data added to the node
*/
template<class T>
void CircularDoubleLinkedList<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pRoot->m_pNext = m_pRoot;
    m_pLast = m_pRoot;
    m_pRoot->m_pPrevNode = m_pLast;
    m_pLast->m_pNext = m_pRoot;
    return;
  }
  Node* newNode = generateNode(t_data);
  m_pRoot->m_pPrevNode = newNode;
  newNode->m_pNext = m_pRoot;
  m_pRoot = newNode;
  m_pLast->m_pNext = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
}
///////////////////////////////////
/**
* @brief Deletes the first node
* 
*/
template<class T>
void CircularDoubleLinkedList<T>::pop_front(){
  // ELIMINAR UN PUNTERO
  if(!m_pRoot){
    return;
  }
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  m_pRoot = m_pRoot->m_pNext;
  m_pRoot->m_pPrevNode = m_pLast;
  m_pLast->m_pNext = m_pRoot;
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
void CircularDoubleLinkedList<T>::pop_back(){
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
  Node* pTemp = m_pRoot;
  while (pTemp->m_pNext->m_pNext){
      pTemp = pTemp->m_pNext;
   // std::cout<<"pTemp data: "<<pTemp->m_data<<std::endl;  
  }
  //std::cout<<"this2\n";
  delete []pTemp->m_pNext;
  pTemp->m_pNext = nullptr; //este puntero causa muchos problemas !!!!!!!!!!!
  //std::cout<<"this3\n";
  m_pLast = pTemp;
  m_pLast->m_pNext = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
  //std::cout<<"this4\n";
  m_size--;
}

/**
* @brief Inserts a Node with the data given at the index passed through
* @parama The data to give to the node, and the index position
*/
template<class T>
void CircularDoubleLinkedList<T>::insert(T t_data, size_t t_index){ // Agrega un nodo con el t_data en el índice t_index.
  if(t_index > m_size){
    throw std::out_of_range("Invalid Index. Code: uwu");
     return; 
  } 
  Node* newNode = generateNode(t_data);
  //Node* previousPointer = new Node();
  if(t_index == 0){
    push_front(t_data);
    return;
  }
  if(!m_pRoot->m_pNext){
    push_back(t_data);
    return;
  }
  Node* tempNode = m_pRoot; 
  if(t_index > m_size/2){
   for(size_t i = 0; i < t_index - 1; ++i){
    tempNode = tempNode->m_pNext;
   }
  } else {
    tempNode = m_pLast;
    for(size_t i = m_size; i > t_index; i--){
    tempNode = tempNode->m_pPrevNode;
    }
  }
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
void CircularDoubleLinkedList<T>::erase(size_t t_index){
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
void CircularDoubleLinkedList<T>::eraseAll(T t_data){
  if(!m_pRoot){
    return;
  }

  while(m_pRoot && m_pRoot->m_data == t_data){
      pop_front();
      //m_pRoot = m_pRoot->m_pNext;
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
  m_pLast->m_pNext = m_pRoot;
  m_pRoot->m_pPrevNode = m_pLast;
}
  
/**
*@brief Deletes all nodes all clear the memory
*
*/
template<class T>
void CircularDoubleLinkedList<T>::clear(){
  if(!m_pRoot){
    return;
  }
  for(size_t i = 0; i < m_size; i++ ){
    pop_front();
  }
  m_pRoot = nullptr;
}


/**
* Returns true if the Linked List is empty
*/
template <class T>
bool CircularDoubleLinkedList<T>::empty(){
  return !m_pRoot;
}

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
void CircularDoubleLinkedList<T>::printList(){
Node* temp = new Node();
  temp = m_pRoot;
  //temp->m_pNext = m_pRoot->m_pNext;
  if(m_pRoot) {
    std::cout<<"The list contains: ";
    while(temp) {
      std::cout<<temp->m_data<<" ";
      temp = temp->m_pNext;
      if(temp == m_pRoot){
        break;
      }
    }
    std::cout<<std::endl;
    return;
  } 
  std::cout<<"The list is empty.\n";
  
}

// ```cpp
// ```