#include "mylib.hpp"
#include <iostream>

int main() {
  std::cout << "Helper command line tool." << std::endl;
  std::cout << "Uses mylib add(1, 1) = " << add(1, 1) << "." << std::endl;
  return 0;
}
