#pragma once
#include <iostream>
#include "Stack.hpp"
//#include <stack>
//#include <stack>
 
template <class T>
class BinaryTree{
  private:
    class Node{
      private:
      T m_data;
      Node* m_pLeft;  // El puntero como promesa
      Node* m_pRight;
      friend class BinaryTree;
    };
  Node* m_pRoot = nullptr;
  size_t m_size;
  // Modifiers
  Node* generateNode(T t_data);
  public:
  // Constructor
  BinaryTree();
  BinaryTree(T t_data);  
  BinaryTree(T t_arr[], size_t t_size);  
  // Modifiers
  void clear();
  void add(T t_data);
  void erase(T t_data);
  // Accesors
  bool empty();
  bool find(T t_data);
  //Node* insertLevelOrder(int arr[], int i, int n);
  //void inOrder(Node* t_root);
};

/**
*  @ brief Default Constructor, size = 0.
*
*/
template<class T>
BinaryTree<T>::BinaryTree(){
  m_pRoot = nullptr;
  m_size = 0;
  //std::cout<<"todo bien\n";
}

/**
*  @ brief Constructor
*  @ param t_data is passed to the constructor
*/
template<class T>
BinaryTree<T>::BinaryTree(T t_data){
  m_pRoot = generateNode(t_data);
  m_pRoot->m_m_pLeft = nullptr;
  m_pRoot->m_m_pRight = nullptr;

}

/**
*  @ brief Constructor that takes in an array
*  @ param t_arr gives the elements to the constructor
*/
template<class T>
BinaryTree<T>::BinaryTree(T t_arr[], size_t t_size){
  std::cout<<"todo bien\n";
  if(t_arr[t_size] == -1){
    throw std::invalid_argument("Invalid Array. Code: uwu");
    return;
  }
  
  m_pRoot = nullptr;
  for(size_t i = 0; i < t_size; i++){
    add(t_arr[i]);
  }

}

/**
* @brief Generates new nodes 
*
*/
template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data; 
  pNewNode->m_pLeft = nullptr;
  pNewNode->m_pRight = nullptr;
  m_size++;
  return pNewNode;
}

/**
*  @ brief Clears all the binary tree
*
*/
template <class T>
void BinaryTree<T>::clear(){
  if(!m_pRoot){
    return;
  }
  
  Stack<Node*> tempStack;
  tempStack.push_front(m_pRoot);

  while(!tempStack.empty()){ 
    Node* pTemp = tempStack.top();
    tempStack.pop_front();
  
    
    if(pTemp->m_pLeft){
      tempStack.push_front(pTemp->m_pLeft);
    }

    if(pTemp->m_pRight){
      tempStack.push_front(pTemp->m_pRight);
    }

    delete [] pTemp;
  }
  
  m_pRoot = nullptr;
  
  
  // without stack

  /*
  Node* pTemp = m_pRoot;
  Node* pPrevNode = nullptr;

  while(pTemp){
    pPrevNode = pTemp;
    
    if(pTemp->m_pLeft){
      pTemp = pTemp->m_pLeft;
      
      if(!pTemp->m_pRight->m_pLeft && !pTemp->m_pRight->m_pRight){
        delete pTemp->m_pRight;
        pTemp->m_pRight = nullptr;
        return;
      }
      
      if(!pTemp->m_pLeft->m_pLeft && !pTemp->m_pLeft->m_pRight){
        delete pTemp->m_pLeft;
        pTemp->m_pLeft = nullptr;
        return;
      }
      return;
    }
    
    if(pTemp->m_pRight){
      pTemp = pTemp->m_pRight;
        
      if(!pTemp->m_pRight->m_pLeft && !pTemp->m_pRight->m_pRight){
        delete pTemp->m_pRight;
        pTemp->m_pRight = nullptr;
        return;
      }
      
      if(!pTemp->m_pLeft->m_pLeft && !pTemp->m_pLeft->m_pRight){
        delete pTemp->m_pLeft;
        pTemp->m_pLeft = nullptr;
        return;
      }
    }

    if(!pPrevNode || pPrevNode == m_pRoot){
      delete m_pRoot;
      m_pRoot = nullptr;
    }

    if(pPrevNode->m_pLeft && pPrevNode->m_pRight){
      return;
    }

    delete pTemp;

    pTemp = pPrevNode;
  }*/

  
}

