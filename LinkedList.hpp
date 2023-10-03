#pragma once
#include <iostream>
// nested class

/**
*  
*
*/
template <class T>
class LinkedList {
  private:
    // Constructors
    class Node{
      private:
        T m_data;
        Node* m_pNext;
      friend class LinkedList;
    };
    Node* m_pRoot;
    Node* m_pLast;
    // Accesors
    size_t m_size;
    // Modifiers
    Node* generateNode(T t_data);
  public:
    // Constructors
    LinkedList();
    LinkedList(T t_data);
    LinkedList(T t_array[], size_t t_arraySize);
    // Modifiers
    void push_back(T t_data);
    void push_front(T t_data);
    T pop_front();
    void pop_back();
    void insert(T t_data, size_t t_index);
    void erase(size_t t_index); 
    void eraseAll(T t_data); 
    void clear(); // Libera toda la memoria usada por la lista ligada.
    // Accesors
    T nodeData();
    bool empty();
    size_t rootData();
    Node* returnRoot();
    Node* returnLast();
    void printList();
    T at(size_t t_index);
    size_t size();
};

/**
*      
*
*/
template <class T>
LinkedList<T>::LinkedList(){
  m_pRoot = nullptr;
  m_pLast = nullptr;
  m_size = 0;
}

/**
*
*
*/
template <class T>
LinkedList<T>::LinkedList(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
*@brief Creates a Linked List class with the array given as parameter
*@param The array used to create the Linked List
*/
template <class T>
LinkedList<T>::LinkedList(T t_array[], size_t t_arraySize){
  //std::cout<<"this\n";
  //m_pRoot = generateNode(t_array[0]);
  m_pRoot = nullptr;
  m_size = 0;
  m_pLast = m_pRoot;
  //std::cout<<"arry: "<<m_pLast->m_data<<"\n";

  for(size_t i = 0; i < t_arraySize; i++){
    push_back(t_array[i]);
    //std::cout<<"size: "<<m_size<<"\n";
    //std::cout<<"arry: "<<m_pLast->m_data<<"\n";
    //m_size++;
  }
  Node* tempLast = m_pRoot;
  while(tempLast->m_pNext){
    tempLast = tempLast->m_pNext;
  }
  m_pLast = tempLast;
  m_pLast->m_pNext = nullptr;
}

/**
* @brief Generates new nodes 
*
*/
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data; 
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
* @brief Adds a node to the end of the list
* @param The node has the data given
*/
template <class T>
void LinkedList<T>::push_back(T t_data){
  if(!m_pRoot){
    //throw std::logic_error("UwUxecption");
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    m_size++;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast = m_pLast->m_pNext;
  m_size++;
}

/**
* @brief Add a node to the beggining of the list
* @param t_data is the new data added to the node
*/
template<class T>
void LinkedList<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    return;
  }
  Node* newNode = generateNode(t_data);
  newNode->m_pNext = m_pRoot;
  m_pRoot = newNode;
}
///////////////////////////////////
/**
* @brief Deletes the first node
* 
*/
template<class T>
T LinkedList<T>::pop_front(){
  // ELIMINAR UN PUNTERO
  if(!m_pRoot){
    throw std::length_error("List is empty");
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
}
/////////
/**
* @brief Pops out the last node
* 
*/
template<class T>
void LinkedList<T>::pop_back(){
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
  std::cout<<"mpRoot data: "<<m_pRoot->m_data<<std::endl;
  Node* pTemp = new Node();
  pTemp = m_pRoot;
  while (pTemp->m_pNext->m_pNext){
      pTemp = pTemp->m_pNext;
    std::cout<<"pTemp data: "<<pTemp->m_data<<std::endl;  
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
void LinkedList<T>::insert(T t_data, size_t t_index){ // Agrega un nodo con el t_data en el índice t_index.
  if(t_index > m_size){
    throw std::out_of_range("Invalid Index. Code: uwu");
     return; 
  } 
  //Node* previousPointer = new Node();
  Node* newNode = generateNode(t_data);
  if(t_index == 0){
    newNode->m_pNext = m_pRoot;
    m_pRoot = newNode;
  } else {
    Node* prevNode = m_pRoot;
    if(!m_pRoot->m_pNext){
      newNode->m_pNext = m_pRoot->m_pNext;
      m_pRoot->m_pNext = newNode;
    }
      // Find the node at t_index - 1
    for(size_t i = 0; i < t_index - 1; ++i){
      prevNode = prevNode->m_pNext;
    }
    // here ->next
    newNode->m_pNext = prevNode->m_pNext;
    prevNode->m_pNext = newNode;
  }
  m_size++;
}

/**
* @brief Deletes a node at the index given 
* @param Index for the node to delete
*/
template<class T>
void LinkedList<T>::erase(size_t t_index){
  if(t_index >= m_size||!m_pRoot){
    return;
  }
  if(t_index==0){
    // Erase the first node
    Node* temp = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    delete []temp;
  }else{
    // Find the node at t_index -1
    
    Node* prevNode = m_pRoot;
    for(size_t i=0; i<t_index-1; i++){
        prevNode = prevNode->m_pNext;
    }
    Node* nodeToDelete = prevNode->m_pNext;
    prevNode->m_pNext = nodeToDelete->m_pNext;
    delete []nodeToDelete;
  }
  --m_size;
}

/**
* @brief Deletes all the nodes with the same value as t_data
* @param All the nodes with the same data will be deleted
*/
template<class T>
void LinkedList<T>::eraseAll(T t_data){
  if(!m_pRoot){
    return;
  }

  while(m_pRoot && m_pRoot->m_data == t_data){
      Node* deleteNode = m_pRoot;
      m_pRoot = m_pRoot->m_pNext;
      delete [] deleteNode;
      m_size--;
  }
  
  Node* temp = m_pRoot;
  //Node* prevNode = new Node();
  while(temp && temp->m_pNext){
    if(temp->m_pNext->m_data == t_data){
      //std::cout<<"this\n";
      Node* deleteNode = temp->m_pNext;
      if(temp->m_pNext->m_pNext){
        temp->m_pNext = temp->m_pNext->m_pNext;
      }
      else{
        temp->m_pNext = nullptr; // ESTE PUNTERO TAMBIÉN DA PROBLEMAS!!!!!
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
void LinkedList<T>::clear(){
  if(!m_pRoot){
    return;
  }
  while(m_pRoot->m_pNext){
    Node* deleteNode = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    delete [] deleteNode;
  }
  m_pRoot = nullptr;
}

/**
*@brief Deletes all nodes all clear the memory
*
*/
template<class T>
T LinkedList<T>::nodeData(){
  return m_pRoot->m_data;
}
 
/**
* Returns true if the Linked List is empty
*/
template <class T>
bool LinkedList<T>::empty(){
  return !m_pRoot;
}

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
typename LinkedList<T>::Node*
LinkedList<T>::returnRoot(){
  return m_pRoot;
}

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
typename LinkedList<T>::Node*
LinkedList<T>::returnLast(){
  return m_pLast;
}

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
void LinkedList<T>::printList(){
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

/**
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
T LinkedList<T>::at(size_t t_index){
  if(!m_pRoot){
    return;
  }
  if(t_index >= m_size){
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
*@brief Prints all the data in the nodes in the linked list
*
*/
template <class T>
size_t LinkedList<T>::size(){
  return m_size;
}