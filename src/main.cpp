#include "gtestsample/sample.hpp"
#include <iostream>

int main(void)
{
  Sample sample;
  sample.set(5);
  std::cout << sample.get() << std::endl;
  return 0;
}

