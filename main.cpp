#include <iostream> 
#include "Interface.h"

int main() {                               
  try{                               
    beginInterface();     
  }                        
  catch(std::out_of_range e) {
    std::cout << e.what() << "\n ";
  }                            
}    