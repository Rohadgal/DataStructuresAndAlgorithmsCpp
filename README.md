# Data Structures in C++: LinkedList and Vector

Welcome to the Data Structures in C++ repository! This repository provides two fundamental data structures: a LinkedList and a Vector, both implemented in C++. These data structures can be used in various applications, and this README will guide you on how to utilize them effectively.

## LinkedList

A LinkedList is a dynamic data structure that allows you to store a collection of elements where each element (node) points to the next one. Here's what you can do with the LinkedList in this repository:

### Creating a LinkedList

You can create an empty LinkedList or initialize it with initial data using constructors:

```cpp
LinkedList<int> myList;                // Create an empty LinkedList
LinkedList<int> myListWithInitialData(5); // Create a LinkedList with initial data
```

### Adding Elements
* push_back(T t_data): Add an element to the end of the LinkedList.
* push_front(T t_data): Add an element to the beginning of the LinkedList.
* insert(T t_data, size_t t_index): Insert an element at a specific index.

### Removing Elements
* pop_front(): Remove the first element from the LinkedList.
* pop_back(): Remove the last element from the LinkedList.
* erase(size_t t_index): Remove an element at a specific index.
* eraseAll(T t_data): Remove all occurrences of a specific value from the LinkedList.
* clear(): Clear the entire LinkedList.
  
### Accessing Elements
* at(size_t t_index): Access an element at a specific index.
* size(): Get the current size of the LinkedList.
* empty(): Check if the LinkedList is empty.
* front(): Get the first element.
* back(): Get the last element.

### Printing the LinkedList
* printList(): Print all elements in the LinkedList.

## Vector
A Vector is a dynamic array that can grow or shrink in size as needed. It is implemented in this repository and offers the following functionalities:

Creating a Vector
You can create a Vector with or without an initial capacity:

```cpp
Vector<int> myVector;            // Create an empty Vector with initial capacity.
Vector<int> vectorWithCapacity(5); // Create a Vector with a specified initial capacity.
```

### Adding Elements
* push_back(T t_data): Add an element to the end of the Vector.
* Modifying Capacity
* reserve(size_t t_capacity): Change the capacity of the Vector.
* shrink_To_Fit(): Shrink the Vector's capacity to match its size.
* clear(): Clear the Vector and release memory.

### Accessing Elements
* at(size_t t_index): Access an element at a specific index.
* size(): Get the current size of the Vector.
* capacity(): Get the current capacity of the Vector.
* empty(): Check if the Vector is empty.
* front(): Get the first element.
* back(): Get the last element.
* data(): Get a pointer to the underlying data array.
* operator[](size_t t_index): Access an element using the subscript operator.

## Example Usage
Here's a quick example of how to use these data structures:

```cpp
// LinkedList
LinkedList<int> myList;
myList.push_back(42);
myList.push_front(10);
myList.insert(99, 1);
myList.printList();

// Vector
Vector<double> myVector;
myVector.push_back(3.14);
myVector.push_back(2.71);
double value = myVector.at(1);
```

Feel free to explore the code and use these data structures in your C++ projects. They can be valuable tools for managing dynamic data efficiently.

## Contributions
Contributions to this repository are welcome! If you have improvements, bug fixes, or additional features to add, please submit a pull request.

## License
This project is licensed under the MIT License.

Happy coding!