/**
* @brief add Nodes to the tree
* @param t_data is passed to the tree
*/
template <class T>
void BinaryTree<T>::add(T t_data){
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    return;
  }
  Node* pTemp = m_pRoot;
  while(pTemp){
    if(pTemp->m_data < t_data){
      if(!pTemp->m_pRight){
        pTemp->m_pRight = generateNode(t_data);
        return;
      } else {
        pTemp = pTemp->m_pRight;
      }
    } else {
      if(!pTemp->m_pLeft){
        pTemp->m_pLeft = generateNode(t_data);
        return;
      } else {
        pTemp = pTemp->m_pLeft;
      }
    }
  }
}

/**
* @brief erase an especific data 
* @param t_data is the value to delete from the tree
*/
template <class T>
void BinaryTree<T>::erase(T t_data){

  if(!m_pRoot){
    throw std::length_error("stack is empty");
    return;
  }

  Node* parent = nullptr;
    Node* current = m_pRoot;

    while (current) {
        if (t_data < current->m_data) {
            parent = current;
            current = current->m_pLeft;
        } else if (t_data > current->m_data) {
            parent = current;
            current = current->m_pRight;
        } else {
            // Encontraste el nodo que deseas eliminar.
            if (!current->m_pLeft) {
                // Caso 1: El nodo no tiene un hijo izquierdo.
                if (!parent) {
                    // El nodo a eliminar es la raíz.
                    m_pRoot = current->m_pRight;
                } else if (current == parent->m_pLeft) {
                    parent->m_pLeft = current->m_pRight;
                } else {
                    parent->m_pRight = current->m_pRight;
                }
                delete current;
                return;
            } else if (!current->m_pRight) {
                // Caso 2: El nodo no tiene un hijo derecho.
                if (!parent) {
                    // El nodo a eliminar es la raíz.
                    m_pRoot = current->m_pLeft;
                } else if (current == parent->m_pLeft) {
                    parent->m_pLeft = current->m_pLeft;
                } else {
                    parent->m_pRight = current->m_pLeft;
                }
                delete current;
                return;
            } else {
                // Caso 3: El nodo tiene dos hijos. Encuentra el sucesor inorden.
                Node* successorParent = current;
                Node* successor = current->m_pRight;
                while (successor->m_pLeft) {
                    successorParent = successor;
                    successor = successor->m_pLeft;
                }
                current->m_data = successor->m_data;
                current = successor;
                parent = successorParent;
            }
        }
    }

  //if(find(t_data));
/*
  Node* tempNode = m_pRoot;
  Node* deleteNode = nullptr;
  while (tempNode) {
     if (t_data == tempNode->m_data) {
       deleteNode = tempNode;
       tempNode = nullptr;
        return;  // Value found
      } else if (t_data < tempNode->m_data) {
        tempNode = tempNode->m_pLeft;
      } else {
        tempNode = tempNode->m_pRight;
      }
  }
  if(!deleteNode->m_pLeft && !deleteNode->m_pRight){
    m_pRoot = deleteNode->m_pLeft;
    }
    delete [] deleteNode;
    deleteNode = nullptr;
  }
      
  //throw std::invalid_argument("Element not in tree.");
 // return;  // Value not found

  /*
  Node* pTemp = m_pRoot; 
  
  while(pTemp){
    if(pTemp->m_data == t_data){
      return;
    }
    
    if(pTemp->m_data < t_data){
      if(!pTemp->m_pRight){
        throw std::invalid_argument("Element not in tree");
        return;
      } else {
        pTemp = pTemp->m_pRight;
        return;
      }
    } else {
      if(!pTemp->m_pLeft){
        throw std::invalid_argument("Element not in tree");
        return;
      } else {
        pTemp = pTemp->m_pLeft;
        return;
      }
    }
  }*/
  m_size--;
}

/**
* @brief Returns tree if empty
*
*/
template <class T>
bool BinaryTree<T>::empty(){
  return !m_pRoot;
}

/**
* @brief find a given data in the tree 
* @param t_data is the data to be found in the tree
*/
template <class T>
bool BinaryTree<T>::find(T t_data){
  Node* tempNode = m_pRoot;

    while (tempNode) {
      if (t_data == tempNode->m_data) {
        return true;  // Value found
      }
      if (t_data < tempNode->m_data) {
        tempNode = tempNode->m_pLeft;
      } else {
        tempNode = tempNode->m_pRight;
      }
    }
  return false;  // Value not found
}
