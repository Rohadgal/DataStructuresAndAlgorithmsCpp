#pragma once
#include <iostream>
#include <array>
using std::size_t;

/**
* @brief A template Data Structure that 
* handles a dynamic array 
*/
template<class T>
class Vector{
  private:
    T* m_data = nullptr;
    size_t m_size;
    size_t m_capacity;
 
    //Modifiers
    void resize();

  public:
    // Constructors
    Vector();
    Vector(size_t t_capacity);
    Vector(T t_array[], size_t t_capacity); // error en la dimensión del vector
    // Modifiers
    void push_back(T t_data);
    void shrink_To_Fit();
    void pop_Back(); 
    void reserve(size_t t_capacity);
    void clear();
    void recapacity();
    // Accesors
    size_t size();  // size_t puede cambiar su capacidad en bits y no tiene negativos
    size_t capacity();
    T at(size_t t_index);
    bool empty();
    T front();
    T back();
    //std::array<T, 5> data();
    T* data();

        // for returning an array as a pointer  
       //https://www.digitalocean.com/community/tutorials/return-array-in-c-plus-plus-function
};

/**
* @brief Resizes the array twice of it's current capacity
*/ 
template<class T>
void Vector<T>::resize(){
  reserve(m_capacity *=2);
}

/*template<class T>
void Vector<T>::recapacity(size_t t_capacity){
  T* dataTmp = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    dataTmp[i] = m_data[i];
  }
  m_capacity *= 2;
  m_data = new T[m_capacity];
  for(size_t i = 0; i < m_size; i++){
    m_data[i] = dataTmp[i];
  }
}*/

//en la clase tenemos un constructor vector y aquí lo voy a especificar

/**
* @brief Default constructor that creates
* a vector with capacity 2 and size = 0
*/ 
template<class T>
Vector<T>::Vector(){
  m_capacity = 2;
  m_size = 0;
  m_data = new T[m_capacity];
}

//en la clase tenemos un constructor vector y aquí lo voy a especificar
 // size_t se modifica solo si necesitamos un número de mayor tamaño que cambia de int a long

/**
* @brief Constructor that creates
* a vector with capacity 2 and size = 0
* @param t_capacity is the desired capacity of the new vector
*/ 
template<class T>
Vector<T>::Vector(size_t t_capacity){
  m_capacity = t_capacity;
  m_size = 0;
  m_data = new T[m_capacity];
}

/**
* @brief Constructor that creates
* a vector with copies of the array passed as a parameter
* @param t_array is the array used to create the vector with the given values
* @param t_capacity sets the capacity of the vector to match the array's parameter size
*/ 
template<class T>
Vector<T>::Vector(T t_array[], size_t t_capacity){;
  std::cout<<"\nConstructor created with an array as parameter.\n";
  m_capacity = t_capacity;
  m_size = m_capacity;
  m_data = new T[m_size];
  //m_data = t_array;
  for(int i = 0; i < m_size; i++){
    m_data[i] = t_array[i];
    std::cout<<"New vector pos " <<i <<": " <<m_data[i]<<"\t\n";
  }
  std::cout<<std::endl;
}

/**
* @brief Adds a new data at the end of the vector
* that means the next index after m_size value
* @tparam value of the new data
*/ 
template<class T>
void Vector<T>::push_back(T t_data){
  if(m_capacity == m_size){
    resize();
  }
  if(!m_data){
  }
  m_data[m_size] = t_data;
  m_size++;
}

/**
* @brief Shrinks the array's capacity to fit the size of the array
*/ 
template<class T>
void Vector<T>::shrink_To_Fit(){
  reserve(m_size);
}

/**
* @brief Pushes out the last value in the array
*/ 
template<class T>
void Vector<T>::pop_Back(){
  if(m_size == 0){
    return;
  }
  m_size--;
}

/**
* @brief Change the capacity of the vector with the value specified in the parameter
* @tparam value of the new capacity
*/ 
template<class T>
void Vector<T>::reserve(size_t t_capacity){
  if(t_capacity < m_size){
    throw std::range_error("Invalid Capacity Value. Code: uwu");
  }
  m_capacity = t_capacity;
  T* dataTemp = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    dataTemp[i] = m_data[i];
  }
  m_data = new T[m_capacity];
  for(size_t i = 0; i < m_size; i++){
    m_data[i] = dataTemp[i];
  }

  std::cout<<"\nThe vector's capacity has been updated to: "<<m_capacity<<std::endl;
}

/**
* @brief Clears the memory used by the vector
*/ 
template<class T>
void Vector<T>::clear(){
  if(!m_data){
    return;
  }
  delete[] m_data;
  m_data = nullptr;
  m_size = 0;
  m_capacity = 0;
  std::cout<<"\nMemory has been cleared for this vector\n";
}

/**
* @brief Returns a copy of m_size value
*/ 
template <class T>
size_t Vector<T>::size(){
  //std::cout << "size: " << m_size <<std::endl;
  return m_size;
}

/**
* @brief Returns a copy of m_capacity value
*/ 
template <class T>
size_t Vector<T>::capacity(){
  std::cout << "\ncapacity: " << m_capacity <<std::endl;
  return m_capacity;
}

/**
* @brief Returns the value at a specified location in the array
*/ 
template <class T>
T Vector<T>::at(size_t t_index){
  if(t_index >= m_size) {
    throw std::out_of_range("Invalid Index. Code: uwu");
  }
  return m_data[t_index];
}

/**
* @brief Returns true if the Vector is empty and false otherwise
*/ 
template <class T>
bool Vector<T>::empty(){
  if(m_size > 0){
    std::cout<< "\nVector is not empty\n";
    return false;
  }
  std::cout<< "\nVector is empty\n";
  return true;
}
 
/**
* @brief Returns the value at the beginning of the vector
*/ 
template <class T>
T Vector<T>::front(){
  if(!m_data){
  }
  std::cout<< "\nFirst vector value: " << m_data[0] << std::endl;
  return m_data[0];
}

/**
* @brief Returns the value at the end of the vector
*/ 
template <class T>
T Vector<T>::back(){
  if(!m_data){ 
  }
  std::cout<< "\nLast vector value: " << m_data[m_size-1] << std::endl;
  return m_data[m_size-1];
}

/**
* @brief Returns an array with a copy of all the values in the vector class
* The array's capacity is the size of the vector
*/ 
template <class T>
T* Vector<T>::data(){
  static T* array = new T[m_size];
  for(int i=0; i < m_size; i++){
    array[i] = m_data[i];
  } 
  return array;
}
