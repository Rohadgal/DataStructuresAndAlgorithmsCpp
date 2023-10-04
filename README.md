# Data Structures in C++

This repository provides various data structures implemented in C++ to help you manage and manipulate data efficiently.

## Data Structures Included

### Vector

A dynamic array that can grow or shrink in size as needed. It is a versatile data structure commonly used for storing collections of elements.

### Linked List

A dynamic data structure where elements (nodes) are connected sequentially, with each node pointing to the next one. Linked lists are flexible for inserting and deleting elements.

### Double Linked List

Similar to a Linked List, but with each node pointing to both the next and previous nodes, allowing for bidirectional traversal.

### Circular Linked List

A Linked List where the last node points back to the first node, creating a circular structure. It is useful for applications that require continuous cycling through data.

### Double Circular Linked List

Combines the features of a Double Linked List and a Circular Linked List, allowing for bidirectional traversal in a circular manner.

### Queue

A linear data structure that follows the First-In-First-Out (FIFO) principle. Elements are added to the back (enqueue) and removed from the front (dequeue).

### Stack

A linear data structure that follows the Last-In-First-Out (LIFO) principle. Elements are added and removed from the same end, typically called the "top."

### Binary Tree

A hierarchical data structure where each node has, at most, two children: left and right. It is commonly used for efficient searching and sorting operations.

### Tree

A more general hierarchical data structure that can have multiple child nodes. Trees are used for various applications, including hierarchical data representation.

### Graph

A data structure that represents relationships between entities. Graphs consist of nodes (vertices) and edges connecting them. They are used for various network-related applications.

## Example Usage

Here's a quick example of how to use these data structures:

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

Happy coding!
